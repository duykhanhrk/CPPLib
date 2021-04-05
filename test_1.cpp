#include "cslscr.h"
#include <stdio.h>

//
// Define
//

// Key code
#define ENTER 13
#define ESC 27
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

// Default values
#define DEFAULT_BACKGROUND BACKGROUND_BLACK
#define DEFAULT_FOREGROUND FOREGROUND_GRAY
#define DEFAULT_CHAR ' '
#define RESULT_FILE_NAME "./result.txt"

// Screen center
#define MIDLE_X(width) (WindowColumns() - (width)) / 2
#define MIDLE_Y(height) (WindowRows() - (height)) / 2

// Pillar display
#define PILLAR_COLOR BACKGROUND_GREY
#define PILLAR_DISC_SPACING_LIMIT 2
#define PILLAR_SPACE 4
#define PILLAR_GROUP_X MIDLE_X(6 * N + 9 + PILLAR_SPACE * 2)
#define PILLAR_GROUP_Y MIDLE_Y(N + 2)
#define PILLAR_A_POSITION_X PILLAR_GROUP_X
#define PILLAR_A_POSITION_Y PILLAR_GROUP_Y
#define PILLAR_B_POSITION_X PILLAR_GROUP_X + PILLAR_SPACE + 2 * N + 3
#define PILLAR_B_POSITION_Y PILLAR_GROUP_Y
#define PILLAR_C_POSITION_X PILLAR_GROUP_X + 2 * PILLAR_SPACE + 4 * N + 6
#define PILLAR_C_POSITION_Y PILLAR_GROUP_Y

// Pillar logics
#define PILLAR_HEAD_DISC(pillar) *(pillar->discs)
#define PILLAR_HEAD_INDEX(pillar) N - pillar->disc_count

// Disc
#define DISC_SHAPE_SIZE_FORMULA(size) 2 * (size) + 1
#define DISC_SHAPE_POSITION_X_FORMULA(disc) disc->pillar->position_x + disc->pillar->size + 1 - disc->size
#define DISC_SHAPE_POSITION_Y_FORMULA(disc) disc->pillar->position_y + disc->index

// Move disk
#define MOVE_DISC_VER_SPEED_UP if (MOVE_DISC_VER_SPEED > 0) MOVE_DISC_VER_SPEED -= 10
#define MOVE_DISC_HOR_SPEED_UP if (MOVE_DISC_HOR_SPEED > 0) MOVE_DISC_HOR_SPEED -= 10
#define MOVE_DISC_VER_SPEED_DOWN if (MOVE_DISC_VER_SPEED < 2000) MOVE_DISC_VER_SPEED += 10
#define MOVE_DISC_HOR_SPEED_DOWN if (MOVE_DISC_HOR_SPEED < 2000) MOVE_DISC_HOR_SPEED += 10

// Print control panel
#define PRINT_CONTROL_PANEL PrintWP("[SPACE] Pause  |  [LEFT] Jump down  |  [RIGHT] Jump up", MIDLE_X(54), WindowRows() - 2); \
                            PrintWP("[ENTER] New session  |  [ESC] Exit", MIDLE_X(34), WindowRows() - 1);

// Print step
#define PRINT_MOVE_STEP(pillar_a, pillar_b) GotoXY(MIDLE_X(6), WindowRows() - 4); \
                        printf("%c -> %c", pillar_a->name, pillar_b->name);

// Pause?
#define PAUSE_YN if (PAUSE) SessionControlPanel()

// Handles and triggers
#define PAUSE_HANDLE if (PAUSE) { \
                       PAUSE = 0; \
                       COMMAND = 0; \
			                 return; \
                     } \
		                 PAUSE = 1; \
		                 SessionControlPanel();

#define COMMAND_HANDLE if (COMMAND == 1) return; \
                       if (COMMAND == 2) return; \
                       if (COMMAND == 3) { \
                         PAUSE_HANDLE; \
											 }

#define MOVING_TRIGGER COMMAND_HANDLE; \
                       if (kbhit()) SessionControlPanel(); \
                       COMMAND_HANDLE;

//
// Prototype
//

typedef struct _Pillar Pillar;
typedef struct _Disc Disc;

void PrintPillar(Pillar *pillar);
void PrintDisc(Disc *disc);
void SessionControlPanel();
void MoveDiscOut(Pillar *pillar);
void MoveDiscIn(Disc *disc, Pillar *pillar);
void MoveDiscToRight(Disc *disc, int from_position_x, int to_position_x);
void MoveDiscToLeft(Disc *disc, int from_position_x, int to_position_x);
void MoveDisc(Pillar *from_pillar, Pillar *to_pillar);
void HaNoi(int n, Pillar *pillar_a, Pillar *pillar_b, Pillar *pillar_c);
void Session();
int MainControlPanel();

//
// Logics
//

typedef struct _Pillar {
	char name;
	int size;
	int color;
	int position_x;
	int position_y;
	Disc **discs;
	int disc_count;
} Pillar;

typedef struct _Disc {
	int index;
	int size;
	int color;
	Pillar *pillar;
} Disc;

