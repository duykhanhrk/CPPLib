#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "cslscr.h"
#include <iostream>

#define IsLeapYear(year) (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))

// NumberInputEvent(TwoCharStyle, unsigned int) {
//   GotoXY(position_x, position_y);
//   if (obj < 10) printf("0%hu", obj);
//   else printf("%hu", obj);
// }

// char DateInput(
//   time_t &obj,
//   time_t max = time(NULL),
//   time_t min = time(NULL),
//   position_tp position_x = CURRENT_CURSOR_POSITION_X,
//   position_tp position_y = CURRENT_CURSOR_POSITION_Y,
//   color_tp f_color = CURRENT_FOREGROUND,
//   color_tp b_color = CURRENT_BACKGROUND,
//   color_tp on_active_f_color = INPUT_ON_ACTIVE_FOREGROUND,
//   color_tp on_active_b_color = INPUT_ON_ACTIVE_BACKGROUND,
//   size_tp container_size = UINT_CONTAINER_SIZE,
//   bool (*NavigationPanel)(char) = STANDARD_NAV_PANEL,
//   NumberInputEventPrototype(OnChange, unsigned int) = NULL,
//   NumberInputEventPrototype(OnSwallow, unsigned int) = NULL,
//   NumberInputEventPrototype(OnWrong, unsigned int) = NULL,
//   NumberInputEventPrototype(OnStart, unsigned int) = NULL,
//   NumberInputEventPrototype(OnEnd, unsigned int) = NULL
// ) {
//   // Start
//   int current_foreground = CURRENT_FOREGROUND;
//   int current_background = CURRENT_BACKGROUND;
//   GotoXY(position_x, position_y);


//   unsigned int year, month ,day;

//   time(&obj);
//   struct tm *timeinfo = localtime(&obj);
//   year = timeinfo->tm_year + 1900;
//   month = timeinfo->tm_mon + 1;
//   day = timeinfo->tm_mday;
// //  mktime(timeinfo);

//   char c = '\0';

//   printf("%hu/0%hu/%hu", day, month, year);

//   int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

//   char current_edit = 'd';
//   while (!NavigationPanel(c)) {
//     if (current_edit == 'd') {
//       days[1] = IsLeapYear(year) ? 29 : 28;
//       c = UIntInput(
//         day,
//         days[month - 1],
//         1,
//         position_x,
//         position_y,
//         f_color,
//         b_color,
//         on_active_f_color,
//         on_active_b_color,
//         2,
//         FULL_ARROW_NAV_PANEL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         TwoCharStyle
//       );
//       if (c == KEY_RIGHT) current_edit = 'm';
//       else if (c == KEY_LEFT) current_edit = 'y';
//     } else if (current_edit == 'm') {
//       days[1] = IsLeapYear(year) ? 29 : 28;
//       c = UIntInput(
//         month,
//         12,
//         1,
//         position_x + 3,
//         position_y,
//         f_color,
//         b_color,
//         on_active_f_color,
//         on_active_b_color,
//         2,
//         FULL_ARROW_NAV_PANEL,
//         NULL,
//         NULL,
//         NULL,
//         NULL,
//         TwoCharStyle
//       );

//       if (day > days[month - 1]) {
//         day = days[month - 1];
//         GotoXY(position_x, position_y);
//         printf("%u", day);
//         GotoXY(position_x + 5, position_y);
//       }

//       if (c == KEY_RIGHT) current_edit = 'y';
//       else if (c == KEY_LEFT) current_edit = 'd';
//     } else if (current_edit == 'y') {
//       c = UIntInput(
//         year,
//         9999,
//         1900,
//         position_x + 6,
//         position_y,
//         f_color,
//         b_color,
//         on_active_f_color,
//         on_active_b_color,
//         2,
//         FULL_ARROW_NAV_PANEL
//       );

//       if (month == 2 && day == 29 && !IsLeapYear(year)) {
//         day = 28u;
//         GotoXY(position_x, position_y);
//         printf("%u", 28);
//         GotoXY(position_x + 10, position_y);
//       }

//       if (c == KEY_RIGHT) current_edit = 'd';
//       else if (c == KEY_LEFT) current_edit = 'm';
//     }
//   }

//   SetColor(current_foreground, current_background);
//   return c;
// }

// NumberInputEvent(OnChange, int) {
//   Print("Ki tu ban vua nhap la: ", 0, 4);
//   Print(c);
// }

int main() {
//   time_t t = time(NULL);
//   DateInput(
//     t,
//     time(NULL),
//     time(NULL),
//     CURRENT_CURSOR_POSITION_X,
//     CURRENT_CURSOR_POSITION_Y,
//     CURRENT_FOREGROUND,
//     CURRENT_BACKGROUND,
//     FOREGROUND_BLUE,
//     BACKGROUND_WHITE
//   );

//   char a[25];
//   a[0] = '\0';
//   StringInput(a);

  GotoXY(0, WINDOW_ROWS - 1);
  system("PAUSE");
  return 0;
}
