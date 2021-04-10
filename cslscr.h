/* Console Screen */

/* Include */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <iostream>

/* Define */

// Debug
#define show(obj) std::cout << obj << std::endl

/* include cslscr feature */
#include "color.h"
#include "cursor.h"
#include "input.h"
/* Logic */



#define ULONG_MAX_VALUE 18446744073709551615u
#define ULONG_MIN_VALUE 0
#define ULONG_START_INPUT_DEFAULT ULongStartInputDefault
#define ULONG_END_INPUT_DEFAULT ULongEndInputDefault

// ULong start, end input
void ULongStartInputDefault(unsigned long long int obj) {
  // ..
}

void ULongEndInputDefault(unsigned long long int obj) {
  printf("%u", obj);
}

char ULongInput(
  unsigned long long int &obj,
  unsigned long long int max = ULONG_MAX_VALUE,
  unsigned long long int min = ULONG_MIN_VALUE,
  int position_x = CURRENT_CURSOR_POSITION_X, int position_y = CURRENT_CURSOR_POSITION_Y,
  int f_color = CURRENT_FOREGROUND, int b_color = CURRENT_FOREGROUND,
  bool (*NavigationPanel)(char) = STANDARD_NAV_PANEL,
  void (*StartInput)(unsigned long long int) = ULONG_START_INPUT_DEFAULT,
  void (*EndInput)(unsigned long long int) = ULONG_END_INPUT_DEFAULT
) {
  // Start
  int current_foreground = CURRENT_FOREGROUND;
  int current_background = CURRENT_BACKGROUND;
  SetColor(f_color, b_color);
  GotoXY(position_x, position_y);

  char c = '\0';

  printf("%u", obj);
  if (obj == 0) printf("%c", BACKSPACE);

  while (!NavigationPanel(c)) {
    if (obj == 0) printf("0%c", BACKSPACE);

    c = getch();

    if (c >= 48 && c <= 57) {
      if (max - obj < max - max/10) continue;
      else if (max - obj == max - max/10 && c - 48 > max%10) continue;

      obj = obj * 10 + (c - 48);
      if (obj == 0) continue;
      printf("%c", c);
    } else if (c == BACKSPACE) {
      if (obj != 0) printf("%c %c", BACKSPACE, BACKSPACE);
      obj /= 10;
    }
  }

  obj = obj < min ? min : obj;
  GotoXY(position_x, position_y);
  EndInput(obj);

  SetColor(current_foreground, current_background);

  return c;
}

#define INT_MAX_VALUE 2147483647
#define INT_MIN_VALUE -2147483648
#define INT_START_INPUT_DEFAULT IntStartInputDefault
#define INT_END_INPUT_DEFAULT IntEndInputDefault

void IntStartInputDefault(int obj) {
  // ..
}

void IntEndInputDefault(int obj) {
  printf("%u", obj);
}

char Input(
  int &obj,
  int max = INT_MAX_VALUE,
  int min = INT_MIN_VALUE,
  int position_x = CURRENT_CURSOR_POSITION_X, int position_y = CURRENT_CURSOR_POSITION_Y,
  int f_color = CURRENT_FOREGROUND, int b_color = CURRENT_FOREGROUND,
  bool (*NavigationPanel)(char) = STANDARD_NAV_PANEL,
  void (*StartInput)(int) = INT_START_INPUT_DEFAULT,
  void (*EndInput)(int) = INT_END_INPUT_DEFAULT
) {
  int current_foreground = CURRENT_FOREGROUND;
  int current_background = CURRENT_BACKGROUND;
  SetColor(f_color, b_color);
  GotoXY(position_x, position_y);

  char c = '\0';

  printf("%d", obj);
  if (obj == 0) printf("%c", BACKSPACE);

  int sign = obj < 0 ? -1 : 1;

  while (!NavigationPanel(c)) {
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

  obj = obj < min ? min : obj;
  GotoXY(position_x, position_y);
  EndInput(obj);

  SetColor(current_foreground, current_background);

  return c;
}

#define LONG_MAX_VALUE 9223372036854775807
#define LONG_MIN_VALUE -9223372036854775807
#define LONG_START_INPUT_DEFAULT LongStartInputDefault
#define LONG_END_INPUT_DEFAULT LongEndInputDefault

void LongStartInputDefault(long long int obj) {
  // ..
}

void LongEndInputDefault(long long int obj) {
  printf("%u", obj);
}

char Input(
  long long int &obj,
  long long int max = LONG_MAX_VALUE,
  long long int min = LONG_MIN_VALUE,
  int position_x = CURRENT_CURSOR_POSITION_X, int position_y = CURRENT_CURSOR_POSITION_Y,
  int f_color = CURRENT_FOREGROUND, int b_color = CURRENT_FOREGROUND,
  bool (*NavigationPanel)(char) = STANDARD_NAV_PANEL,
  void (*StartInput)(long long int) = LONG_START_INPUT_DEFAULT,
  void (*EndInput)(long long int) = LONG_END_INPUT_DEFAULT
) {
  int current_foreground = CURRENT_FOREGROUND;
  int current_background = CURRENT_BACKGROUND;
  SetColor(f_color, b_color);
  GotoXY(position_x, position_y);

  char c = '\0';

  printf("%d", obj);
  if (obj == 0) printf("%c", BACKSPACE);

  int sign = obj < 0 ? -1 : 1;

  while (!NavigationPanel(c)) {
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

  obj = obj < min ? min : obj;
  GotoXY(position_x, position_y);
  EndInput(obj);

  SetColor(current_foreground, current_background);

  return c;
}

#define STRING_MAX_LEN 24
#define PURE_STRING PureString
#define ALPHABET_STRING AlphabetString

char PureString(char c) {
  if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 95) return c;

  return '\0';
}

char AlphabetString(char c) {
  if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) return c;

  return '\0';
}