// Config
int N = 0;                     // Min = 1 | Max = 24
int MOVE_DISC_VER_SPEED = 150; // Min = 0 | Max 2000
int MOVE_DISC_HOR_SPEED = 150; // Min = 0 | Max 2000
int DISC_VER_JUMP = 2;         // Min = 1 | Max = 24
int DISC_HOR_JUMP = 2;         // Min = 1 | Max = 24
int COMMAND = 2;               // 0: Normal | 1: Exit | 2: New session
bool PAUSE = 0;                // 0: Pause off | 1: Pause on
FILE *result_file;             // Result file

void PrintPillar(Pillar *pillar) {
	PrintVerLine(
	  DEFAULT_CHAR,
		pillar->size + 1,
		pillar->color,
		pillar->color,
		pillar->position_x + pillar->size + 1,
		pillar->position_y
	);

	PrintHorLine(
    DEFAULT_CHAR,
    DISC_SHAPE_SIZE_FORMULA(pillar->size + 1),
		pillar->color,
		pillar->color,
		pillar->position_x,
		pillar->position_y + pillar->size + 1
	);
}

void PrintDisc(Disc *disc) {
	PrintHorLine(
    DEFAULT_CHAR,
    DISC_SHAPE_SIZE_FORMULA(disc->size),
		disc->color,
		disc->color,
		DISC_SHAPE_POSITION_X_FORMULA(disc),
		DISC_SHAPE_POSITION_Y_FORMULA(disc)
	);
}

void PrintDisc(Disc *disc, int position_x) {
	PrintHorLine(
    DEFAULT_CHAR,
    DISC_SHAPE_SIZE_FORMULA(disc->size),
		disc->color,
		disc->color,
		position_x,
		DISC_SHAPE_POSITION_Y_FORMULA(disc)
	);
}

void SessionControlPanel() {
	int c = getch();

	if (c == ENTER) {
		// New session
		COMMAND = 2;
	} else if (c == ESC) {
		// Exit
		COMMAND = 1;
	} else if (c == 32) {
		// Pause
		PAUSE_HANDLE;
	} else if (c == 224) {
		// Move speed
		c = getch();

		if (c == KEY_LEFT) {
			MOVE_DISC_VER_SPEED_DOWN;
			MOVE_DISC_HOR_SPEED_DOWN;
		} else if (c == KEY_RIGHT) {
			MOVE_DISC_VER_SPEED_UP;
			MOVE_DISC_HOR_SPEED_UP;
		}

		PAUSE_YN;
	} else {
		PAUSE_YN;
	}
}

void MoveDiscOut(Pillar *pillar) {
	Disc *disc = PILLAR_HEAD_DISC(pillar);
	Disc _disc = *disc;
	_disc.color = DEFAULT_BACKGROUND;

	Disc __disc = *disc;
	__disc.size = 0;
	__disc.color = PILLAR_COLOR;

	while (disc->index > -(PILLAR_DISC_SPACING_LIMIT + 1)) {
		MOVING_TRIGGER;

		disc->index --;

		PrintDisc(&_disc);
		if (__disc.index >= 0) {
			PrintDisc(&__disc);
		}
		PrintDisc(disc);

		_disc.index --;
		__disc.index --;

		Sleep(MOVE_DISC_VER_SPEED);

		MOVING_TRIGGER;
	}

	// Drop head disc
	pillar->discs ++;
	pillar->disc_count --;
}

void MoveDiscIn(Disc *disc, Pillar *pillar) {
	Disc _disc = *disc;
	_disc.color = DEFAULT_BACKGROUND;

	Disc __disc = *disc;
	__disc.size = 0;
	__disc.color = PILLAR_COLOR;

	while (disc->index < PILLAR_HEAD_INDEX(pillar)) {
		MOVING_TRIGGER;

		disc->index ++;

		PrintDisc(&_disc);
		if (__disc.index >= 0) {
			PrintDisc(&__disc);
		}
		PrintDisc(disc);

		_disc.index ++;
		__disc.index ++;

		Sleep(MOVE_DISC_VER_SPEED);

		MOVING_TRIGGER;
	}

	// Add disc to head index
	pillar->discs --;
	*(pillar->discs) = disc;
	pillar->disc_count ++;
}

void MoveDiscToRight(Disc *disc, int from_position_x, int to_position_x) {
	Disc _disc = *disc;
	_disc.color = DEFAULT_BACKGROUND;

	while (from_position_x < to_position_x) {
		MOVING_TRIGGER;

		from_position_x += DISC_HOR_JUMP;
		from_position_x = from_position_x > to_position_x ? to_position_x : from_position_x;

		PrintDisc(&_disc, from_position_x - DISC_HOR_JUMP);
		PrintDisc(disc, from_position_x);

		Sleep(MOVE_DISC_HOR_SPEED);

		MOVING_TRIGGER;
	}
}

