/* Print */

/* Define */

#define ContextArgument position_tp position_x = CURRENT_CURSOR_POSITION_X, \
                        position_tp position_y = CURRENT_CURSOR_POSITION_Y, \
                        color_tp f_color = CURRENT_FOREGROUND, \
                        color_tp b_color = CURRENT_BACKGROUND

#define ApplyContextArgument GotoXY(position_x, position_y); \
                             SetColor(f_color, b_color);

#define EndLine GotoXY(position_x, position_y + 1)

#define SaveContext color_tp __current_foreground__ = CURRENT_FOREGROUND; \
                    color_tp __current_background__ = CURRENT_BACKGROUND; \
                    position_tp __position_x__ = CURRENT_CURSOR_POSITION_X; \
                    position_tp __position_y__ = CURRENT_CURSOR_POSITION_Y

#define ApplyContext GotoXY(__position_x__, __position_y__); \
                     SetColor(__current_foreground__, __current_background__)

/* Print */

void Print(char obj, ContextArgument) {
  SaveColorContext;
  ApplyContextArgument;
  printf("%c", obj);
  ApplyColorContext;
}

void PrintLine(char obj, ContextArgument) {
  SaveColorContext;
  ApplyContextArgument;
  printf("%c\n", obj);
  EndLine;
  ApplyColorContext;
}

void Print(const char *obj, ContextArgument) {
  SaveColorContext;
  ApplyContextArgument;
  printf("%s", obj);
  ApplyColorContext;
}

void PrintLine(const char *obj, ContextArgument) {
  SaveColorContext;
  ApplyContextArgument;
  printf("%s\n", obj);
  EndLine;
  ApplyColorContext;
}

void Print(short int obj, ContextArgument) {
  SaveColorContext;
  ApplyContextArgument;
  printf("%hi", obj);
  ApplyColorContext;
}

void PrintLine(short int obj, ContextArgument) {
  SaveColorContext;
  ApplyContextArgument;
  printf("%hi\n", obj);
  EndLine;
  ApplyColorContext;
}

void Print(int obj, ContextArgument) {
  SaveColorContext;
  ApplyContextArgument;
  printf("%d", obj);
  ApplyColorContext;
}

void PrintLine(int obj, ContextArgument) {
  SaveColorContext;
  ApplyContextArgument;
  printf("%d\n", obj);
  EndLine;
  ApplyColorContext;
}

void Print(long long int obj, ContextArgument) {
  SaveColorContext;
  ApplyContextArgument;
  printf("%ld", obj);
  ApplyColorContext;
}

void PrintLine(long long int obj, ContextArgument) {
  SaveColorContext;
  ApplyContextArgument;
  printf("%ld\n", obj);
  EndLine;
  ApplyColorContext;
}

void Print(unsigned short int obj, ContextArgument) {
  SaveColorContext;
  ApplyContextArgument;
  printf("%hu", obj);
  ApplyColorContext;
}

void PrintLine(unsigned short int obj, ContextArgument) {
  SaveColorContext;
  ApplyContextArgument;
  printf("%hu\n", obj);
  EndLine;
  ApplyColorContext;
}

void Print(unsigned int obj, ContextArgument) {
  SaveColorContext;
  ApplyContextArgument;
  printf("%u", obj);
  ApplyColorContext;
}

void PrintLine(unsigned int obj, ContextArgument) {
  SaveColorContext;
  ApplyContextArgument;
  printf("%u\n", obj);
  EndLine;
  ApplyColorContext;
}

void Print(unsigned long long int obj, ContextArgument) {
  SaveColorContext;
  ApplyContextArgument;
  printf("%llu", obj);
  ApplyColorContext;
}

void PrintLine(unsigned long long int obj, ContextArgument) {
  SaveColorContext;
  ApplyContextArgument;
  printf("%llu\n", obj);
  EndLine;
  ApplyColorContext;
}

void PrintDate(time_t obj, ContextArgument) {
  time(&obj);
  struct tm *timeinfo = localtime(&obj);
  SaveColorContext;
  ApplyContextArgument;
  printf("%hu/%hu/%hu", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
  ApplyColorContext;
}

void PrintDateLine(time_t obj, ContextArgument) {
  time(&obj);
  struct tm *timeinfo = localtime(&obj);
  SaveColorContext;
  ApplyContextArgument;
  printf("%hu/%hu/%hu\n", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
  EndLine;
  ApplyColorContext;
}

/* Echo */

void Echo(char obj, ContextArgument) {
  SaveContext;
  ApplyContextArgument;
  printf("%c", obj);
  ApplyContext;
}

void Echo(const char *obj, ContextArgument) {
  SaveContext;
  ApplyContextArgument;
  printf("%s", obj);
  ApplyContext;
}

void Echo(short int obj, ContextArgument) {
  SaveContext;
  ApplyContextArgument;
  printf("%hi", obj);
  ApplyContext;
}

void Echo(int obj, ContextArgument) {
  SaveContext;
  ApplyContextArgument;
  printf("%d", obj);
  ApplyContext;
}

void Echo(long long int obj, ContextArgument) {
  SaveContext;
  ApplyContextArgument;
  printf("%ld", obj);
  ApplyContext;
}

void Echo(unsigned short int obj, ContextArgument) {
  SaveContext;
  ApplyContextArgument;
  printf("%hu", obj);
  ApplyContext;
}

void Echo(unsigned int obj, ContextArgument) {
  SaveContext;
  ApplyContextArgument;
  printf("%u", obj);
  ApplyContext;
}

void Echo(unsigned long long int obj, ContextArgument) {
  SaveContext;
  ApplyContextArgument;
  printf("%llu", obj);
  ApplyContext;
}

void EchoDate(time_t obj, ContextArgument) {
  time(&obj);
  struct tm *timeinfo = localtime(&obj);
  SaveContext;
  ApplyContextArgument;
  printf("%hu/%hu/%hu", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
  ApplyContext;
}

/* Draw */

#define DRAW_CHR_DEFAULT 32

// Print a line
void DrawVerLine(size_tp size, char chr = DRAW_CHR_DEFAULT, ContextArgument) {
  SaveColorContext;
  ApplyContextArgument;
  for (int i = 0; i < size - 1; i ++) {
    GotoXY(position_x, position_y + i);
    printf("%c\n", chr);
  }
  GotoXY(position_x, position_y + size - 1);
  printf("%c", chr);
  ApplyColorContext;
}

void DrawVerLineLine(size_tp size, char chr = DRAW_CHR_DEFAULT, ContextArgument) {
  SaveColorContext;
  ApplyContextArgument;
  for (int i = 0; i < size; i ++) {
    GotoXY(position_x, position_y + i);
    printf("%c\n", chr);
  }
  GotoXY(position_x, position_y + size);
  ApplyColorContext;
}

void DrawHorLine(size_tp size, char chr = DRAW_CHR_DEFAULT, ContextArgument) {
  SaveColorContext;
  ApplyContextArgument;

  char *line = new char[size + 1];
  for (int i = 0; i < size; i ++) {
    line[i] = chr;
  }
  line[size] = '\0';

  printf("%s", line);

  delete [] line;
  ApplyColorContext;
}

void DrawHorLineLine(size_tp size, char chr = DRAW_CHR_DEFAULT, ContextArgument) {
  SaveColorContext;
  ApplyContextArgument;

  char *line = new char[size + 1];
  for (int i = 0; i < size; i ++) {
    line[i] = chr;
  }
  line[size] = '\0';

  printf("%s", line);
  delete [] line;

  EndLine;
  ApplyColorContext;
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
