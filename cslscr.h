#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

//
// Define
//

#ifdef WIN32
// Define for Windows platform
#define CLEAR_SCREEN_COMMAND "cls"
#else
// Define for Linux platform
#define CLEAR_SCREEN_COMMAND "clear"
#endif

// Color
// Foreground
#define FOREGROUND_BLACK 0x0
#define FOREGROUND_BLUE 0x1
#define FOREGROUND_GREEN 0x2
#define FOREGROUND_TUFTS 0x3
#define FOREGROUND_RED 0x4
#define FOREGROUND_MAGENTA 0x5
#define FOREGROUND_YELLOW 0x6
#define FOREGROUND_GRAY 0x7
#define FOREGROUND_GREY 0x8
#define FOREGROUND_ROYAL 0x9
// Background
#define BACKGROUND_BLACK 0x0
#define BACKGROUND_BLUE 0x10
#define BACKGROUND_GREEN 0x20
#define BACKGROUND_TUFTS 0x30
#define BACKGROUND_RED 0x40
#define BACKGROUND_MAGENTA 0x50
#define BACKGROUND_YELLOW 0x60
#define BACKGROUND_GRAY 0x70
#define BACKGROUND_GREY 0x80
#define BACKGROUND_ROYAL 0x90

//
// Prototype
//
void ClearScreen();
void ClearScreen(int b_color);
void GotoXY(int x, int y);

void SetColor(int f_color, int b_color);
void SetForeground(int f_color);
void SetBackground(int b_color);

void Print(char obj);
void Print(const char *obj);
void Print(int obj);
void Print(double obj);

void Print(char obj, int f_color, int b_color, int x, int y);
void Print(const char *obj, int f_color, int b_color, int x, int y);
void Print(int obj, int f_color, int b_color, int x, int y);
void Print(double obj, int f_color, int b_color, int x, int y);

void PrintWC(char obj, int f_color, int b_color);
void PrintWC(const char *obj, int f_color, int b_color);
void PrintWC(int obj, int f_color, int b_color);
void PrintWC(int obj, int f_color, int b_color);

void PrintWP(char obj, int x, int y);
void PrintWP(const char *obj, int x, int y);
void PrintWP(int obj, int x, int y);
void PrintWP(double obj, int x, int y);

void PrintVerLine(char chr, int height);
void PrintVerLine(char chr, int height, int f_color, int b_color, int x, int y);
void PrintVerLineWC(char chr, int height, int f_color, int b_color);
void PrintVerLineWP(char chr, int height, int x, int y);

void PrintHorLine(char chr, int width);
void PrintHorLine(char chr, int width, int f_color, int b_color, int x, int y);
void PrintHorLineWC(char chr, int width, int f_color, int b_color);
void PrintHorLineWP(char chr, int width, int x, int y);

void PrintRec(char chr, int width, int height);
void PrintRec(char chr, int width, int height, int f_color, int b_color, int x, int y);
void PrintRecWC(char chr, int width, int height, int f_color, int b_color);
void PrintRecWP(char chr, int width, int height, int x, int y);

void PrintRecShape(char chr, int width, int height);
void PrintRecShapeWP(char chr, int width, int height, int x, int y);
void PrintRecShapeWC(char chr, int width, int height, int f_color, int b_color);
void PrintRecShape(char chr, int width, int height, int f_color, int b_color, int x, int y);

//
// Config
//

int CURRENT_BACKGROUND = BACKGROUND_BLACK;
int CURRENT_FOREGROUND = FOREGROUND_GRAY;

// Clear screen
void ClearScreen() {
	system(CLEAR_SCREEN_COMMAND);
}

// Clear screen with background color
void ClearScreen(int b_color) {
	SetBackground(b_color);
	system(CLEAR_SCREEN_COMMAND);
}

// Goto x, y
void GotoXY(int x, int y) {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursor_position;
	
	cursor_position.X = x;
	cursor_position.Y = y;
	SetConsoleCursorPosition(console, cursor_position);
}

// Get cursor position x
int CursorPositionX() {
	CONSOLE_SCREEN_BUFFER_INFO console_screen_buffer_info;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &console_screen_buffer_info);
	
	return console_screen_buffer_info.dwCursorPosition.X;
}

// Get cursor position y
int CursorPositionY() {
	CONSOLE_SCREEN_BUFFER_INFO console_screen_buffer_info;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &console_screen_buffer_info);
	
	return console_screen_buffer_info.dwCursorPosition.Y;
}

int WindowRows() {
	CONSOLE_SCREEN_BUFFER_INFO console_screen_buffer_info;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &console_screen_buffer_info);
	
  return console_screen_buffer_info.srWindow.Bottom - console_screen_buffer_info.srWindow.Top + 1;
}

int WindowColumns() {
	CONSOLE_SCREEN_BUFFER_INFO console_screen_buffer_info;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &console_screen_buffer_info);
	
  return console_screen_buffer_info.srWindow.Right - console_screen_buffer_info.srWindow.Left + 1;
}

