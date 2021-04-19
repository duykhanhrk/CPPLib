/* Print */

/* Define */
#define ContextArgumentsPrint position_tp position_x = CURSOR_POSITION_X, \
                              position_tp position_y = CURSOR_POSITION_Y, \
                              color_tp f_color = CURRENT_FOREGROUND, \
                              color_tp b_color = CURRENT_BACKGROUND

#define EndLine GotoXY(position_x, position_y + 1)

/* Write */

void Write(char obj, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;
  printf("%c", obj);
  ApplyColorContext;
}

void Write(const char *obj, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;
  printf("%s", obj);
  ApplyColorContext;
}

void Write(short int obj, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;
  printf("%hi", obj);
  ApplyColorContext;
}

void Write(int obj, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;
  printf("%d", obj);
  ApplyColorContext;
}

void Write(long long int obj, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;
  printf("%lld", obj);
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
  printf("%lld\n", obj);
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
}

/* Echo */

void Echo(char obj, ContextArgumentsPrint) {
  SaveContext;
  ApplyContextArguments;
  printf("%c", obj);
  ApplyContext;
}

void Echo(const char *obj, ContextArgumentsPrint) {
  SaveContext;
  ApplyContextArguments;
  printf("%s", obj);
  ApplyContext;
}

void Echo(short int obj, ContextArgumentsPrint) {
  SaveContext;
  ApplyContextArguments;
  printf("%hi", obj);
  ApplyContext;
}

void Echo(int obj, ContextArgumentsPrint) {
  SaveContext;
  ApplyContextArguments;
  printf("%d", obj);
  ApplyContext;
}

void Echo(long long int obj, ContextArgumentsPrint) {
  SaveContext;
  ApplyContextArguments;
  printf("%lld", obj);
  ApplyContext;
}

void Echo(unsigned short int obj, ContextArgumentsPrint) {
  SaveContext;
  ApplyContextArguments;
  printf("%hu", obj);
  ApplyContext;
}

void Echo(unsigned int obj, ContextArgumentsPrint) {
  SaveContext;
  ApplyContextArguments;
  printf("%u", obj);
  ApplyContext;
}

void Echo(unsigned long long int obj, ContextArgumentsPrint) {
  SaveContext;
  ApplyContextArguments;
  printf("%llu", obj);
  ApplyContext;
}

// Print DateTime

void WriteDate(time_t obj, ContextArgumentsPrint) {
  tm time_info = *(localtime(&obj));
  SaveColorContext;
  ApplyContextArguments;
  if (time_info.tm_mday < 10) printf("0%hu", time_info.tm_mday);
  else printf("%hu", time_info.tm_mday);

  if (time_info.tm_mon < 10) printf("/0%hu", time_info.tm_mon + 1);
  else printf("/%hu", time_info.tm_mon + 1);

  printf("/%hu", time_info.tm_year + 1900);
  ApplyColorContext;
}

void PrintDate(time_t obj, ContextArgumentsPrint) {
  struct tm time_info = *(localtime(&obj));
  SaveColorContext;
  ApplyContextArguments;
  if (time_info.tm_mday < 10) printf("0%hu", time_info.tm_mday);
  else printf("%hu", time_info.tm_mday);

  if (time_info.tm_mon < 10) printf("/0%hu", time_info.tm_mon + 1);
  else printf("/%hu", time_info.tm_mon + 1);

  printf("/%hu", time_info.tm_year + 1900);
  EndLine;
  ApplyColorContext;
}

void EchoDate(time_t obj, ContextArgumentsPrint) {
  struct tm time_info = *(localtime(&obj));
  SaveContext;
  ApplyContextArguments;
  if (time_info.tm_mday < 10) printf("0%hu", time_info.tm_mday);
  else printf("%hu", time_info.tm_mday);

  if (time_info.tm_mon < 10) printf("/0%hu", time_info.tm_mon + 1);
  else printf("/%hu", time_info.tm_mon + 1);

  printf("/%hu", time_info.tm_year + 1900);
  ApplyContext;
}

/* Draw */

#define DRAW_CHR_DEFAULT 32

// Draw a line
void DrawVerLine(size_tp size, char chr = DRAW_CHR_DEFAULT, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;
  for (int i = 0; i < size - 1; i ++) {
    GotoXY(position_x, position_y + i);
    printf("%c\n", chr);
  }
  GotoXY(position_x, position_y + size - 1);
  printf("%c", chr);
  ApplyColorContext;
}

void DrawHorLine(size_tp size, char chr = DRAW_CHR_DEFAULT, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;

  char *line = new char[size + 1];
  for (int i = 0; i < size; i ++) {
    line[i] = chr;
  }
  line[size] = '\0';

  printf("%s", line);

  delete [] line;
  ApplyColorContext;
}

void PrintVerLine(size_tp size, char chr = DRAW_CHR_DEFAULT, ContextArgumentsPrint) {
  SaveColorContext;
  ApplyContextArguments;
  for (int i = 0; i < size; i ++) {
    GotoXY(position_x, position_y + i);
    printf("%c\n", chr);
  }
  GotoXY(position_x, position_y + size);
  ApplyColorContext;
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
  GotoXY(position_x, position_y + height - 1);
  printf("%s", line);
  delete [] line;

  for (int i = 1; i < height - 1; i ++) {
    GotoXY(position_x, position_y + i);
    printf("%c", chr);

    GotoXY(position_x + width - 1, position_y + i);
    printf("%c", chr);
  }

  GotoXY(position_x, position_y + height);
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
