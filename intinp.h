/* Int input */

/* UShort */

// ..
#define usi_tp = unsigned short int

// Limit
#define USHORT_MAX_VALUE 65535u
#define USHORT_MIN_VALUE 0

// Define
#define USHORT_INPUT_MAX_VALUE USHORT_MAX_VALUE
#define USHORT_INPUT_MIN_VALUE USHORT_MIN_VALUE
#define USHORT_INPUT_POSITION_X NUMBER_INPUT_POSITION_X
#define USHORT_INPUT_POSITION_Y NUMBER_INPUT_POSITION_Y
#define USHORT_INPUT_FOREGROUND NUMBER_INPUT_FOREGROUND
#define USHORT_INPUT_BACKGROUND NUMBER_INPUT_BACKGROUND
#define USHORT_INPUT_ON_ACTIVE_FOREGROUND NUMBER_INPUT_ON_ACTIVE_FOREGROUND
#define USHORT_INPUT_ON_ACTIVE_BACKGROUND NUMBER_INPUT_ON_ACTIVE_BACKGROUND
#define USHORT_INPUT_CONTAINER_SIZE 5
#define USHORT_INPUT_NAV_PANEL NUMBER_INPUT_NAV_PANEL
#define USHORT_INPUT_CHAR_SET NUMBER_INPUT_CHAR_SET
#define USHORT_INPUT_ON_CHANGE_EVENT NULL
#define USHORT_INPUT_ON_VIOLATE_EVENT NULL
#define USHORT_INPUT_ON_INVALID_EVENT NULL
#define USHORT_INPUT_ON_ENTER_EVENT NULL
#define USHORT_INPUT_ON_LEAVE_EVENT NULL

char UShortInput(
  usi_tp &obj,
  usi_tp max = USHORT_INPUT_MAX_VALUE,
  usi_tp min = USHORT_INPUT_MIN_VALUE,
  position_tp position_x = USHORT_INPUT_POSITION_X,
  position_tp position_y = USHORT_INPUT_POSITION_Y,
  color_tp f_color = USHORT_INPUT_FOREGROUND,
  color_tp b_color = USHORT_INPUT_BACKGROUND,
  size_tp container_size = USHORT_INPUT_CONTAINER_SIZE,
  color_tp on_active_f_color = USHORT_INPUT_ON_ACTIVE_FOREGROUND,
  color_tp on_active_b_color = USHORT_INPUT_ON_ACTIVE_BACKGROUND,
  InputLogicTriggerPrototype(NavigationPanel, usi_tp, usi_tp, usi_tp) = USHORT_INPUT_NAV_PANEL,
  InputControlTriggerPrototype(CharacterSet, usi_tp, usi_tp, usi_tp) = USHORT_INPUT_CHAR_SET,
  InputPerformTriggerPrototype(ExpressObj, usi_tp, usi_tp, usi_tp) = USHORT_INPUT_CHAR_SET,
  InputEventTriggerPrototype(OnChange, usi_tp, usi_tp, usi_tp) = USHORT_INPUT_ON_CHANGE_EVENT,
  InputEventTriggerPrototype(OnViolate, usi_tp, usi_tp, usi_tp) = USHORT_INPUT_ON_VIOLATE_EVENT,
  InputEventTriggerPrototype(OnInvalid, usi_tp, usi_tp, usi_tp) = USHORT_INPUT_ON_INVALID_EVENT,
  InputEventTriggerPrototype(OnEnter, usi_tp, usi_tp, usi_tp) = USHORT_INPUT_ON_ENTER_EVENT,
  InputEventTriggerPrototype(OnLeave, usi_tp, usi_tp, usi_tp) = USHORT_INPUT_ON_LEAVE_EVENT
) {
  // Initialize
  SaveColorContext;

  // Setup color
  SetColor(on_active_f_color, on_active_b_color);

  // Draw container
  DrawHorLine(container_size, ' ', position_x, position_y, on_active_f_color, on_active_b_color);

  // Setup cursor position
  GotoXY(position_x, position_y);

  // Init stash
  InitStash;

  // Define c
  char c = '\0';

  // Call OnEnter
  InputEventTriggerHandle(OnEnter);

  // Re-create the context
  printf("%hu", obj);
  if (obj == 0) printf("%c", BACKSPACE);

  // Input
  while (true) {
    // Navigate
    if (InputLogicTriggerHandle(NavigationPanel)) break;

    // Input from ControlPanel
    c = ControlPanel();

    // Navigate
    if (InputLogicTriggerHandle(NavigationPanel)) break;

    if (Input) {
      // Violates max value, Call OnViolate
      if (NumViolatesMaxValue(obj, c, max)) {
        InputEventTriggerHandle(OnViolate);
        continue;
      }

      // Violates min value, Call OnViolate
      if (NumViolatesMinValue(obj, c, min)) InputEventTriggerHandle(OnViolate);

      obj = obj * 10 + CharToNumber(c);
      if (obj == 0) continue;
      printf("%c", c);

      // Call OnChange
      NumberInputEventHandle(OnChange);
    } else if (c == BACKSPACE) {
      if (obj != 0) printf("%c %c", BACKSPACE, BACKSPACE);
      obj /= 10;

      // Call OnChange
      InputEventTriggerHandle(OnChange);
    } else {
      // Call OnInvalid
      InputEventTriggerHandle(OnInvalid);
    }

    if (obj == 0) printf("0%c", BACKSPACE);
  }

  // Check min and re-create the context
  obj = obj < min ? min : obj;

  // Setup color
  SetColor(f_color, b_color);

  // DrawHorLine
  DrawHorLine(container_size, ' ', position_x, position_y, f_color, b_color);
  GotoXY(position_x, position_y);
  printf("%hu", obj);

  // Call OnEnd
  NumberInputEventHandle(OnEnd);

  ApplyColorContext;
  return c;
}