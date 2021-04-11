/* Input */

/* Define */

// Keys
#define ENTER 13
#define ESC 27
#define BACKSPACE 8
#define KEY_UP -1
#define KEY_DOWN -2
#define KEY_LEFT -3
#define KEY_RIGHT -4

#define INPUT_POSITION_X CURRENT_CURSOR_POSITION_X
#define INPUT_POSITION_Y CURRENT_CURSOR_POSITION_Y
#define INPUT_FOREGROUND CURRENT_FOREGROUND
#define INPUT_BACKGROUND CURRENT_BACKGROUND
#define INPUT_ON_ACTIVE_FOREGROUND CURRENT_FOREGROUND
#define INPUT_ON_ACTIVE_BACKGROUND CURRENT_BACKGROUND
#define INPUT_NAV_PANEL STANDARD_NAV_PANEL

/* Prototype */
char ControlPanel();

/* Logic */

/* Control panel */
char ControlPanel() {
  char c = getch();

  if (c == 13) return ENTER;
  else if (c == 27) return ESC;
  else if (c == 8) return BACKSPACE;
  else if (c == -32) {
    c = getch();
    if (c == 75) return KEY_LEFT;
    else if (c == 77) return KEY_RIGHT;
    else if (c == 80) return KEY_DOWN;
    else if (c == 72) return KEY_UP;
    return '\0';
  }
  return c;
}

/* Navigation Panel */

// Define
#define STANDARD_NAV_PANEL StandardNavPanel
#define FULL_ARROW_NAV_PANEL FullArrowNavPanel

// ENTER | ESC | KEY_UP | KEY_DOWN
bool StandardNavPanel(char c) {
  return (c == ENTER || c == ESC || c == KEY_UP || c == KEY_DOWN);
}

// ENTER | ESC | KEY_UP | KEY_DOWN | KEY_LEFT | KEY_RIGHT
bool FullArrowNavPanel(char c) {
  return (c == ENTER || c == ESC || c == KEY_UP || c == KEY_DOWN || c == KEY_LEFT || c == KEY_RIGHT);
}

/* Valid character */

#define NUMBER_VALID_CHAR NumberValidChar
#define ALPHABET_NUMBER_UNDERSCORE_VALID_CHAR AlphabetNumberUnderscoreValidChar

// Only number
char NumberValidChar(char c) {
  if (IsNumericChar(c)) return c;

  return '\0';
}

char AlphabetNumberUnderscoreValidChar(char c) {
  if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 95) return c;

  return '\0';
}

/* Number Input */

// Define

#define NumberInputEvent(identity, num_type) void identity( \
                                                    char &c, \
                                                    num_type &obj, \
                                                    num_type &max, \
                                                    num_type &min, \
                                                    position_tp &position_x, \
                                                    position_tp &position_y, \
                                                    color_tp &f_color, \
                                                    color_tp &b_color, \
                                                    color_tp &on_active_f_color, \
                                                    color_tp &on_active_b_color, \
                                                    size_tp &container_size \
                                                  )

#define NumberInputEventCall(event_name) event_name( \
                                           c, \
                                           obj, \
                                           max, \
                                           min, \
                                           position_x, \
                                           position_y, \
                                           f_color, \
                                           b_color, \
                                           on_active_f_color, \
                                           on_active_b_color, \
                                           container_size \
                                         )

#define NumberInputEventPrototype(event_name, num_type) void (*event_name)( \
                                                          char&, \
                                                          num_type&, \
                                                          num_type&, \
                                                          num_type&, \
                                                          position_tp&, \
                                                          position_tp&, \
                                                          color_tp&, \
                                                          color_tp&, \
                                                          color_tp&, \
                                                          color_tp&, \
                                                          size_tp& \
                                                        )

#define NumberInputEventHandle(event_name) if (event_name != NULL) { \
                                             SaveStash; \
                                             NumberInputEventCall(event_name); \
                                             ApplyStash; \
                                           }

#define NUMBER_INPUT_POSITION_X INPUT_POSITION_X
#define NUMBER_INPUT_POSITION_Y INPUT_POSITION_Y
#define NUMBER_INPUT_FOREGROUND INPUT_FOREGROUND
#define NUMBER_INPUT_BACKGROUND INPUT_BACKGROUND
#define NUMBER_INPUT_ON_ACTIVE_FOREGROUND INPUT_ON_ACTIVE_FOREGROUND
#define NUMBER_INPUT_ON_ACTIVE_BACKGROUND INPUT_ON_ACTIVE_BACKGROUND
#define NUMBER_INPUT_NAV_PANEL INPUT_NAV_PANEL
#define NUMBER_INPUT_ON_CHANGE_EVENT NULL
#define NUMBER_INPUT_ON_SWALLOW_EVENT NULL
#define NUMBER_INPUT_ON_WRONG_EVENT NULL
#define NUMBER_INPUT_ON_START_EVENT NULL
#define NUMBER_INPUT_ON_END_EVENT NULL

