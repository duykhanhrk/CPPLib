#include "cslscr.h"

InputEventTriggerInit(InputOnchage) {
  Write("Ban cua nhap: ", 4, 4);
  Echo("     ");
  Write(VoidTypeToUShort(obj));
  if (VoidTypeToUShort(obj) < VoidTypeToUShort(min)) {
    Write("Vi pham gioi han", 4, 5);
    return;
  }
  Write("                                             ", 4, 5);
}

InputEventTriggerInit(InputOnViolate) {
  Write("Vi pham gioi han", 4, 5);
}

int main() {
  uh_tp n = 0;

  HideCursor;

  Input(
    n,
    USHORT_INPUT_MAX_VALUE,
    20,
    CURSOR_POSITION_X,
    CURSOR_POSITION_Y,
    CURRENT_FOREGROUND,
    CURRENT_BACKGROUND,
    USHORT_INPUT_CONTAINER_SIZE + 1,
    FOREGROUND_RED,
    BACKGROUND_WHITE,
    NULL,
    NULL,
    InputOnchage,
    InputOnViolate,
    NULL,
    NULL,
    NULL
  );

  Write("Hello world", 0, 10);

  GotoXY(0, WINDOW_ROWS - 1);
  system("PAUSE");
  return 0;
}
