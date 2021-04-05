/* Console Screen */

//
// Include
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <iostream>

//
// Define
//

// Debug
#define show(obj) std::cout << obj << std::endl

// Commands
#define CLEAR_SCREEN_COMMAND "cls"

// Keys
#define ENTER 13
#define ESC 27
#define BACKSPACE 8
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

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

// Control
void ClearScreen();
void ClearScreen(int b_color);

void SetColor(int f_color, int b_color);
void SetForeground(int f_color);
void SetBackground(int b_color);

void GotoXY(int x, int y);
int CursorPositionX();
int CursorPositionY();
int WindowRows();
int WindowColumns();

// Input
char UIntInput(unsigned int &obj, const char * label = "\0", unsigned int max = 4294967295u)
char ULongInput(unsigned long long int &obj, const char * label = "\0", unsigned long long int max = 18446744073709551615u)

//
// Config
//

int CURRENT_BACKGROUND = BACKGROUND_BLACK;
int CURRENT_FOREGROUND = FOREGROUND_GRAY;

//
// Logic
//

// Control
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

// Get window rows
int WindowRows() {
	CONSOLE_SCREEN_BUFFER_INFO console_screen_buffer_info;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &console_screen_buffer_info);

  return console_screen_buffer_info.srWindow.Bottom - console_screen_buffer_info.srWindow.Top + 1;
}

// Get window columns
int WindowColumns() {
	CONSOLE_SCREEN_BUFFER_INFO console_screen_buffer_info;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &console_screen_buffer_info);

  return console_screen_buffer_info.srWindow.Right - console_screen_buffer_info.srWindow.Left + 1;
}

// Input
// Get a positive number
char Input(unsigned int &obj, const char * label = "\0", unsigned int max = 4294967295u) {
  unsigned int n = obj;
  char c = '\0';

  printf("%s%u", label, n);
  if (n == 0) printf("%c", BACKSPACE);

  while (c != ENTER && c != ESC && c != KEY_UP && c != KEY_DOWN) {
    if (n == 0) printf("0%c", BACKSPACE);

    c = getch();

    if (c >= 48 && c <= 57) {
      if (max - n < max - max/10) continue;
      else if (max - n == max - max/10 && c - 48 > max%10) continue;

      n = n * 10 + (c - 48);
      if (n == 0) continue;
      printf("%c", c);
    } else if (c == BACKSPACE) {
      if (n != 0) printf("%c %c", BACKSPACE, BACKSPACE);
      n /= 10;
    }
  }

  obj = n;

  return c;
}

char Input(unsigned long long int &obj, const char * label = "\0", unsigned long long int max = 18446744073709551615u) {
  unsigned long long int n = obj;
  char c = '\0';

  printf("%s%u", label, n);
  if (n == 0) printf("%c", BACKSPACE);

  while (c != ENTER && c != ESC && c != KEY_UP && c != KEY_DOWN) {
    if (n == 0) printf("0%c", BACKSPACE);

    c = getch();

    if (c >= 48 && c <= 57) {
      if (max - n < max - max/10) continue;
      else if (max - n == max - max/10 && c - 48 > max%10) continue;

      n = n * 10 + (c - 48);
      if (n == 0) continue;
      printf("%c", c);
    } else if (c == BACKSPACE) {
      if (n != 0) printf("%c %c", BACKSPACE, BACKSPACE);
      n /= 10;
    }
  }

  obj = n;

  return c;
}

char Input(int &obj, int max = 2147483647, int min = -2147483648) {
  char c = '\0';

  printf("%d", obj);
  if (obj == 0) printf("%c", BACKSPACE);

  int sign = obj < 0 ? -1 : 1;

  while (c != ENTER && c != ESC && c != KEY_UP && c != KEY_DOWN) {
    if (obj == 0) printf("0%c", BACKSPACE);

    c = getch();

    if (c >= 48 && c <= 57) {
      if ((sign == 1 && max - obj < max - max/10) || (sign == -1 && min - obj > min - min/10)) continue;
      else if ((sign == 1 && max - obj == max - max/10 && c - 48 > max%10) || (sign == -1 && min - obj == min - min/10 && 48 - c < min%10)) continue;

      obj = obj * 10 + (c - 48) * sign;
      if (obj == 0) continue;
      printf("%c", c);
    } else if (c == BACKSPACE) {
      if (obj != 0) printf("%c %c", BACKSPACE, BACKSPACE);
      else if (obj == 0 && sign == -1) {
        printf("%c%c  %c%c", BACKSPACE, BACKSPACE, BACKSPACE, BACKSPACE);
        sign = 1;
      }
      obj /= 10;
    } else if (c == 45 && obj == 0 && sign == 1) {
      sign = -1;
      printf("%c", '-');
    }
  }

  return c;
}

char Input(long long int &obj, long long int max = 9223372036854775807, long long int min = -9223372036854775807) {
  char c = '\0';

  printf("%d", obj);
  if (obj == 0) printf("%c", BACKSPACE);

  int sign = obj < 0 ? -1 : 1;

  while (c != ENTER && c != ESC && c != KEY_UP && c != KEY_DOWN) {
    if (obj == 0) printf("0%c", BACKSPACE);

    c = getch();

    if (c >= 48 && c <= 57) {
      if ((sign == 1 && max - obj < max - max/10) || (sign == -1 && min - obj > min - min/10)) continue;
      else if ((sign == 1 && max - obj == max - max/10 && c - 48 > max%10) || (sign == -1 && min - obj == min - min/10 && 48 - c < min%10)) continue;

      obj = obj * 10 + (c - 48) * sign;
      if (obj == 0) continue;
      printf("%c", c);
    } else if (c == BACKSPACE) {
      if (obj != 0) printf("%c %c", BACKSPACE, BACKSPACE);
      else if (obj == 0 && sign == -1) {
        printf("%c%c  %c%c", BACKSPACE, BACKSPACE, BACKSPACE, BACKSPACE);
        sign = 1;
      }
      obj /= 10;
    } else if (c == 45 && obj == 0 && sign == 1) {
      sign = -1;
      printf("%c", '-');
    }
  }

  return c;
}

char PureString(char c) {
  if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 95) return c;

  return '\0';
}

char AlphabetString(char c) {
  if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) return c;

  return '\0';
}

char Input(char * obj, char (*StringStyle)(char), unsigned short max_len = 24) {
  char c = '\0';
  short len = strlen(obj);

  printf("%s", obj);

  while (true) {
    c = getch();

    if (c == ENTER || c == ESC) break;
    else if (c == -32) {
  		c = getch();
  		if (c == KEY_UP || c == KEY_DOWN) break;
  		continue;
	  }

    if (StringStyle(c) != '\0') {
      if (len == max_len) continue;
      printf("%c", StringStyle(c));
      obj[len] = StringStyle(c);
      obj[len + 1] = '\0';
      len ++;
    } else if (c == BACKSPACE) {
      if (len == 0) continue;
      else if (len > 0) obj[len - 1] = '\0';
      else obj[0] = '\0';
      printf("%c %c", BACKSPACE, BACKSPACE);
      len --;
    }
  }

  return c;
}