/* UShort */

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
#define USHORT_INPUT_ON_CHANGE_EVENT NUMBER_INPUT_ON_CHANGE_EVENT
#define USHORT_INPUT_ON_SWALLOW_EVENT NUMBER_INPUT_ON_SWALLOW_EVENT
#define USHORT_INPUT_ON_WRONG_EVENT NUMBER_INPUT_ON_WRONG_EVENT
#define USHORT_INPUT_ON_START_EVENT NUMBER_INPUT_ON_START_EVENT
#define USHORT_INPUT_ON_END_EVENT NUMBER_INPUT_ON_END_EVENT

char UShortInput(
  unsigned short int &obj,
  unsigned short int max = USHORT_INPUT_MAX_VALUE,
  unsigned short int min = USHORT_INPUT_MIN_VALUE,
  position_tp position_x = USHORT_INPUT_POSITION_X,
  position_tp position_y = USHORT_INPUT_POSITION_Y,
  color_tp f_color = USHORT_INPUT_FOREGROUND,
  color_tp b_color = USHORT_INPUT_BACKGROUND,
  color_tp on_active_f_color = USHORT_INPUT_ON_ACTIVE_FOREGROUND,
  color_tp on_active_b_color = USHORT_INPUT_ON_ACTIVE_BACKGROUND,
  size_tp container_size = USHORT_INPUT_CONTAINER_SIZE,
  bool (*NavigationPanel)(char) = USHORT_INPUT_NAV_PANEL,
  NumberInputEventPrototype(OnChange, unsigned short int) = USHORT_INPUT_ON_CHANGE_EVENT,
  NumberInputEventPrototype(OnSwallow, unsigned short int) = USHORT_INPUT_ON_SWALLOW_EVENT,
  NumberInputEventPrototype(OnWrong, unsigned short int) = USHORT_INPUT_ON_WRONG_EVENT,
  NumberInputEventPrototype(OnStart, unsigned short int) = USHORT_INPUT_ON_START_EVENT,
  NumberInputEventPrototype(OnEnd, unsigned short int) = USHORT_INPUT_ON_END_EVENT
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

  // Call OnStart
  NumberInputEventHandle(OnStart);

  // Re-create the context
  printf("%hu", obj);
  if (obj == 0) printf("%c", BACKSPACE);

  // Input
  while (true) {
    // Navigate
    if (NavigationPanel(c)) break;

    // Input from ControlPanel
    c = ControlPanel();

    // Navigate
    if (NavigationPanel(c)) break;

    if (IsNumericChar(c)) {
      if (CanExceedMaxValue(obj, c, max)) {
        NumberInputEventHandle(OnSwallow);
        continue;
      }

      obj = obj * 10 + CharToNumber(c);
      if (obj == 0) continue;
      printf("%c", c);

      // Call OnChange
      NumberInputEventHandle(OnChange);
    } else if (c == BACKSPACE) {
      if (obj != 0) printf("%c %c", BACKSPACE, BACKSPACE);
      obj /= 10;

      // Call OnChange
      NumberInputEventHandle(OnChange);
    } else {
      // Call OnWrong
      NumberInputEventHandle(OnWrong);
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

/* UInt */

// Limit
#define UINT_MAX_VALUE 4294967295u
#define UINT_MIN_VALUE 0

// Define
#define UINT_INPUT_MAX_VALUE UINT_MAX_VALUE
#define UINT_INPUT_MIN_VALUE UINT_MIN_VALUE
#define UINT_INPUT_POSITION_X NUMBER_INPUT_POSITION_X
#define UINT_INPUT_POSITION_Y NUMBER_INPUT_POSITION_Y
#define UINT_INPUT_FOREGROUND NUMBER_INPUT_FOREGROUND
#define UINT_INPUT_BACKGROUND NUMBER_INPUT_BACKGROUND
#define UINT_INPUT_ON_ACTIVE_FOREGROUND NUMBER_INPUT_ON_ACTIVE_FOREGROUND
#define UINT_INPUT_ON_ACTIVE_BACKGROUND NUMBER_INPUT_ON_ACTIVE_BACKGROUND
#define UINT_INPUT_CONTAINER_SIZE 10
#define UINT_INPUT_NAV_PANEL NUMBER_INPUT_NAV_PANEL
#define UINT_INPUT_ON_CHANGE_EVENT NUMBER_INPUT_ON_CHANGE_EVENT
#define UINT_INPUT_ON_SWALLOW_EVENT NUMBER_INPUT_ON_SWALLOW_EVENT
#define UINT_INPUT_ON_WRONG_EVENT NUMBER_INPUT_ON_WRONG_EVENT
#define UINT_INPUT_ON_START_EVENT NUMBER_INPUT_ON_START_EVENT
#define UINT_INPUT_ON_END_EVENT NUMBER_INPUT_ON_END_EVENT

char UIntInput(
  unsigned int &obj,
  unsigned int max = UINT_INPUT_MAX_VALUE,
  unsigned int min = UINT_INPUT_MIN_VALUE,
  position_tp position_x = UINT_INPUT_POSITION_X,
  position_tp position_y = UINT_INPUT_POSITION_Y,
  color_tp f_color = UINT_INPUT_FOREGROUND,
  color_tp b_color = UINT_INPUT_BACKGROUND,
  color_tp on_active_f_color = UINT_INPUT_ON_ACTIVE_FOREGROUND,
  color_tp on_active_b_color = UINT_INPUT_ON_ACTIVE_BACKGROUND,
  size_tp container_size = UINT_INPUT_CONTAINER_SIZE,
  bool (*NavigationPanel)(char) = UINT_INPUT_NAV_PANEL,
  NumberInputEventPrototype(OnChange, unsigned int) = UINT_INPUT_ON_CHANGE_EVENT,
  NumberInputEventPrototype(OnSwallow, unsigned int) = UINT_INPUT_ON_SWALLOW_EVENT,
  NumberInputEventPrototype(OnWrong, unsigned int) = UINT_INPUT_ON_WRONG_EVENT,
  NumberInputEventPrototype(OnStart, unsigned int) = UINT_INPUT_ON_START_EVENT,
  NumberInputEventPrototype(OnEnd, unsigned int) = UINT_INPUT_ON_END_EVENT
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

  // Call OnStart
  NumberInputEventHandle(OnStart);

  // Re-create the context
  printf("%u", obj);
  if (obj == 0) printf("%c", BACKSPACE);

  // Input
  while (true) {
    // Navigate
    if (NavigationPanel(c)) break;

    // Input from ControlPanel
    c = ControlPanel();

    // Navigate
    if (NavigationPanel(c)) break;

    if (IsNumericChar(c)) {
      if (CanExceedMaxValue(obj, c, max)) {
        NumberInputEventHandle(OnSwallow);
        continue;
      }

      obj = obj * 10 + CharToNumber(c);
      if (obj == 0) continue;
      printf("%c", c);

      // Call OnChange
      NumberInputEventHandle(OnChange);
    } else if (c == BACKSPACE) {
      if (obj != 0) printf("%c %c", BACKSPACE, BACKSPACE);
      obj /= 10;

      // Call OnChange
      NumberInputEventHandle(OnChange);
    } else {
      // Call OnWrong
      NumberInputEventHandle(OnWrong);
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
  printf("%u", obj);

  // Call OnEnd
  NumberInputEventHandle(OnEnd);

  ApplyColorContext;
  return c;
}

/* ULong */

// Limit
#define ULONG_MAX_VALUE 18446744073709551615u
#define ULONG_MIN_VALUE 0

// Define
#define ULONG_INPUT_MAX_VALUE ULONG_MAX_VALUE
#define ULONG_INPUT_MIN_VALUE ULONG_MIN_VALUE
#define ULONG_INPUT_POSITION_X NUMBER_INPUT_POSITION_X
#define ULONG_INPUT_POSITION_Y NUMBER_INPUT_POSITION_Y
#define ULONG_INPUT_FOREGROUND NUMBER_INPUT_FOREGROUND
#define ULONG_INPUT_BACKGROUND NUMBER_INPUT_BACKGROUND
#define ULONG_INPUT_ON_ACTIVE_FOREGROUND NUMBER_INPUT_ON_ACTIVE_FOREGROUND
#define ULONG_INPUT_ON_ACTIVE_BACKGROUND NUMBER_INPUT_ON_ACTIVE_BACKGROUND
#define ULONG_INPUT_CONTAINER_SIZE 20
#define ULONG_INPUT_NAV_PANEL NUMBER_INPUT_NAV_PANEL
#define ULONG_INPUT_ON_CHANGE_EVENT NUMBER_INPUT_ON_CHANGE_EVENT
#define ULONG_INPUT_ON_SWALLOW_EVENT NUMBER_INPUT_ON_SWALLOW_EVENT
#define ULONG_INPUT_ON_WRONG_EVENT NUMBER_INPUT_ON_WRONG_EVENT
#define ULONG_INPUT_ON_START_EVENT NUMBER_INPUT_ON_START_EVENT
#define ULONG_INPUT_ON_END_EVENT NUMBER_INPUT_ON_END_EVENT

char ULongInput(
  unsigned long long int &obj,
  unsigned long long int max = ULONG_INPUT_MAX_VALUE,
  unsigned long long int min = ULONG_INPUT_MIN_VALUE,
  position_tp position_x = ULONG_INPUT_POSITION_X,
  position_tp position_y = ULONG_INPUT_POSITION_Y,
  color_tp f_color = ULONG_INPUT_FOREGROUND,
  color_tp b_color = ULONG_INPUT_BACKGROUND,
  color_tp on_active_f_color = ULONG_INPUT_ON_ACTIVE_FOREGROUND,
  color_tp on_active_b_color = ULONG_INPUT_ON_ACTIVE_BACKGROUND,
  size_tp container_size = ULONG_INPUT_CONTAINER_SIZE,
  bool (*NavigationPanel)(char) = ULONG_INPUT_NAV_PANEL,
  NumberInputEventPrototype(OnChange, unsigned long long int) = ULONG_INPUT_ON_CHANGE_EVENT,
  NumberInputEventPrototype(OnSwallow, unsigned long long int) = ULONG_INPUT_ON_SWALLOW_EVENT,
  NumberInputEventPrototype(OnWrong, unsigned long long int) = ULONG_INPUT_ON_WRONG_EVENT,
  NumberInputEventPrototype(OnStart, unsigned long long int) = ULONG_INPUT_ON_START_EVENT,
  NumberInputEventPrototype(OnEnd, unsigned long long int) = ULONG_INPUT_ON_END_EVENT
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

  // Call OnStart
  NumberInputEventHandle(OnStart);

  // Re-create the context
  printf("%llu", obj);
  if (obj == 0) printf("%c", BACKSPACE);

  // Input
  while (true) {
    // Navigate
    if (NavigationPanel(c)) break;

    // Input from ControlPanel
    c = ControlPanel();

    // Navigate
    if (NavigationPanel(c)) break;

    if (IsNumericChar(c)) {
      if (CanExceedMaxValue(obj, c, max)) {
        NumberInputEventHandle(OnSwallow);
        continue;
      }

      obj = obj * 10 + CharToNumber(c);
      if (obj == 0) continue;
      printf("%c", c);

      // Call OnChange
      NumberInputEventHandle(OnChange);
    } else if (c == BACKSPACE) {
      if (obj != 0) printf("%c %c", BACKSPACE, BACKSPACE);
      obj /= 10;

      // Call OnChange
      NumberInputEventHandle(OnChange);
    } else {
      // Call OnWrong
      NumberInputEventHandle(OnWrong);
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
  printf("%llu", obj);

  // Call OnEnd
  NumberInputEventHandle(OnEnd);

  ApplyColorContext;
  return c;
}

/* Int */

// Limit
#define SHORT_MAX_VALUE 2147483647
#define SHORT_MIN_VALUE -2147483648

// Define
#define SHORT_INPUT_MAX_VALUE SHORT_MAX_VALUE
#define SHORT_INPUT_MIN_VALUE SHORT_MIN_VALUE
#define SHORT_INPUT_POSITION_X NUMBER_INPUT_POSITION_X
#define SHORT_INPUT_POSITION_Y NUMBER_INPUT_POSITION_Y
#define SHORT_INPUT_FOREGROUND NUMBER_INPUT_FOREGROUND
#define SHORT_INPUT_BACKGROUND NUMBER_INPUT_BACKGROUND
#define SHORT_INPUT_ON_ACTIVE_FOREGROUND NUMBER_INPUT_ON_ACTIVE_FOREGROUND
#define SHORT_INPUT_ON_ACTIVE_BACKGROUND NUMBER_INPUT_ON_ACTIVE_BACKGROUND
#define SHORT_INPUT_CONTAINER_SIZE 11
#define SHORT_INPUT_NAV_PANEL NUMBER_INPUT_NAV_PANEL
#define SHORT_INPUT_ON_CHANGE_EVENT NUMBER_INPUT_ON_CHANGE_EVENT
#define SHORT_INPUT_ON_SWALLOW_EVENT NUMBER_INPUT_ON_SWALLOW_EVENT
#define SHORT_INPUT_ON_WRONG_EVENT NUMBER_INPUT_ON_WRONG_EVENT
#define SHORT_INPUT_ON_START_EVENT NUMBER_INPUT_ON_START_EVENT
#define SHORT_INPUT_ON_END_EVENT NUMBER_INPUT_ON_END_EVENT

char ShortInput(
  int &obj,
  int max = SHORT_INPUT_MAX_VALUE,
  int min = SHORT_INPUT_MIN_VALUE,
  position_tp position_x = SHORT_INPUT_POSITION_X,
  position_tp position_y = SHORT_INPUT_POSITION_Y,
  color_tp f_color = SHORT_INPUT_FOREGROUND,
  color_tp b_color = SHORT_INPUT_BACKGROUND,
  color_tp on_active_f_color = SHORT_INPUT_ON_ACTIVE_FOREGROUND,
  color_tp on_active_b_color = SHORT_INPUT_ON_ACTIVE_BACKGROUND,
  size_tp container_size = SHORT_INPUT_CONTAINER_SIZE,
  bool (*NavigationPanel)(char) = SHORT_INPUT_NAV_PANEL,
  NumberInputEventPrototype(OnChange, int) = SHORT_INPUT_ON_CHANGE_EVENT,
  NumberInputEventPrototype(OnSwallow, int) = SHORT_INPUT_ON_SWALLOW_EVENT,
  NumberInputEventPrototype(OnWrong, int) = SHORT_INPUT_ON_WRONG_EVENT,
  NumberInputEventPrototype(OnStart, int) = SHORT_INPUT_ON_START_EVENT,
  NumberInputEventPrototype(OnEnd, int) = SHORT_INPUT_ON_END_EVENT
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

  // Call OnStart
  NumberInputEventHandle(OnStart);

  // Re-create the context
  printf("%hi", obj);
  if (obj == 0) printf("%c", BACKSPACE);

  // Sign
  int sign = obj < 0 ? -1 : 1;

  // Input
  while (true) {
    // Navigate
    if (NavigationPanel(c)) break;

    c = getch();

    // Navigate
    if (NavigationPanel(c)) break;

    if (IsNumericChar(c)) {
      if ((sign == 1 && CanExceedMaxValue(obj, c, max)) || (sign == -1 && CanExceedMinValue(obj, c, min))) {
        NumberInputEventHandle(OnSwallow);
        continue;
      }

      obj = obj * 10 + CharToNumber(c) * sign;
      if (obj == 0) continue;
      printf("%c", c);

      // Call OnChange
      NumberInputEventHandle(OnChange);
    } else if (c == BACKSPACE) {
      if (obj != 0) printf("%c %c", BACKSPACE, BACKSPACE);
      else if (obj == 0 && sign == -1) {
        printf("%c%c  %c%c", BACKSPACE, BACKSPACE, BACKSPACE, BACKSPACE);
        sign = 1;
      }
      obj /= 10;

      // Call OnChange
      NumberInputEventHandle(OnChange);
    } else if (c == 45 && obj == 0 && sign == 1) {
      sign = -1;
      printf("%c", '-');
    } else {
      // Call OnWrong
      NumberInputEventHandle(OnWrong);
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
  printf("%hi", obj);

  // Call OnEnd
  NumberInputEventHandle(OnEnd);

  ApplyColorContext;
  return c;
}

/* Int */

// Limit
#define INT_MAX_VALUE 2147483647
#define INT_MIN_VALUE -2147483648

// Define
#define INT_INPUT_MAX_VALUE INT_MAX_VALUE
#define INT_INPUT_MIN_VALUE INT_MIN_VALUE
#define INT_INPUT_POSITION_X NUMBER_INPUT_POSITION_X
#define INT_INPUT_POSITION_Y NUMBER_INPUT_POSITION_Y
#define INT_INPUT_FOREGROUND NUMBER_INPUT_FOREGROUND
#define INT_INPUT_BACKGROUND NUMBER_INPUT_BACKGROUND
#define INT_INPUT_ON_ACTIVE_FOREGROUND NUMBER_INPUT_ON_ACTIVE_FOREGROUND
#define INT_INPUT_ON_ACTIVE_BACKGROUND NUMBER_INPUT_ON_ACTIVE_BACKGROUND
#define INT_INPUT_CONTAINER_SIZE 11
#define INT_INPUT_NAV_PANEL NUMBER_INPUT_NAV_PANEL
#define INT_INPUT_ON_CHANGE_EVENT NUMBER_INPUT_ON_CHANGE_EVENT
#define INT_INPUT_ON_SWALLOW_EVENT NUMBER_INPUT_ON_SWALLOW_EVENT
#define INT_INPUT_ON_WRONG_EVENT NUMBER_INPUT_ON_WRONG_EVENT
#define INT_INPUT_ON_START_EVENT NUMBER_INPUT_ON_START_EVENT
#define INT_INPUT_ON_END_EVENT NUMBER_INPUT_ON_END_EVENT

char IntInput(
  int &obj,
  int max = INT_INPUT_MAX_VALUE,
  int min = INT_INPUT_MIN_VALUE,
  position_tp position_x = INT_INPUT_POSITION_X,
  position_tp position_y = INT_INPUT_POSITION_Y,
  color_tp f_color = INT_INPUT_FOREGROUND,
  color_tp b_color = INT_INPUT_BACKGROUND,
  color_tp on_active_f_color = INT_INPUT_ON_ACTIVE_FOREGROUND,
  color_tp on_active_b_color = INT_INPUT_ON_ACTIVE_BACKGROUND,
  size_tp container_size = INT_INPUT_CONTAINER_SIZE,
  bool (*NavigationPanel)(char) = INT_INPUT_NAV_PANEL,
  NumberInputEventPrototype(OnChange, int) = INT_INPUT_ON_CHANGE_EVENT,
  NumberInputEventPrototype(OnSwallow, int) = INT_INPUT_ON_SWALLOW_EVENT,
  NumberInputEventPrototype(OnWrong, int) = INT_INPUT_ON_WRONG_EVENT,
  NumberInputEventPrototype(OnStart, int) = INT_INPUT_ON_START_EVENT,
  NumberInputEventPrototype(OnEnd, int) = INT_INPUT_ON_END_EVENT
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

  // Call OnStart
  NumberInputEventHandle(OnStart);

  // Re-create the context
  printf("%d", obj);
  if (obj == 0) printf("%c", BACKSPACE);

  // Sign
  int sign = obj < 0 ? -1 : 1;

  // Input
  while (true) {
    // Navigate
    if (NavigationPanel(c)) break;

    c = getch();

    // Navigate
    if (NavigationPanel(c)) break;

    if (IsNumericChar(c)) {
      if ((sign == 1 && CanExceedMaxValue(obj, c, max)) || (sign == -1 && CanExceedMinValue(obj, c, min))) {
        NumberInputEventHandle(OnSwallow);
        continue;
      }

      obj = obj * 10 + CharToNumber(c) * sign;
      if (obj == 0) continue;
      printf("%c", c);

      // Call OnChange
      NumberInputEventHandle(OnChange);
    } else if (c == BACKSPACE) {
      if (obj != 0) printf("%c %c", BACKSPACE, BACKSPACE);
      else if (obj == 0 && sign == -1) {
        printf("%c%c  %c%c", BACKSPACE, BACKSPACE, BACKSPACE, BACKSPACE);
        sign = 1;
      }
      obj /= 10;

      // Call OnChange
      NumberInputEventHandle(OnChange);
    } else if (c == 45 && obj == 0 && sign == 1) {
      sign = -1;
      printf("%c", '-');
    } else {
      // Call OnWrong
      NumberInputEventHandle(OnWrong);
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
  printf("%d", obj);

  // Call OnEnd
  NumberInputEventHandle(OnEnd);

  ApplyColorContext;
  return c;
}

/* Long */

// Limit
#define LONG_MAX_VALUE 9223372036854775807
#define LONG_MIN_VALUE -9223372036854775807

// Define
#define LONG_INPUT_MAX_VALUE LONG_MAX_VALUE
#define LONG_INPUT_MIN_VALUE LONG_MIN_VALUE
#define LONG_INPUT_POSITION_X NUMBER_INPUT_POSITION_X
#define LONG_INPUT_POSITION_Y NUMBER_INPUT_POSITION_Y
#define LONG_INPUT_FOREGROUND NUMBER_INPUT_FOREGROUND
#define LONG_INPUT_BACKGROUND NUMBER_INPUT_BACKGROUND
#define LONG_INPUT_ON_ACTIVE_FOREGROUND NUMBER_INPUT_ON_ACTIVE_FOREGROUND
#define LONG_INPUT_ON_ACTIVE_BACKGROUND NUMBER_INPUT_ON_ACTIVE_BACKGROUND
#define LONG_INPUT_CONTAINER_SIZE 20
#define LONG_INPUT_NAV_PANEL NUMBER_INPUT_NAV_PANEL
#define LONG_INPUT_ON_CHANGE_EVENT NUMBER_INPUT_ON_CHANGE_EVENT
#define LONG_INPUT_ON_SWALLOW_EVENT NUMBER_INPUT_ON_SWALLOW_EVENT
#define LONG_INPUT_ON_WRONG_EVENT NUMBER_INPUT_ON_WRONG_EVENT
#define LONG_INPUT_ON_START_EVENT NUMBER_INPUT_ON_START_EVENT
#define LONG_INPUT_ON_END_EVENT NUMBER_INPUT_ON_END_EVENT

char LongInput(
  long long int &obj,
  long long int max = LONG_INPUT_MAX_VALUE,
  long long int min = LONG_INPUT_MIN_VALUE,
  position_tp position_x = LONG_INPUT_POSITION_X,
  position_tp position_y = LONG_INPUT_POSITION_Y,
  color_tp f_color = LONG_INPUT_FOREGROUND,
  color_tp b_color = LONG_INPUT_BACKGROUND,
  color_tp on_active_f_color = LONG_INPUT_ON_ACTIVE_FOREGROUND,
  color_tp on_active_b_color = LONG_INPUT_ON_ACTIVE_BACKGROUND,
  size_tp container_size = LONG_INPUT_CONTAINER_SIZE,
  bool (*NavigationPanel)(char) = LONG_INPUT_NAV_PANEL,
  NumberInputEventPrototype(OnChange, long long int) = LONG_INPUT_ON_CHANGE_EVENT,
  NumberInputEventPrototype(OnSwallow, long long int) = LONG_INPUT_ON_SWALLOW_EVENT,
  NumberInputEventPrototype(OnWrong, long long int) = LONG_INPUT_ON_WRONG_EVENT,
  NumberInputEventPrototype(OnStart, long long int) = LONG_INPUT_ON_START_EVENT,
  NumberInputEventPrototype(OnEnd, long long int) = LONG_INPUT_ON_END_EVENT
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

  // Call OnStart
  NumberInputEventHandle(OnStart);

  // Re-create the context
  printf("%lld", obj);
  if (obj == 0) printf("%c", BACKSPACE);

  // Sign
  int sign = obj < 0 ? -1 : 1;

  // Input
  while (true) {
    // Navigate
    if (NavigationPanel(c)) break;

    c = getch();

    // Navigate
    if (NavigationPanel(c)) break;

    if (IsNumericChar(c)) {
      if ((sign == 1 && CanExceedMaxValue(obj, c, max)) || (sign == -1 && CanExceedMinValue(obj, c, min))) {
        NumberInputEventHandle(OnSwallow);
        continue;
      }

      obj = obj * 10 + CharToNumber(c) * sign;
      if (obj == 0) continue;
      printf("%c", c);

      // Call OnChange
      NumberInputEventHandle(OnChange);
    } else if (c == BACKSPACE) {
      if (obj != 0) printf("%c %c", BACKSPACE, BACKSPACE);
      else if (obj == 0 && sign == -1) {
        printf("%c%c  %c%c", BACKSPACE, BACKSPACE, BACKSPACE, BACKSPACE);
        sign = 1;
      }
      obj /= 10;

      // Call OnChange
      NumberInputEventHandle(OnChange);
    } else if (c == 45 && obj == 0 && sign == 1) {
      sign = -1;
      printf("%c", '-');
    } else {
      // Call OnWrong
      NumberInputEventHandle(OnWrong);
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
  printf("%lld", obj);

  // Call OnEnd
  NumberInputEventHandle(OnEnd);

  ApplyColorContext;
  return c;
}

/* String */

// Define

#define StringInputEvent(identity) void identity( \
                                     char &c, \
                                     char * obj, \
                                     unsigned short int &max, \
                                     unsigned short int &min, \
                                     position_tp &position_x, \
                                     position_tp &position_y, \
                                     color_tp &f_color, \
                                     color_tp &b_color, \
                                     color_tp &on_active_f_color, \
                                     color_tp &on_active_b_color, \
                                     size_tp &container_size \
                                   )

#define StringInputEventCall(event_name) event_name( \
                                           c, \
                                           obj, \
                                           max, \
                                           min, \
                                           position_x, \
                                           position_y, \
                                           f_color, \
                                           b_color, \
                                           on_active_f_color, \
                                           on_active_b_color, \
                                           container_size \
                                         )

#define StringInputEventPrototype(event_name) void (*event_name)( \
                                                char&, \
                                                char*, \
                                                unsigned short int&, \
                                                unsigned short int&, \
                                                position_tp&, \
                                                position_tp&, \
                                                color_tp&, \
                                                color_tp&, \
                                                color_tp&, \
                                                color_tp&, \
                                                size_tp& \
                                              )

#define StringInputEventHandle(event_name) if (event_name != NULL) { \
                                             SaveStash; \
                                             StringInputEventCall(event_name); \
                                             ApplyStash; \
                                           }

#define STRING_INPUT_MAX_LEN 24
#define STRING_INPUT_MIN_LEN 0
#define STRING_INPUT_POSITION_X INPUT_POSITION_X
#define STRING_INPUT_POSITION_Y INPUT_POSITION_Y
#define STRING_INPUT_FOREGROUND INPUT_FOREGROUND
#define STRING_INPUT_BACKGROUND INPUT_BACKGROUND
#define STRING_INPUT_ON_ACTIVE_FOREGROUND INPUT_ON_ACTIVE_FOREGROUND
#define STRING_INPUT_ON_ACTIVE_BACKGROUND INPUT_ON_ACTIVE_BACKGROUND
#define STRING_INPUT_CONTAINER_SIZE STRING_INPUT_MAX_LEN
#define STRING_INPUT_VALID_CHAR ALPHABET_NUMBER_UNDERSCORE_VALID_CHAR
#define STRING_INPUT_NAV_PANEL INPUT_NAV_PANEL
#define STRING_INPUT_ON_CHANGE_EVENT NULL
#define STRING_INPUT_ON_SWALLOW_EVENT NULL
#define STRING_INPUT_ON_WRONG_EVENT NULL
#define STRING_INPUT_ON_START_EVENT NULL
#define STRING_INPUT_ON_END_EVENT NULL

char StringInput(
  char *obj,
  unsigned short int max = STRING_INPUT_MAX_LEN,
  unsigned short int min = STRING_INPUT_MIN_LEN,
  position_tp position_x = STRING_INPUT_POSITION_X,
  position_tp position_y = STRING_INPUT_POSITION_Y,
  color_tp f_color = STRING_INPUT_FOREGROUND,
  color_tp b_color = STRING_INPUT_BACKGROUND,
  color_tp on_active_f_color = STRING_INPUT_ON_ACTIVE_FOREGROUND,
  color_tp on_active_b_color = STRING_INPUT_ON_ACTIVE_BACKGROUND,
  size_tp container_size = STRING_INPUT_CONTAINER_SIZE,
  char (*ValidCharacter)(char) = STRING_INPUT_VALID_CHAR,
  bool (*NavigationPanel)(char) = STRING_INPUT_NAV_PANEL,
  StringInputEventPrototype(OnChange) = STRING_INPUT_ON_CHANGE_EVENT,
  StringInputEventPrototype(OnSwallow) = STRING_INPUT_ON_SWALLOW_EVENT,
  StringInputEventPrototype(OnWrong) = STRING_INPUT_ON_WRONG_EVENT,
  StringInputEventPrototype(OnStart) = STRING_INPUT_ON_START_EVENT,
  StringInputEventPrototype(OnEnd) = STRING_INPUT_ON_END_EVENT
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

  // Call OnStart
  NumberInputEventHandle(OnStart);

  short len = strlen(obj);

  printf("%s", obj);

  while (true) {
    // Navigate
    if (NavigationPanel(c)) {
      if (strlen(obj) < min) {
        StringInputEventHandle(OnWrong);
        continue;
      }

      break;
    }

    c = getch();

    // Navigate
    if (NavigationPanel(c)) {
      if (strlen(obj) < min) {
        StringInputEventHandle(OnWrong);
        continue;
      }

      break;
    }

    if (ValidCharacter(c) != '\0') {
      if (len == max) {
        StringInputEventHandle(OnSwallow);
        continue;
      }

      printf("%c", ValidCharacter(c));
      obj[len] = ValidCharacter(c);
      obj[len + 1] = '\0';
      len ++;

      StringInputEventHandle(OnChange);
    } else if (c == BACKSPACE) {
      if (len == 0) continue;
      else if (len > 0) obj[len - 1] = '\0';
      else obj[0] = '\0';
      printf("%c %c", BACKSPACE, BACKSPACE);
      len --;

      StringInputEventHandle(OnChange);
    } else {
      StringInputEventHandle(OnWrong);
    }
  }

  // Setup color
  SetColor(f_color, b_color);

  // DrawHorLine
  DrawHorLine(container_size, ' ', position_x, position_y, f_color, b_color);
  GotoXY(position_x, position_y);
  printf("%s", obj);

  // Call OnEnd
  NumberInputEventHandle(OnEnd);

  ApplyColorContext;
  return c;
}
