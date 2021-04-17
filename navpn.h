/* Navigation Panel */

// Define
#define STANDARD_NAV_PANEL StandardNavPanel

// ENTER | ESC | KEY_UP | KEY_DOWN
bool StandardNavPanel(char c) {
  return (c == ENTER || c == ESC || c == KEY_UP || c == KEY_DOWN);
}