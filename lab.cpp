/* Lab */

#include "cslscr.h"

#define IsLeapYear(year) (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
#define SLASH 47

bool DateNavPanel(char c) {
  return (c == ENTER || c == ESC || c == KEY_UP || c == KEY_DOWN || c == KEY_LEFT || c == KEY_RIGHT || c == SLASH);
}

NumberInputEvent(TwoCharStyle, unsigned int) {
  GotoXY(position_x, position_y);
  if (obj < 10) printf("0%hu", obj);
  else printf("%hu", obj);
}

time_t DateParse(
  unsigned int day, unsigned int month, unsigned int year
) {
  time_t rawtime;
  time(&rawtime);
  struct tm * time_info = localtime(&rawtime);
  time_info->tm_mday = day;
  time_info->tm_mon = month - 1;
  time_info->tm_year = year - 1900;
  return mktime(time_info);
}

#define __TimeTToDayMonthYear__(obj, time_info, day, month, year) unsigned int day, month, year; \
                                                                  time_info = gmtime(&obj); \
                                                                  year = time_info->tm_year + 1900; \
                                                                  month = time_info->tm_mon + 1; \
                                                                  day = time_info->tm_mday;

#define __SetDay__(value) __SavePositionContext__; \
                          day = value; \
                          GotoXY(position_x, position_y); \
                          if (day < 10) printf("0%u", day); \
                          else printf("%u", day); \
                          __ApplyPositionContext__;

#define __SetMonth__(value) __SavePositionContext__; \
                            month = value; \
                            GotoXY(position_x + 3, position_y); \
                            if (month < 10) printf("0%u", month); \
                            else printf("%u", day); \
                            __ApplyPositionContext__


// Define
#define CURRENT_DATETIME time(NULL)

// Limit
#define DATETIME_MAX_VALUE CURRENT_DATETIME
#define DATETIME_MIN_VALUE DateParse(1, 1, 2001)

// ..
#define DATE_INPUT_MAX_VALUE DATETIME_MAX_VALUE
#define DATE_INPUT_MIN_VALUE DATETIME_MIN_VALUE
#define DATE_INPUT_POSITION_X INPUT_POSITION_X
#define DATE_INPUT_POSITION_Y INPUT_POSITION_Y
#define DATE_INPUT_FOREGROUND INPUT_FOREGROUND
#define DATE_INPUT_BACKGROUND INPUT_BACKGROUND
#define DATE_INPUT_ON_ACTIVE_FOREGROUND INPUT_ON_ACTIVE_FOREGROUND
#define DATE_INPUT_ON_ACTIVE_BACKGROUND INPUT_ON_ACTIVE_BACKGROUND
#define DATE_INPUT_CONTAINER_SIZE 9
#define DATE_INPUT_NAV_PANEL STANDARD_NAV_PANEL
#define DATE_INPUT_ON_CHANGE_EVENT NULL
#define DATE_INPUT_ON_EXCEED_EVENT NULL
#define DATE_INPUT_ON_INVALID_EVENT NULL
#define DATE_INPUT_ON_START_EVENT NULL
#define DATE_INPUT_ON_END_EVENT NULL