// Set foreground
void SetForeground(int f_color) {
	CURRENT_FOREGROUND = f_color;
	
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, CURRENT_FOREGROUND | CURRENT_BACKGROUND);
}

// Set background
void SetBackground(int b_color) {
	CURRENT_BACKGROUND = b_color;
	
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, CURRENT_FOREGROUND | CURRENT_BACKGROUND);
}

// Set color
void SetColor(int f_color, int b_color) {
	CURRENT_BACKGROUND = b_color;
	CURRENT_FOREGROUND = f_color;
	
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, CURRENT_FOREGROUND | CURRENT_BACKGROUND);
}

// Input
void Input(int &obj) {
	scanf("%d", &obj);
}

// Print
void Print(char obj) {
	printf("%c", obj);
}

void Print(const char *obj) {
	printf("%s", obj);
}

void Print(int obj) {
	printf("%d", obj);
}

void Print(double obj) {
	printf("%lf", obj);
}

// Print with colors and postition (x, y)
void Print(char obj, int f_color, int b_color, int x, int y) {
	int current_foreground = CURRENT_FOREGROUND;
	int current_background = CURRENT_BACKGROUND;
	
	SetColor(f_color, b_color);
	GotoXY(x, y);
	printf("%c", obj);
	SetColor(current_foreground, current_background);
}

void Print(const char *obj, int f_color, int b_color, int x, int y) {
	int current_foreground = CURRENT_FOREGROUND;
	int current_background = CURRENT_BACKGROUND;
	
	SetColor(f_color, b_color);
	GotoXY(x, y);
	printf("%s", obj);
	SetColor(current_foreground, current_background);
}

void Print(int obj, int f_color, int b_color, int x, int y) {
	int current_foreground = CURRENT_FOREGROUND;
	int current_background = CURRENT_BACKGROUND;
	
	SetColor(f_color, b_color);
	GotoXY(x, y);
	printf("%d", obj);
	SetColor(current_foreground, current_background);
}

void Print(double obj, int f_color, int b_color, int x, int y) {
	int current_foreground = CURRENT_FOREGROUND;
	int current_background = CURRENT_BACKGROUND;
	
	SetColor(f_color, b_color);
	GotoXY(x, y);
	printf("%lf", obj);
	SetColor(current_foreground, current_background);
}

// Print text with colors
void PrintWC(char obj, int f_color, int b_color) {
	int current_foreground = CURRENT_FOREGROUND;
	int current_background = CURRENT_BACKGROUND;
	
	SetColor(f_color, b_color);
	printf("%c", obj);
	SetColor(current_foreground, current_background);
}

void PrintWC(const char *obj, int f_color, int b_color) {
	int current_foreground = CURRENT_FOREGROUND;
	int current_background = CURRENT_BACKGROUND;
	
	SetColor(f_color, b_color);
	printf("%s", obj);
	SetColor(current_foreground, current_background);
}

void PrintWC(int obj, int f_color, int b_color) {
	int current_foreground = CURRENT_FOREGROUND;
	int current_background = CURRENT_BACKGROUND;
	
	SetColor(f_color, b_color);
	printf("%d", obj);
	SetColor(current_foreground, current_background);
}

void PrintWC(double obj, int f_color, int b_color) {
	int current_foreground = CURRENT_FOREGROUND;
	int current_background = CURRENT_BACKGROUND;
	
	SetColor(f_color, b_color);
	printf("%lf", obj);
	SetColor(current_foreground, current_background);
}

// Print text with postion (x, y)
void PrintWP(char obj, int x, int y) {
	GotoXY(x, y);
	printf("%c", obj);
}

void PrintWP(const char *obj, int x, int y) {
	GotoXY(x, y);
	printf("%s", obj);
}

void PrintWP(int obj, int x, int y) {
	GotoXY(x, y);
	printf("%d", obj);
}

void PrintWP(double obj, int x, int y) {
	GotoXY(x, y);
	printf("%lf", obj);
}

// Print a line
void PrintVerLine(char chr, int height) {
	int x = CursorPositionX();
	int y = CursorPositionY();
	
	for (int i = 0; i < height; i ++) {
		GotoXY(x, y + i);
		printf("%c\n", chr);
	}
}

void PrintVerLine(char chr, int height, int f_color, int b_color, int x, int y) {
	int current_foreground = CURRENT_FOREGROUND;
	int current_background = CURRENT_BACKGROUND;
	
	SetColor(f_color, b_color);
	GotoXY(x, y);
	
	for (int i = 0; i < height; i ++) {
		GotoXY(x, y + i);
		printf("%c\n", chr);
	}
	
	SetColor(current_foreground, current_background);
}

void PrintVerLineWC(char chr, int height, int f_color, int b_color) {
	int current_foreground = CURRENT_FOREGROUND;
	int current_background = CURRENT_BACKGROUND;
	
	SetColor(f_color, b_color);
	
	PrintVerLine(chr, height);
	
	SetColor(current_foreground, current_background);
}

void PrintVerLineWP(char chr, int height, int x, int y) {
	GotoXY(x, y);
	PrintVerLine(chr, height);
}