void MoveDiscToLeft(Disc *disc, int from_position_x, int to_position_x) {
	Disc _disc = *disc;
	_disc.color = DEFAULT_BACKGROUND;

	while(from_position_x > to_position_x) {
		MOVING_TRIGGER;

		from_position_x -= DISC_HOR_JUMP;
		from_position_x = from_position_x < to_position_x ? to_position_x : from_position_x;
		PrintDisc(&_disc, from_position_x + DISC_HOR_JUMP);
		PrintDisc(disc, from_position_x);

		Sleep(MOVE_DISC_HOR_SPEED);

		MOVING_TRIGGER;
	}
}

void MoveDisc(Pillar *from_pillar, Pillar *to_pillar) {
	Disc *disc = PILLAR_HEAD_DISC(from_pillar);

	COMMAND_HANDLE;

	// Print move step
	PRINT_MOVE_STEP(from_pillar, to_pillar);

	// Moves disc out of current pillar
	MoveDiscOut(from_pillar);

	COMMAND_HANDLE;

	// Move the disc horizontally
	int from_position_x = DISC_SHAPE_POSITION_X_FORMULA(disc);
	disc->pillar = to_pillar;
	int to_position_x = DISC_SHAPE_POSITION_X_FORMULA(disc);

	COMMAND_HANDLE;

	if (from_position_x < to_position_x) {
		MoveDiscToRight(disc, from_position_x, to_position_x);
	} else {
		MoveDiscToLeft(disc, from_position_x, to_position_x);
	}

	COMMAND_HANDLE;

	// Moves disc out of current pillar
	MoveDiscIn(disc, to_pillar);
}

void HaNoi(int n, Pillar *pillar_a, Pillar *pillar_b, Pillar *pillar_c) {
	if (n == 1) {
    MoveDisc(pillar_a, pillar_c);
		fprintf(result_file, "%c -> %c\n", pillar_a->name, pillar_b->name);
    COMMAND_HANDLE;
		return;
	}

	HaNoi(n - 1, pillar_a, pillar_c, pillar_b);
	COMMAND_HANDLE;
	HaNoi(1, pillar_a, pillar_b, pillar_c);
	COMMAND_HANDLE;
	HaNoi(n - 1, pillar_b, pillar_a, pillar_c);
}

void Session() {
	// Reset values
	COMMAND = 3;
	PAUSE = 0;

	// Set background, foreground and clear screen
SetColor(DEFAULT_FOREGROUND, DEFAULT_BACKGROUND);
	ClearScreen();

  do {
		// Get Input
		PrintWP("Nhap so N: ", MIDLE_X(12), MIDLE_Y(1));
		Input(N);

		// Clear screen
		ClearScreen();
	} while (N < 1 || N > 24);


	// Initialize
	// Discs
	Disc **discs_a = new Disc*[N + 1];
	Disc **discs_b = new Disc*[N + 1];
	Disc **discs_c = new Disc*[N + 1];

	// Pillar
	Pillar pillar_a = { 'A', N, PILLAR_COLOR, PILLAR_A_POSITION_X, PILLAR_A_POSITION_Y, discs_a, N };
	Pillar pillar_b = { 'B', N, PILLAR_COLOR, PILLAR_B_POSITION_X, PILLAR_B_POSITION_Y, discs_b + N + 1, 0 };
	Pillar pillar_c = { 'C', N, PILLAR_COLOR, PILLAR_C_POSITION_X, PILLAR_C_POSITION_Y, discs_c + N + 1, 0 };

	// Print three pillars
	PrintPillar(&pillar_a);
	PrintPillar(&pillar_b);
	PrintPillar(&pillar_c);

	// Discs
	Disc *discs = new Disc[N];
	for (int i = 0; i < N; i ++) {
		(discs + i)->index = i + 1;
		(discs + i)->size = i + 1;
		(discs + i)->color = 16 * (i % 9 + 1);
		(discs + i)->pillar = &pillar_a;

		*(pillar_a.discs + i) = (discs + i);
		PrintDisc(discs + i);
	}

	PRINT_CONTROL_PANEL;

	// Open result file
	result_file = fopen(RESULT_FILE_NAME, "w+");

	// Act
	HaNoi(N, &pillar_a, &pillar_b, &pillar_c);

	// Close result file
	fclose(result_file);

	// Clear
	delete [] discs;
	delete [] discs_a;
	delete [] discs_b;
	delete [] discs_c;

	GotoXY(WindowColumns() - 1,  WindowRows() - 1);
}

int MainControlPanel() {
	if (COMMAND == 1) {
		return 1;
	}

	if (COMMAND == 2) {
		Session();
		return 0;
	}

	int c = getch();

	if (c == ENTER) {
		// New session
		COMMAND = 2;
	} else if (c == ESC) {
		// Exit
		return 1;
	} else if (c == 224) {
		// Move speed
		c = getch();

		if (c == KEY_LEFT) {
			MOVE_DISC_VER_SPEED_DOWN;
			MOVE_DISC_HOR_SPEED_DOWN;
		} else if (c == KEY_RIGHT) {
			MOVE_DISC_VER_SPEED_UP;
			MOVE_DISC_HOR_SPEED_UP;
		}
	}

	return 0;
}

//
// Main
//

int main() {
	while (MainControlPanel() != 1);

	ClearScreen();

	return 0;
}

