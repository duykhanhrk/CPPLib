#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#define show(obj) std::cout << obj << std::endl;

// Keys
#define ENTER 0xD
#define ESC 27
#define BACKSPACE 8
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

char Input(long long int &obj, long long int max = 9223372036854775807, long long int min = -9223372036854775807) {
  char c = '\0';

  min = 0;

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

int main() {
  long long int n = 0;

  Input(n);
  show("");
  show(n);

  system("PAUSE");
  return 0;
}