void PrintHorLine(char chr, int width) {
	char *line = new char[width + 1];
	
	for (int i = 0; i < width; i ++) {
		line[i] = chr;
	}
	line[width] = '\0';
	
	printf("%s", line);
	
	delete [] line;
}

void PrintHorLine(char chr, int width, int f_color, int b_color, int x, int y) {
	char *line = new char[width + 1];
	
	for (int i = 0; i < width; i ++) {
		line[i] = chr;
	}
	line[width] = '\0';
	
	int current_foreground = CURRENT_FOREGROUND;
	int current_background = CURRENT_BACKGROUND;
	
	SetColor(f_color, b_color);
	GotoXY(x, y);
	
	printf("%s", line);
	delete [] line;
	
	SetColor(current_foreground, current_background);
}

void PrintHorLineWC(char chr, int width, int f_color, int b_color) {
	int current_foreground = CURRENT_FOREGROUND;
	int current_background = CURRENT_BACKGROUND;
	
	SetColor(f_color, b_color);
	
	PrintHorLine(chr, width);
	
	SetColor(current_foreground, current_background);
}

void PrintHorLineWP(char chr, int width, int x, int y) {
	GotoXY(x, y);
	PrintHorLine(chr, width);
}

// Print a rectangle

void PrintRec(char chr, int width, int height) {
	int x = CursorPositionX();
	int y = CursorPositionY();
	
	char *line = new char[width + 1];
	
	for (int i = 0; i < width; i ++) {
		line[i] = chr;
	}
	line[width] = '\0';
	
	printf("%s", line);
	GotoXY(x, y + height - 1);
	printf("%s", line);
	delete [] line;
	
	for (int i = 1; i < height - 1; i ++) {
		GotoXY(x, y + i);
		printf("%c", chr);
		
		GotoXY(x + width - 1, y + i);
		printf("%c", chr);
	}
	
	GotoXY(x, y + height);
}

void PrintRec(char chr, int width, int height, int f_color, int b_color, int x, int y) {
	int current_foreground = CURRENT_FOREGROUND;
	int current_background = CURRENT_BACKGROUND;
	
	SetColor(f_color, b_color);
	GotoXY(x, y);
	
	char *line = new char[width + 1];
	
	for (int i = 0; i < width; i ++) {
		line[i] = chr;
	}
	line[width] = '\0';
	
	printf("%s", line);
	GotoXY(x, y + height - 1);
	printf("%s", line);
	delete [] line;
	
	for (int i = 1; i < height - 1; i ++) {
		GotoXY(x, y + i);
		printf("%c", chr);
		
		GotoXY(x + width - 1, y + i);
		printf("%c", chr);
	}
	
	GotoXY(x, y + height);
	SetColor(current_foreground, current_background);
}

void PrintRecWC(char chr, int width, int height, int f_color, int b_color) {
	int current_foreground = CURRENT_FOREGROUND;
	int current_background = CURRENT_BACKGROUND;
	
	SetColor(f_color, b_color);
	
	PrintRec(chr, width, height);
	
	SetColor(current_foreground, current_background);
}

void PrintRecWP(char chr, int width, int height, int x, int y) {
	GotoXY(x, y);
	
	char *line = new char[width + 1];
	
	for (int i = 0; i < width; i ++) {
		line[i] = chr;
	}
	line[width] = '\0';
	
	printf("%s", line);
	GotoXY(x, y + height - 1);
	printf("%s", line);
	delete [] line;
	
	for (int i = 1; i < height - 1; i ++) {
		GotoXY(x, y + i);
		printf("%c", chr);
		
		GotoXY(x + width - 1, y + i);
		printf("%c", chr);
	}
	
	GotoXY(x, y + height);
}

// Print rectangle shape

void PrintRecShape(char chr, int width, int height) {
	char *line = new char[width + 1];
	
	for (int i = 0; i < width; i ++) {
		line[i] = chr;
	}
	line[width] = '\0';
	
	for (int i = 0; i < height - 1; i ++) {
		printf("%s\n", line);
	}
	
	delete [] line;
}

void PrintRecShape(char chr, int width, int height, int f_color, int b_color, int x, int y) {
	int current_foreground = CURRENT_FOREGROUND;
	int current_background = CURRENT_BACKGROUND;
	
	SetColor(f_color, b_color);
	
	GotoXY(x, y);
	
	char *line = new char[width + 1];
	
	for (int i = 0; i < width; i ++) {
		line[i] = chr;
	}
	line[width] = '\0';
	
	for (int i = 0; i < height - 1; i ++) {
		printf("%s\n", line);
	}
	
	delete [] line;
	
	SetColor(current_foreground, current_background);
}

void PrintRecShapeWC(char chr, int width, int height, int f_color, int b_color) {
	int current_foreground = CURRENT_FOREGROUND;
	int current_background = CURRENT_BACKGROUND;
	
	SetColor(f_color, b_color);
	
	PrintRecShape(chr, width, height);
	
	SetColor(current_foreground, current_background);
}

void PrintRecShapeWP(char chr, int width, int height, int x, int y) {
	GotoXY(x, y);
	
	PrintRecShape(chr, width, height);
}
