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

// Utility
#define CharToNumber(c) (c - 48)
#define IsNumericChar(c) (c >= 48 && c <= 57)
#define CanExceedMaxValue(num, c, max) ((max - num < max - max/10) || (max - num == max - max/10 && CharToNumber(c) > max%10))

// Data type
#define size_tp int

// Navigation Panel
#define STANDARD_NAV_PANEL StandardNavPanel
#define FULL_ARROW_NAV_PANEL FullArrowNavPanel

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
// ENTER | ESC | KEY_UP | KEY_DOWN
bool StandardNavPanel(char c) {
  return (c == ENTER || c == ESC || c == KEY_UP || c == KEY_DOWN);
}

// ENTER | ESC | KEY_UP | KEY_DOWN | KEY_LEFT | KEY_RIGHT
bool FullArrowNavPanel(char c) {
  return (c == ENTER || c == ESC || c == KEY_UP || c == KEY_DOWN || c == KEY_LEFT || c == KEY_RIGHT);
}

/* Number Input */

// Define

#define InitStash int __stash_postion_x__; \
                  int __stash_postion_y__; \
                  int __stash_b_color__; \
                  int __stash_f_color__

#define SaveStash int __stash_postion_x__ = CURRENT_CURSOR_POSITION_X; \
                  int __stash_postion_y__ = CURRENT_CURSOR_POSITION_Y; \
                  int __stash_b_color__ = CURRENT_BACKGROUND; \
                  int __stash_f_color__ = CURRENT_FOREGROUND

#define ApplyStash GotoXY(__stash_postion_x__, __stash_postion_y__); \
                   SetColor(__stash_f_color__, __stash_b_color__)

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

// Limit
#define UINT_MAX_VALUE 4294967295u
#define UINT_MIN_VALUE 0
#define UINT_CONTAINER_SIZE 10

// Color
#define INPUT_ON_ACTIVE_FOREGROUND CURRENT_FOREGROUND
#define INPUT_ON_ACTIVE_BACKGROUND CURRENT_BACKGROUND
#define INPUT_FOREGROUND CURRENT_FOREGROUND
#define INPUT_BACKGROUND CURRENT_BACKGROUND

/* UInt */

char UIntInput(
  unsigned int &obj,
  unsigned int max = UINT_MAX_VALUE,
  unsigned int min = UINT_MIN_VALUE,
  position_tp position_x = CURRENT_CURSOR_POSITION_X,
  position_tp position_y = CURRENT_CURSOR_POSITION_Y,
  color_tp f_color = CURRENT_FOREGROUND,
  color_tp b_color = CURRENT_FOREGROUND,
  color_tp on_active_f_color = INPUT_ON_ACTIVE_FOREGROUND,
  color_tp on_active_b_color = INPUT_ON_ACTIVE_BACKGROUND,
  size_tp container_size = UINT_CONTAINER_SIZE,
  bool (*NavigationPanel)(char) = STANDARD_NAV_PANEL,
  NumberInputEventPrototype(OnChange, unsigned int) = NULL,
  NumberInputEventPrototype(OnSwallow, unsigned int) = NULL,
  NumberInputEventPrototype(OnWrong, unsigned int) = NULL,
  NumberInputEventPrototype(OnStart, unsigned int) = NULL,
  NumberInputEventPrototype(OnEnd, unsigned int) = NULL
) {
  // Initialize
  // Save current color
  int current_foreground = CURRENT_FOREGROUND;
  int current_background = CURRENT_BACKGROUND;

  // Setup color and cursor position
  SetColor(on_active_f_color, on_active_b_color);
  GotoXY(position_x, position_y);

  // PrintRecShape
  printf("%s", "  ");

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

  // Setup color and cursor position
  SetColor(f_color, b_color);
  GotoXY(position_x, position_y);
  printf("%s", "  ");
  GotoXY(position_x, position_y);
  printf("%u", obj);

  // Call OnEnd
  NumberInputEventHandle(OnEnd);

  // Reset current color
  SetColor(current_foreground, current_background);
  return c;
}
