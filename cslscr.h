/* Console Screen */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <windows.h>

/* Define */

// Data type
#define position_tp int
#define color_tp int
#define size_tp int

// Key code
// Keys
#define ENTER 13
#define ESC 27
#define BACKSPACE 8
#define KEY_UP -1
#define KEY_DOWN -2
#define KEY_LEFT -3
#define KEY_RIGHT -4

// Utilities
#define SavePositionContext position_tp __current_position_x__ = CURRENT_CURSOR_POSITION_X; \
                            position_tp __current_position_y__ = CURRENT_CURSOR_POSITION_Y

#define ApplyPositionContext GotoXY(__current_position_x__, __current_position_y__)

#define SaveColorContext color_tp __current_foreground__ = CURRENT_FOREGROUND; \
                         color_tp __current_background__ = CURRENT_BACKGROUND

#define ApplyColorContext SetColor(__current_foreground__, __current_background__)

#define SaveContext SavePositionContext; \
                    SaveColorContext

#define ApplyContext ApplyPositionContext; \
                     ApplyColorContext


#define ApplyPositionContextArgument GotoXY(position_x, position_y)

#define ApplyColorContextArgument SetColor(f_color, b_color)

#define ApplyContextArguments ApplyPositionContextArgument; \
                              ApplyColorContextArgument

#define InitStash position_tp __stash_postion_x__; \
                  position_tp __stash_postion_y__; \
                  color_tp __stash_b_color__; \
                  color_tp __stash_f_color__;

#define SaveStash position_tp __stash_postion_x__ = CURRENT_CURSOR_POSITION_X; \
                  position_tp __stash_postion_y__ = CURRENT_CURSOR_POSITION_Y; \
                  color_tp __stash_b_color__ = CURRENT_BACKGROUND; \
                  color_tp __stash_f_color__ = CURRENT_FOREGROUND

#define ApplyStash GotoXY(__stash_postion_x__, __stash_postion_y__); \
                   SetColor(__stash_f_color__, __stash_b_color__)

#define IsNumericChar(c) (c >= 48 && c <= 57)
#define IsLowercaseChar(c) (c >= 97 && c<= 122)
#define IsUppercaseChar(c) (c >= 65 && c <= 90)
#define IsAlphabeticChar(c) (IsLowercaseChar(c) || IsUppercaseChar(c))
#define IsSpace(c) (c == 32)
#define IsUnderscore(c) (c == 95)

#define NumViolatesMaxValue(num, c, max) ((max - num < max - max/10) || (max - num == max - max/10 && CharToNumber(c) > max%10))
#define NumViolatesMinValue(num, c, min) ((min - obj > min - min/10) || (min - obj == min - min/10 && 48 - c < min%10))

#define CharToInt(c) (c - 48)

/* include cslscr feature */

#include "color.h"
#include "cursor.h"
#include "print.h"
#include "input.h"
