/* Print */

/* Define */
<<<<<<< HEAD:__Temp__/Base/print.h

#define __ContextArgument__ position_tp position_x = CURSOR_POSITION_X, \
                        position_tp position_y = CURSOR_POSITION_Y, \
                        color_tp f_color = CURRENT_FOREGROUND, \
                        color_tp b_color = CURRENT_BACKGROUND

#define __ApplyContextArgument__ GotoXY(position_x, position_y); \
                             SetColor(f_color, b_color);
=======
#define ContextArgumentsPrint position_tp position_x = CURRENT_CURSOR_POSITION_X, \
                              position_tp position_y = CURRENT_CURSOR_POSITION_Y, \
                              color_tp f_color = CURRENT_FOREGROUND, \
                              color_tp b_color = CURRENT_BACKGROUND
>>>>>>> 83a09e54bef5d6771cf7e79981bb72f3c2d0f7c6:print.h

#define __EndLine__ GotoXY(position_x, position_y + 1)

<<<<<<< HEAD:__Temp__/Base/print.h
#define __SaveContext__ color_tp __current_foreground__ = CURRENT_FOREGROUND; \
                        color_tp __current_background__ = CURRENT_BACKGROUND; \
                        position_tp __position_x__ = CURSOR_POSITION_X; \
                        position_tp __position_y__ = CURSOR_POSITION_Y

#define __ApplyContext__ GotoXY(__position_x__, __position_y__); \
                         SetColor(__current_foreground__, __current_background__)

/* Print */

