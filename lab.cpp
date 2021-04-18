#include "cslscr.h"

void status(bool st) {
  if (st) Write("  OK   ", 4, 6, FOREGROUND_WHITE, BACKGROUND_GREEN);
  else Write(" WRONG ", 4, 6, FOREGROUND_WHITE, BACKGROUND_RED);
}

InputEventTriggerInit(InputOnChage) {
  Write("Ban cua nhap: ", 4, 4);
  Echo("                           ");
  Write(VoidTypeToShort(obj));

  if (VoidTypeToShort(obj) < VoidTypeToShort(min)) status(false);
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
  if (VoidTypeToShort(obj) < VoidTypeToShort(min)) status(false);
  else status(true);
}

InputEventTriggerInit(InputOnLeave) {
  Write("                                         ", 4, 8);
}

int main() {
  h_tp n = 0;

  HideCursor;

  Input(
    n,
    SHORT_INPUT_MAX_VALUE,
    -100,
    CURSOR_POSITION_X,
    CURSOR_POSITION_Y,
    CURRENT_FOREGROUND,
    CURRENT_BACKGROUND,
    SHORT_INPUT_CONTAINER_SIZE + 1,
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
