#include "cslscr.h"

void status(bool st) {
  if (st) Write("  OK   ", 4, 6, FOREGROUND_WHITE, BACKGROUND_GREEN);
  else Write(" WRONG ", 4, 6, FOREGROUND_WHITE, BACKGROUND_RED);
}

InputEventTriggerInit(InputOnChage) {
  if (VoidTypeToDateTime(obj) < VoidTypeToDateTime(min)) status(false);
  else status(true);

  Write("                                         ", 4, 8);
}

InputEventTriggerInit(InputOnInvalid) {
  Write("         Chi chap nhan ki tu so          ", 4, 8, FOREGROUND_WHITE, BACKGROUND_YELLOW);
}

InputEventTriggerInit(InputOnViolate) {
  Write("  Phai nam trong pham vi tu 20 den 2000  ", 4, 8, FOREGROUND_WHITE, BACKGROUND_YELLOW);
}

InputEventTriggerInit(InputOnEnter) {
  if (VoidTypeToDateTime(obj) < VoidTypeToDateTime(min)) status(false);
  else status(true);
}

InputEventTriggerInit(InputOnLeave) {
  Write("                                         ", 4, 8);
}

int main() {
  HideCursor;

  // l_tp n = 0;

  // Input(
  //   n,
  //   LONG_INPUT_MAX_VALUE,
  //   LONG_INPUT_MIN_VALUE,
  //   CURSOR_POSITION_X,
  //   CURSOR_POSITION_Y,
  //   CURRENT_FOREGROUND,
  //   CURRENT_BACKGROUND,
  //   LONG_INPUT_CONTAINER_SIZE + 1,
  //   FOREGROUND_RED,
  //   BACKGROUND_WHITE,
  //   NULL,
  //   NULL,
  //   InputOnChage,
  //   InputOnViolate,
  //   InputOnInvalid,
  //   InputOnEnter,
  //   InputOnLeave
  // );

  time_t t = DateParse(3, 4, 2021);
  Write("Nhap ngay thang nam: ");
  DateInput(
    t,
    DATE_INPUT_MAX_VALUE,
    DATE_INPUT_MIN_VALUE,
    CURSOR_POSITION_X,
    CURSOR_POSITION_Y,
    CURRENT_FOREGROUND,
    CURRENT_BACKGROUND,
    DATE_INPUT_CONTAINER_SIZE,
    FOREGROUND_RED,
    BACKGROUND_WHITE,
    NULL,
    NULL,
    InputOnChage,
    InputOnViolate,
    InputOnInvalid,
    InputOnEnter,
    InputOnLeave
);

  GotoXY(0, WINDOW_ROWS - 1);
  system("PAUSE");
  return 0;
}
