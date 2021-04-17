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
#define visible_tp bool
#define void_tp void*
#define str_tp char*
#define uh_tp unsigned short int
#define ui_tp unsigned int
#define ul_tp unsigned long long int
#define h_tp short int
#define i_tp int
#define l_tp long long int

// Key code
// Keys
#define ENTER 13
#define ESC 27
#define BACKSPACE 8
#define KEY_UP -1
#define KEY_DOWN -2
#define KEY_LEFT -3
#define KEY_RIGHT -4

/* Utilities */

// Context
#define SaveCursorPositionContext position_tp __cursor_position_x__ = CURSOR_POSITION_X; \
                                  position_tp __cursor_position_y__ = CURSOR_POSITION_Y

#define ApplyCursorPositionContext GotoXY(__cursor_position_x__, __cursor_position_y__)

#define SaveCursorVisibleContext bool __cursor_visible__ = CURSOR_VISIBLE

#define ApplyCursorVisibleContext CursorVisible(__cursor_visible__)

#define SaveColorContext color_tp __current_foreground__ = CURRENT_FOREGROUND; \
                         color_tp __current_background__ = CURRENT_BACKGROUND

#define ApplyColorContext SetColor(__current_foreground__, __current_background__)

#define SaveContext SaveCursorPositionContext; \
                    SaveColorContext; \
                    SaveCursorVisibleContext

#define ApplyContext ApplyCursorPositionContext; \
                     ApplyColorContext; \
                     ApplyCursorVisibleContext


#define ApplyCursorPositionContextArgument GotoXY(position_x, position_y)

#define ApplyColorContextArgument SetColor(f_color, b_color)

#define ApplyContextArguments ApplyCursorPositionContextArgument; \
                              ApplyColorContextArgument

// Stash
#define InitStash position_tp __stash_postion_x__; \
                  position_tp __stash_postion_y__; \
                  color_tp __stash_b_color__; \
                  color_tp __stash_f_color__; \
                  visible_tp __stash_cursor_visible__;

#define SaveStash __stash_postion_x__ = CURSOR_POSITION_X; \
                  __stash_postion_y__ = CURSOR_POSITION_Y; \
                  __stash_b_color__ = CURRENT_BACKGROUND; \
                  __stash_f_color__ = CURRENT_FOREGROUND; \
                  __stash_cursor_visible__ = CURSOR_VISIBLE

#define ApplyStash GotoXY(__stash_postion_x__, __stash_postion_y__); \
                   SetColor(__stash_f_color__, __stash_b_color__); \
                   CursorVisible(__stash_cursor_visible__)

// Common
#define IsNumericChar(c) (c >= 48 && c <= 57)
#define IsLowercaseChar(c) (c >= 97 && c<= 122)
#define IsUppercaseChar(c) (c >= 65 && c <= 90)
#define IsAlphabeticChar(c) (IsLowercaseChar(c) || IsUppercaseChar(c))
#define IsSpace(c) (c == 32)
#define IsUnderscore(c) (c == 95)
#define CharToInt(c) (c - 48)
#define VoidTypeToUShort(obj) (*((uh_tp *) obj))
#define VoidTypeToUInt(obj) (*((ui_tp *) obj))
#define VoidTypeToULong(obj) (*((ul_tp *) obj))
#define VoidTypeToShort(obj) (*((h_tp *) obj))
#define VoidTypeToInt(obj) (*((i_tp *) obj))
#define VoidTypeToLong(obj) (*((l_tp *) obj))
#define NumViolatesMaxValue(num, c, max) ((max - num < max - max/10) || (max - num == max - max/10 && CharToInt(c) > max%10))
#define NumViolatesMinValue(num, c, min) ((min - obj > min - min/10) || (min - obj == min - min/10 && 48 - c < min%10))


#define CharToInt(c) (c - 48)

/* include cslscr feature */

#include "context/color.h"
#include "context/cursor.h"
#include "print/print.h"
#include "input/input.h"