void Print(char obj, __ContextArgument__) {
  __SaveColorContext__;
  __ApplyContextArgument__;
=======
/* Write */

void Write(char obj, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;
>>>>>>> 83a09e54bef5d6771cf7e79981bb72f3c2d0f7c6:print.h
  printf("%c", obj);
 __ApplyColorContext__;
}

<<<<<<< HEAD:__Temp__/Base/print.h
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
=======
void Write(const char *obj, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;
>>>>>>> 83a09e54bef5d6771cf7e79981bb72f3c2d0f7c6:print.h
  printf("%s", obj);
 __ApplyColorContext__;
}

<<<<<<< HEAD:__Temp__/Base/print.h
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
=======
void Write(short int obj, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;
>>>>>>> 83a09e54bef5d6771cf7e79981bb72f3c2d0f7c6:print.h
  printf("%hi", obj);
 __ApplyColorContext__;
}

<<<<<<< HEAD:__Temp__/Base/print.h
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
=======
void Write(int obj, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;
  printf("%d", obj);
  ApplyColorContext;
}

void Write(long long int obj, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;
  printf("%ld", obj);
  ApplyColorContext;
}

void Write(unsigned short int obj, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;
  printf("%hu", obj);
  ApplyColorContext;
}

void Write(unsigned int obj, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;
  printf("%u", obj);
  ApplyColorContext;
}

void Write(unsigned long long int obj, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;
  printf("%llu", obj);
  ApplyColorContext;
}

/* Print */

void Print(char obj, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;
  printf("%c\n", obj);
  EndLine;
  ApplyColorContext;
}

void Print(const char *obj, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;
  printf("%s\n", obj);
  EndLine;
  ApplyColorContext;
}

void Print(short int obj, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;
  printf("%hi\n", obj);
  EndLine;
  ApplyColorContext;
}

void Print(int obj, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;
  printf("%d\n", obj);
  EndLine;
  ApplyColorContext;
}

void Print(long long int obj, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;
  printf("%ld\n", obj);
  EndLine;
  ApplyColorContext;
}

void Print(unsigned short int obj, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;
  printf("%hu\n", obj);
  EndLine;
  ApplyColorContext;
}

void Print(unsigned int obj, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;
  printf("%u\n", obj);
  EndLine;
  ApplyColorContext;
}

void Print(unsigned long long int obj, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;
  printf("%llu\n", obj);
  EndLine;
  ApplyColorContext;
>>>>>>> 83a09e54bef5d6771cf7e79981bb72f3c2d0f7c6:print.h
}

/* Echo */

<<<<<<< HEAD:__Temp__/Base/print.h
void Echo(char obj, __ContextArgument__) {
  __SaveContext__;
  __ApplyContextArgument__;
=======
void Echo(char obj, ContextArgumentsPrint) {
  SaveContext;
  ApplyContextArguments;
>>>>>>> 83a09e54bef5d6771cf7e79981bb72f3c2d0f7c6:print.h
  printf("%c", obj);
  __ApplyContext__;
}

<<<<<<< HEAD:__Temp__/Base/print.h
void Echo(const char *obj, __ContextArgument__) {
  __SaveContext__;
  __ApplyContextArgument__;
=======
void Echo(const char *obj, ContextArgumentsPrint) {
  SaveContext;
  ApplyContextArguments;
>>>>>>> 83a09e54bef5d6771cf7e79981bb72f3c2d0f7c6:print.h
  printf("%s", obj);
  __ApplyContext__;
}

<<<<<<< HEAD:__Temp__/Base/print.h
void Echo(short int obj, __ContextArgument__) {
  __SaveContext__;
  __ApplyContextArgument__;
=======
void Echo(short int obj, ContextArgumentsPrint) {
  SaveContext;
  ApplyContextArguments;
>>>>>>> 83a09e54bef5d6771cf7e79981bb72f3c2d0f7c6:print.h
  printf("%hi", obj);
  __ApplyContext__;
}

<<<<<<< HEAD:__Temp__/Base/print.h
void Echo(int obj, __ContextArgument__) {
  __SaveContext__;
  __ApplyContextArgument__;
=======
void Echo(int obj, ContextArgumentsPrint) {
  SaveContext;
  ApplyContextArguments;
>>>>>>> 83a09e54bef5d6771cf7e79981bb72f3c2d0f7c6:print.h
  printf("%d", obj);
  __ApplyContext__;
}

<<<<<<< HEAD:__Temp__/Base/print.h
void Echo(long long int obj, __ContextArgument__) {
  __SaveContext__;
  __ApplyContextArgument__;
=======
void Echo(long long int obj, ContextArgumentsPrint) {
  SaveContext;
  ApplyContextArguments;
>>>>>>> 83a09e54bef5d6771cf7e79981bb72f3c2d0f7c6:print.h
  printf("%ld", obj);
  __ApplyContext__;
}

<<<<<<< HEAD:__Temp__/Base/print.h
void Echo(unsigned short int obj, __ContextArgument__) {
  __SaveContext__;
  __ApplyContextArgument__;
=======
void Echo(unsigned short int obj, ContextArgumentsPrint) {
  SaveContext;
  ApplyContextArguments;
>>>>>>> 83a09e54bef5d6771cf7e79981bb72f3c2d0f7c6:print.h
  printf("%hu", obj);
  __ApplyContext__;
}

<<<<<<< HEAD:__Temp__/Base/print.h
void Echo(unsigned int obj, __ContextArgument__) {
  __SaveContext__;
  __ApplyContextArgument__;
=======
void Echo(unsigned int obj, ContextArgumentsPrint) {
  SaveContext;
  ApplyContextArguments;
>>>>>>> 83a09e54bef5d6771cf7e79981bb72f3c2d0f7c6:print.h
  printf("%u", obj);
  __ApplyContext__;
}

<<<<<<< HEAD:__Temp__/Base/print.h
void Echo(unsigned long long int obj, __ContextArgument__) {
  __SaveContext__;
  __ApplyContextArgument__;
=======
void Echo(unsigned long long int obj, ContextArgumentsPrint) {
  SaveContext;
  ApplyContextArguments;
>>>>>>> 83a09e54bef5d6771cf7e79981bb72f3c2d0f7c6:print.h
  printf("%llu", obj);
  __ApplyContext__;
}

<<<<<<< HEAD:__Temp__/Base/print.h
void EchoDate(time_t obj, __ContextArgument__) {
  time(&obj);
  struct tm *timeinfo = localtime(&obj);
  __SaveContext__;
  __ApplyContextArgument__;
=======
// Print DateTime

void WriteDate(time_t obj, ContextArgumentsPrint) {
  time(&obj);
  struct tm *timeinfo = localtime(&obj);
  SaveColorContext;
  ApplyContextArguments;
  printf("%hu/%hu/%hu", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
  ApplyColorContext;
}

void PrintDate(time_t obj, ContextArgumentsPrint) {
  time(&obj);
  struct tm *timeinfo = localtime(&obj);
  SaveColorContext;
  ApplyContextArguments;
  printf("%hu/%hu/%hu\n", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
  EndLine;
  ApplyColorContext;
}

void EchoDate(time_t obj, ContextArgumentsPrint) {
  time(&obj);
  struct tm *timeinfo = localtime(&obj);
  SaveContext;
  ApplyContextArguments;
>>>>>>> 83a09e54bef5d6771cf7e79981bb72f3c2d0f7c6:print.h
  printf("%hu/%hu/%hu", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
  __ApplyContext__;
}

/* Draw */

#define DRAW_CHR_DEFAULT 32

<<<<<<< HEAD:__Temp__/Base/print.h
// Print a line
void DrawVerLine(size_tp size, char chr = DRAW_CHR_DEFAULT, __ContextArgument__) {
  __SaveColorContext__;
  __ApplyContextArgument__;
=======
// Draw a line
void DrawVerLine(size_tp size, char chr = DRAW_CHR_DEFAULT, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;
>>>>>>> 83a09e54bef5d6771cf7e79981bb72f3c2d0f7c6:print.h
  for (int i = 0; i < size - 1; i ++) {
    GotoXY(position_x, position_y + i);
    printf("%c\n", chr);
  }
  GotoXY(position_x, position_y + size - 1);
  printf("%c", chr);
 __ApplyColorContext__;
}

<<<<<<< HEAD:__Temp__/Base/print.h
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
=======
void DrawHorLine(size_tp size, char chr = DRAW_CHR_DEFAULT, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;
>>>>>>> 83a09e54bef5d6771cf7e79981bb72f3c2d0f7c6:print.h

  char *line = new char[size + 1];
  for (int i = 0; i < size; i ++) {
    line[i] = chr;
  }
  line[size] = '\0';

  printf("%s", line);

  delete [] line;
 __ApplyColorContext__;
}

<<<<<<< HEAD:__Temp__/Base/print.h
void DrawHorLineLine(size_tp size, char chr = DRAW_CHR_DEFAULT, __ContextArgument__) {
  __SaveColorContext__;
  __ApplyContextArgument__;

  char *line = new char[size + 1];
=======
void PrintVerLine(size_tp size, char chr = DRAW_CHR_DEFAULT, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;
>>>>>>> 83a09e54bef5d6771cf7e79981bb72f3c2d0f7c6:print.h
  for (int i = 0; i < size; i ++) {
    GotoXY(position_x, position_y + i);
    printf("%c\n", chr);
  }
<<<<<<< HEAD:__Temp__/Base/print.h
  line[size] = '\0';

  printf("%s", line);
  delete [] line;

  __EndLine__;
 __ApplyColorContext__;
=======
  GotoXY(position_x, position_y + size);
  ApplyColorContext;
>>>>>>> 83a09e54bef5d6771cf7e79981bb72f3c2d0f7c6:print.h
}

void PrintHorLine(size_tp size, char chr = DRAW_CHR_DEFAULT, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;

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

// Draw a rectangle

void DrawRec(size_tp width, size_tp height, char chr = DRAW_CHR_DEFAULT, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;

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
    GotoXY(position_x, position_y + i);
    printf("%c", chr);

    GotoXY(position_x + width - 1, position_y + i);
    printf("%c", chr);
  }

  GotoXY(x, y + height);
  ApplyColorContext;
}

// Draw rectangle shape

void DrawRecShape(size_tp width, size_tp height, char chr = DRAW_CHR_DEFAULT, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;

  char *line = new char[width + 1];

  for (int i = 0; i < width; i ++) {
    line[i] = chr;
  }
  line[width] = '\0';

  for (int i = 0; i < height - 1; i ++) {
    GotoXY(position_x, position_y + i);
    printf("%s", line);
  }

  delete [] line;

  ApplyContextArguments;
}