char Input(
  char * obj,
  unsigned short max_len = STRING_MAX_LEN,
  char (*StringStyle)(char) = PURE_STRING,
  int position_x = CURRENT_CURSOR_POSITION_X, int position_y = CURRENT_CURSOR_POSITION_Y,
  int f_color = CURRENT_FOREGROUND, int b_color = CURRENT_FOREGROUND,
  bool (*NavigationPanel)(char) = STANDARD_NAV_PANEL,
  void (*StartInput)(unsigned int) = NULL,
  void (*EndInput)(unsigned int) = NULL

) {
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
void DrawVerLine(char chr, int height) {
  int x = CursorPositionX();
  int y = CursorPositionY();

  for (int i = 0; i < height; i ++) {
    GotoXY(x, y + i);
    printf("%c\n", chr);
  }
}

void DrawVerLine(char chr, int height, int f_color, int b_color, int x, int y) {
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

void DrawVerLineWC(char chr, int height, int f_color, int b_color) {
  int current_foreground = CURRENT_FOREGROUND;
  int current_background = CURRENT_BACKGROUND;

  SetColor(f_color, b_color);

  DrawVerLine(chr, height);

  SetColor(current_foreground, current_background);
}

void DrawVerLineWP(char chr, int height, int x, int y) {
  GotoXY(x, y);
  DrawVerLine(chr, height);
}

void DrawHorLine(char chr, int width) {
  char *line = new char[width + 1];

  for (int i = 0; i < width; i ++) {
    line[i] = chr;
  }
  line[width] = '\0';

  printf("%s", line);

  delete [] line;
}

void DrawHorLine(char chr, int width, int f_color, int b_color, int x, int y) {
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

void DrawHorLineWC(char chr, int width, int f_color, int b_color) {
  int current_foreground = CURRENT_FOREGROUND;
  int current_background = CURRENT_BACKGROUND;

  SetColor(f_color, b_color);

  DrawHorLine(chr, width);

  SetColor(current_foreground, current_background);
}

void DrawHorLineWP(char chr, int width, int x, int y) {
  GotoXY(x, y);
  DrawHorLine(chr, width);
}

// Print a rectangle

void DrawRec(char chr, int width, int height) {
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

void DrawRec(char chr, int width, int height, int f_color, int b_color, int x, int y) {
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

void DrawRecWC(char chr, int width, int height, int f_color, int b_color) {
  int current_foreground = CURRENT_FOREGROUND;
  int current_background = CURRENT_BACKGROUND;

  SetColor(f_color, b_color);

  DrawRec(chr, width, height);

  SetColor(current_foreground, current_background);
}

void DrawRecWP(char chr, int width, int height, int x, int y) {
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

void DrawRecShape(char chr, int width, int height) {
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

void DrawRecShape(char chr, int width, int height, int f_color, int b_color, int x, int y) {
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
    GotoXY(x, y + i);
    printf("%s\n", line);
  }

  delete [] line;

  SetColor(current_foreground, current_background);
}

void DrawRecShapeWC(char chr, int width, int height, int f_color, int b_color) {
  int current_foreground = CURRENT_FOREGROUND;
  int current_background = CURRENT_BACKGROUND;

  SetColor(f_color, b_color);

  DrawRecShape(chr, width, height);

  SetColor(current_foreground, current_background);
}

void DrawRecShapeWP(char chr, int width, int height, int x, int y) {
  GotoXY(x, y);

  DrawRecShape(chr, width, height);
}