char DateInput(
  time_t &obj,
  time_t max = DATE_INPUT_MAX_VALUE,
  time_t min = DATE_INPUT_MIN_VALUE,
  position_tp position_x = DATE_INPUT_POSITION_X,
  position_tp position_y = DATE_INPUT_POSITION_Y,
  color_tp f_color = DATE_INPUT_FOREGROUND,
  color_tp b_color = DATE_INPUT_BACKGROUND,
  color_tp on_active_f_color = DATE_INPUT_ON_ACTIVE_FOREGROUND,
  color_tp on_active_b_color = DATE_INPUT_ON_ACTIVE_BACKGROUND,
  size_tp container_size = DATE_INPUT_CONTAINER_SIZE,
  __NavigationPanelPrototype__ = DATE_INPUT_NAV_PANEL,
  NumberInputEventPrototype(OnChange, time_t) = DATE_INPUT_ON_CHANGE_EVENT,
  NumberInputEventPrototype(OnExceed, time_t) = DATE_INPUT_ON_EXCEED_EVENT,
  NumberInputEventPrototype(OnInvalid, time_t) = DATE_INPUT_ON_INVALID_EVENT,
  NumberInputEventPrototype(OnStart, time_t) = DATE_INPUT_ON_START_EVENT,
  NumberInputEventPrototype(OnEnd, time_t) = DATE_INPUT_ON_END_EVENT
) {
  // Initialize
  __SaveColorContext__;

  // Setup color
  SetColor(f_color, f_color);

  // Draw container
  DrawHorLine(container_size, ' ', position_x, position_y, f_color, f_color);

  // Setup cursor position
  GotoXY(position_x, position_y);

  // Init stash
  __InitStash__;

  char c = '\0';

  // Call OnStart
  NumberInputEventHandle(OnStart);

  struct tm *time_info;
  __TimeTToDayMonthYear__(obj, time_info, day, month, year);
  __TimeTToDayMonthYear__(max, time_info, a_day, a_month, a_year);
  __TimeTToDayMonthYear__(min, time_info, i_day, i_month, i_year);

  printf("%hu/0%hu/%hu", day, month, year);

  unsigned int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  int max_day, max_month;
  int min_day, min_month;

  char current_edit = 'd';
  while (!NavigationPanel(c)) {
    if (current_edit == 'd') {
      days[1] = IsLeapYear(year) ? 29 : 28;

      if (year == a_year && month == a_month) max_day = a_day;
      else max_day = days[month - 1];

      if (year == i_year && month == i_month) min_day = i_day;
      else min_day = 1;

      c = UIntInput(
        day, max_day, min_day, position_x, position_y,
        f_color, b_color, on_active_f_color, on_active_b_color, 2,
        FULL_ARROW_NAV_PANEL, NULL, NULL, NULL, NULL, TwoCharStyle
      );

      if (c == KEY_RIGHT || c == SLASH) current_edit = 'm';
      else if (c == KEY_LEFT) current_edit = 'y';
    } else if (current_edit == 'm') {
      days[1] = IsLeapYear(year) ? 29 : 28;

      if (year == a_year) max_month = a_month;
      else max_month = 12;

      if (year == i_year) min_month = i_month;
      else min_month = 1;

      c = UIntInput(
        month, max_month, min_month, position_x + 3, position_y,
        f_color, b_color, on_active_f_color, on_active_b_color, 2,
        FULL_ARROW_NAV_PANEL, NULL, NULL, NULL, NULL, TwoCharStyle
      );

      if (day > days[month - 1]) {
        __SetDay__(days[month - 1]);
      }

      if (year == a_year && month == a_month && day > a_day) {
        __SetDay__(a_day);
      }

      if (year == i_year && month == i_month && day < i_day) {
        __SetDay__(i_day);
      }

      if (c == KEY_RIGHT || c == SLASH) current_edit = 'y';
      else if (c == KEY_LEFT) current_edit = 'd';
    } else if (current_edit == 'y') {
      c = UIntInput(
        year, a_year, i_year, position_x + 6, position_y,
        f_color, b_color, on_active_f_color, on_active_b_color, 2,
        FULL_ARROW_NAV_PANEL
      );

      // February
      if (month == 2 && day == 29 && !IsLeapYear(year)) {
        __SetDay__(28u);
      }

      if (year == a_year) {
        if (month > a_month) {
          __SetMonth__(a_month);
        }

        if (month == a_month && day > a_day) {
          __SetDay__(a_day);
        }
      }

      if (year == i_year) {
        if (month < i_month) {
          __SetMonth__(i_month);
        }

        if (month == i_month && day < i_day) {
          __SetDay__(i_day);
        }
      }

      if (c == KEY_RIGHT) current_edit = 'd';
      else if (c == KEY_LEFT) current_edit = 'm';
    }

    obj = DateParse(day, month, year);
    if (obj > max || obj < min) NumberInputEventHandle(OnExceed);
  }

 __ApplyColorContext__;
  return c;
}

NumberInputEvent(OnChange, int) {
  Print("Ki tu ban vua nhap la: ", 0, 4);
  Print(c);
}

NumberInputEvent(OnExceed, unsigned int) {
  Print("Phai nam trong doan: ", 4, 5);
  Print(min);
  Print(" -> ");
  Print(max);
}

NumberInputEvent(OnChangeTwo, unsigned int) {
  if (obj < min) Echo("Wrong", 4, 4);
  else Echo("OK    ", 4, 4);

  Print("                                               ", 4, 5);
}

int main() {
  time_t t = time(NULL);
  DateInput(t);
//   unsigned int n = 0;
//   UIntInput(
//     n,
//     200,
//     10,
//     UINT_INPUT_POSITION_X,
//     UINT_INPUT_POSITION_Y,
//     UINT_INPUT_FOREGROUND,
//     UINT_INPUT_BACKGROUND,
//     UINT_INPUT_ON_ACTIVE_FOREGROUND,
//     UINT_INPUT_ON_ACTIVE_BACKGROUND,
//     3,
//     UINT_INPUT_NAV_PANEL,
//     OnChangeTwo,
//     OnExceed,
//     NULL,
//     NULL,
//     NULL
//   );

  GotoXY(0, WINDOW_ROWS - 1);
  system("PAUSE");
  return 0;
}
