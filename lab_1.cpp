#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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

char Input(double &obj, double max = 1.7976931348623158e+308, double min = 2.2250738585072014e-308, short max_fractional_len = 10) {
  char c = '\0';

  int sign = obj < 0 ? -1 : 1;
  double whole;
  double fractional;
  fractional = modf(obj, &whole);
  bool dot = fractional == 0 ? false : true;

  printf("%d", whole);
  if (whole == 0 && !dot) printf("%c", BACKSPACE);

  while (c != ENTER && c != ESC && c != KEY_UP && c != KEY_DOWN) {
    if (whole == 0 && !dot) printf("0%c", BACKSPACE);

    c = getch();

    if (c >= 48 && c <= 57) {
//       if ((sign == 1 && max - obj < max - max/10) || (sign == -1 && min - obj > min - min/10)) continue;
//       else if ((sign == 1 && max - obj == max - max/10) || (sign == -1 && min - obj == min - min/10)) continue;

      if (dot) {
        fractional = fractional * 0.1
      } else {
        whole = whole * 10 + (c - 48) * sign;
        if (whole == 0) continue;
        printf("%c", c);
      }
    } else if (c == BACKSPACE) {
      if (dot) {

      } else {
        if (whole != 0) printf("%c %c", BACKSPACE, BACKSPACE);
        else if (whole == 0 && sign == -1) {
          printf("%c%c  %c%c", BACKSPACE, BACKSPACE, BACKSPACE, BACKSPACE);
          sign = 1;
        }
        whole /= 10;
        whole = (whole/10 > -1 && whole/10 < 1) ? 0 : obj/10;
      }
    } else if (c == 45 && whole == 0 && !dot && sign == 1) {
      sign = -1;
      printf("%c", '-');
    } else if (c == 46 && !dot) {
      dot = true;
      printf("%c", '.');
    }
  }

  modf(whole, &whole);
  obj = whole + fractional;

  return c;
}

int main() {
  double n = 0;

  Input(n);
  show("");
  printf("%lf\n", n);
//   show(n);

  system("PAUSE");
  return 0;
}

