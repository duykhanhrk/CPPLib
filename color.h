/* Colors */

/* Include */

#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

/* Define */

// Foreground
#define FOREGROUND_BLACK 0x0
#define FOREGROUND_BLUE 0x1
#define FOREGROUND_GREEN 0x2
#define FOREGROUND_AQUA 0x3
#define FOREGROUND_RED 0x4
#define FOREGROUND_PURPLE 0x5
#define FOREGROUND_YELLOW 0x6
#define FOREGROUND_WHITE 0x7
#define FOREGROUND_GRAY 0x8
#define FOREGROUND_LIGHT_BLUE 0x9
#define FOREGROUND_LIGHT_GREEN 0xA
#define FOREGROUND_LIGHT_AQUA 0xB
#define FOREGROUND_LIGHT_RED 0xC
#define FOREGROUND_LIGHT_PURPLE 0xD
#define FOREGROUND_LIGHT_YELLOW 0xE
#define FOREGROUND_BRIGHT_WHITE 0xF

// Background
#define BACKGROUND_BLACK 0x0
#define BACKGROUND_BLUE 0x10
#define BACKGROUND_GREEN 0x20
#define BACKGROUND_AQUA 0x30
#define BACKGROUND_RED 0x40
#define BACKGROUND_PURPLE 0x50
#define BACKGROUND_YELLOW 0x60
#define BACKGROUND_WHITE 0x70
#define BACKGROUND_GRAY 0x80
#define BACKGROUND_LIGHT_BLUE 0x90
#define BACKGROUND_LIGHT_GREEN 0xA0
#define BACKGROUND_LIGHT_AQUA 0xB0
#define BACKGROUND_LIGHT_RED 0xC0
#define BACKGROUND_LIGHT_PURPLE 0xD0
#define BACKGROUND_LIGHT_YELLOW 0xE0
#define BACKGROUND_BRIGHT_WHITE 0xF0

// Date type
#define color_tp int

// Commands
#define CLEAR_SCREEN_COMMAND "cls"

/* Prototype */

void ClearScreen();
void ClearScreen(int b_color);

void SetColor(int f_color, int b_color);
void SetForeground(int f_color);
void SetBackground(int b_color);

/* Config */

int CURRENT_BACKGROUND = BACKGROUND_BLACK;
int CURRENT_FOREGROUND = FOREGROUND_WHITE;

/* Logic */

// Clear screen
void ClearScreen() {
	system(CLEAR_SCREEN_COMMAND);
}

// Clear screen with background color
void ClearScreen(int b_color) {
	SetBackground(b_color);
	system(CLEAR_SCREEN_COMMAND);
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
