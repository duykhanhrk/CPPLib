/* Print */

/* Define */

#define __ContextArgument__ position_tp position_x = CURRENT_CURSOR_POSITION_X, \
                        position_tp position_y = CURRENT_CURSOR_POSITION_Y, \
                        color_tp f_color = CURRENT_FOREGROUND, \
                        color_tp b_color = CURRENT_BACKGROUND

#define __ApplyContextArgument__ GotoXY(position_x, position_y); \
                             SetColor(f_color, b_color);

#define __EndLine__ GotoXY(position_x, position_y + 1)

#define __SaveContext__ color_tp __current_foreground__ = CURRENT_FOREGROUND; \
                        color_tp __current_background__ = CURRENT_BACKGROUND; \
                        position_tp __position_x__ = CURRENT_CURSOR_POSITION_X; \
                        position_tp __position_y__ = CURRENT_CURSOR_POSITION_Y

#define __ApplyContext__ GotoXY(__position_x__, __position_y__); \
                         SetColor(__current_foreground__, __current_background__)

/* Print */

void Print(char obj, __ContextArgument__) {
  __SaveColorContext__;
  __ApplyContextArgument__;
  printf("%c", obj);
 __ApplyColorContext__;
}

void PrintLine(char obj, __ContextArgument__) {
  __SaveColorContext__;
  __ApplyContextArgument__;
  printf("%c\n", obj);
  __EndLine__;
 __ApplyColorContext__;
}

void Print(const char *obj, __ContextArgument__) {
  __SaveColorContext__;
  __ApplyContextArgument__;
  printf("%s", obj);
 __ApplyColorContext__;
}

void PrintLine(const char *obj, __ContextArgument__) {
  __SaveColorContext__;
  __ApplyContextArgument__;
  printf("%s\n", obj);
  __EndLine__;
 __ApplyColorContext__;
}

void Print(short int obj, __ContextArgument__) {
  __SaveColorContext__;
  __ApplyContextArgument__;
  printf("%hi", obj);
 __ApplyColorContext__;
}

void PrintLine(short int obj, __ContextArgument__) {
  __SaveColorContext__;
  __ApplyContextArgument__;
  printf("%hi\n", obj);
  __EndLine__;
 __ApplyColorContext__;
}

void Print(int obj, __ContextArgument__) {
  __SaveColorContext__;
  __ApplyContextArgument__;
  printf("%d", obj);
 __ApplyColorContext__;
}

void PrintLine(int obj, __ContextArgument__) {
  __SaveColorContext__;
  __ApplyContextArgument__;
  printf("%d\n", obj);
  __EndLine__;
 __ApplyColorContext__;
}

void Print(long long int obj, __ContextArgument__) {
  __SaveColorContext__;
  __ApplyContextArgument__;
  printf("%ld", obj);
 __ApplyColorContext__;
}

void PrintLine(long long int obj, __ContextArgument__) {
  __SaveColorContext__;
  __ApplyContextArgument__;
  printf("%ld\n", obj);
  __EndLine__;
 __ApplyColorContext__;
}

void Print(unsigned short int obj, __ContextArgument__) {
  __SaveColorContext__;
  __ApplyContextArgument__;
  printf("%hu", obj);
 __ApplyColorContext__;
}

void PrintLine(unsigned short int obj, __ContextArgument__) {
  __SaveColorContext__;
  __ApplyContextArgument__;
  printf("%hu\n", obj);
  __EndLine__;
 __ApplyColorContext__;
}

void Print(unsigned int obj, __ContextArgument__) {
  __SaveColorContext__;
  __ApplyContextArgument__;
  printf("%u", obj);
 __ApplyColorContext__;
}

void PrintLine(unsigned int obj, __ContextArgument__) {
  __SaveColorContext__;
  __ApplyContextArgument__;
  printf("%u\n", obj);
  __EndLine__;
 __ApplyColorContext__;
}

void Print(unsigned long long int obj, __ContextArgument__) {
  __SaveColorContext__;
  __ApplyContextArgument__;
  printf("%llu", obj);
 __ApplyColorContext__;
}

void PrintLine(unsigned long long int obj, __ContextArgument__) {
  __SaveColorContext__;
  __ApplyContextArgument__;
  printf("%llu\n", obj);
  __EndLine__;
 __ApplyColorContext__;
}

