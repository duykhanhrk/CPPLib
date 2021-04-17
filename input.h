/* Input */

/* Define */

/* Logic trigger */

#define InputLogicTriggerPrototype(logic_name, obj_dtype, max_dtype, min_dtype) \
        bool (*logic_name)(char, value_dtype, max_dtype, min_dtype, position_tp, position_tp, color_tp, color_tp)

#define InputLogicTriggerInit(logic_name, obj_dtype, max_dtype, min_dtype) \
        bool logic_name(char c, obj_dtype obj, max_dtype max, min_dtype min, position_tp position_x, position_tp position_y, color_tp f_color, color_tp b_color)

#define InputLogicTriggerCall(logic_name) \
        logic_name(c, obj, position_x, position_y, f_color, b_color);

#define InputLogicTriggerHandle(logic_name) \
        InputLogicTriggerCall(logic_name)

/* Control trigger */

#define InputControlTriggerPrototype(control_name, obj_dtype, max_dtype, min_dtype) \
        char (*control_name)(char, value_dtype, max_dtype, min_dtype, position_tp, position_tp, color_tp, color_tp)

#define InputControlTriggerInit(control_name, obj_dtype, max_dtype, min_dtype) \
        char control_name(char c, obj_dtype obj, max_dtype max, min_dtype min, position_tp position_x, position_tp position_y, color_tp f_color, color_tp b_color)

#define InputControlTriggerCall(control_name) \
        control_name(c, obj, position_x, position_y, f_color, b_color);

#define InputControlTriggerHandle(control_name) \
        InputControlTriggerCall(control_name)

/* Perform trigger */

#define InputPerformTriggerPrototype(perform_name, obj_dtype, max_dtype, min_dtype) \
        void (*perform_name)(char, value_dtype, max_dtype, min_dtype, position_tp, position_tp, color_tp, color_tp)

#define InputPerformTriggerInit(perform_name, obj_dtype, max_dtype, min_dtype) \
        void perform_name(char c, obj_dtype obj, max_dtype max, min_dtype min, position_tp position_x, position_tp position_y, color_tp f_color, color_tp b_color)

#define InputPerformTriggerCall(perform_name) \
        perform_name(c, obj, position_x, position_y, f_color, b_color);

#define InputPerformTriggerHandle(perform_name) \
        InputPerformTriggerCall(perform_name)

/* Event trigger */

#define InputEventTriggerPrototype(event_name, obj_dtype, max_dtype, min_dtype) \
        void (*event_name)(char&, value_dtype, max_dtype, min_dtype, position_tp, position_tp, color_tp, color_tp)

#define InputEventTriggerInit(event_name, obj_dtype, max_dtype, min_dtype) \
        void event_name(char &c, obj_dtype obj, max_dtype max, min_dtype min, position_tp position_x, position_tp position_y, color_tp f_color, color_tp b_color)

#define InputEventTriggerCall(event_name) \
        event_name(c, obj, position_x, position_y, f_color, b_color);

#define InputEventTriggerHandle(event_name) \
        if (event_name != NULL) { \
          SaveStash; \
          InputEventTriggerCall(event_name); \
          ApplyStash; \
        }

// Control Panel
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

/* Inlucde features */
#include "navpn.h"
#include "charset.h"