void PrintDate(time_t obj, __ContextArgument__) {
  time(&obj);
  struct tm *timeinfo = localtime(&obj);
  __SaveColorContext__;
  __ApplyContextArgument__;
  printf("%hu/%hu/%hu", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
 __ApplyColorContext__;
}

void PrintDateLine(time_t obj, __ContextArgument__) {
  time(&obj);
  struct tm *timeinfo = localtime(&obj);
  __SaveColorContext__;
  __ApplyContextArgument__;
  printf("%hu/%hu/%hu\n", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
  __EndLine__;
 __ApplyColorContext__;
}

/* Echo */

void Echo(char obj, __ContextArgument__) {
  __SaveContext__;
  __ApplyContextArgument__;
  printf("%c", obj);
  __ApplyContext__;
}

void Echo(const char *obj, __ContextArgument__) {
  __SaveContext__;
  __ApplyContextArgument__;
  printf("%s", obj);
  __ApplyContext__;
}

void Echo(short int obj, __ContextArgument__) {
  __SaveContext__;
  __ApplyContextArgument__;
  printf("%hi", obj);
  __ApplyContext__;
}

void Echo(int obj, __ContextArgument__) {
  __SaveContext__;
  __ApplyContextArgument__;
  printf("%d", obj);
  __ApplyContext__;
}

void Echo(long long int obj, __ContextArgument__) {
  __SaveContext__;
  __ApplyContextArgument__;
  printf("%ld", obj);
  __ApplyContext__;
}

void Echo(unsigned short int obj, __ContextArgument__) {
  __SaveContext__;
  __ApplyContextArgument__;
  printf("%hu", obj);
  __ApplyContext__;
}

void Echo(unsigned int obj, __ContextArgument__) {
  __SaveContext__;
  __ApplyContextArgument__;
  printf("%u", obj);
  __ApplyContext__;
}

void Echo(unsigned long long int obj, __ContextArgument__) {
  __SaveContext__;
  __ApplyContextArgument__;
  printf("%llu", obj);
  __ApplyContext__;
}

void EchoDate(time_t obj, __ContextArgument__) {
  time(&obj);
  struct tm *timeinfo = localtime(&obj);
  __SaveContext__;
  __ApplyContextArgument__;
  printf("%hu/%hu/%hu", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
  __ApplyContext__;
}

/* Draw */

#define DRAW_CHR_DEFAULT 32

// Print a line
void DrawVerLine(size_tp size, char chr = DRAW_CHR_DEFAULT, __ContextArgument__) {
  __SaveColorContext__;
  __ApplyContextArgument__;
  for (int i = 0; i < size - 1; i ++) {
    GotoXY(position_x, position_y + i);
    printf("%c\n", chr);
  }
  GotoXY(position_x, position_y + size - 1);
  printf("%c", chr);
 __ApplyColorContext__;
}

void DrawVerLineLine(size_tp size, char chr = DRAW_CHR_DEFAULT, __ContextArgument__) {
  __SaveColorContext__;
  __ApplyContextArgument__;
  for (int i = 0; i < size; i ++) {
    GotoXY(position_x, position_y + i);
    printf("%c\n", chr);
  }
  GotoXY(position_x, position_y + size);
 __ApplyColorContext__;
}

void DrawHorLine(size_tp size, char chr = DRAW_CHR_DEFAULT, __ContextArgument__) {
  __SaveColorContext__;
  __ApplyContextArgument__;

  char *line = new char[size + 1];
  for (int i = 0; i < size; i ++) {
    line[i] = chr;
  }
  line[size] = '\0';

  printf("%s", line);

  delete [] line;
 __ApplyColorContext__;
}

void DrawHorLineLine(size_tp size, char chr = DRAW_CHR_DEFAULT, __ContextArgument__) {
  __SaveColorContext__;
  __ApplyContextArgument__;

  char *line = new char[size + 1];
  for (int i = 0; i < size; i ++) {
    line[i] = chr;
  }
  line[size] = '\0';

  printf("%s", line);
  delete [] line;

  __EndLine__;
 __ApplyColorContext__;
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
    printf("%s", line);
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
