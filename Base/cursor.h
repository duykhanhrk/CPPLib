/* Cursor */

/* Define */

// Cursor postion
#define CURSOR_POSITION_X CursorPositionX()
#define CURSOR_POSITION_Y CursorPositionY()

// Window rows, columns
#define WINDOW_ROWS WindowRows()
#define WINDOW_COLUMNS WindowColumns()

// Date type
#define position_tp int

/* Prototype */

// Cursor
void GotoXY(int x, int y);
int CursorPositionX();
int CursorPositionY();

// Window
int WindowRows();
int WindowColumns();

/* Logic */

// Goto x, y
void GotoXY(int x, int y) {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursor_position;

	cursor_position.X = x;
	cursor_position.Y = y;
	SetConsoleCursorPosition(console, cursor_position);
}

// Get cursor position x
int CursorPositionX() {
	CONSOLE_SCREEN_BUFFER_INFO console_screen_buffer_info;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &console_screen_buffer_info);

	return console_screen_buffer_info.dwCursorPosition.X;
}

// Get cursor position y
int CursorPositionY() {
	CONSOLE_SCREEN_BUFFER_INFO console_screen_buffer_info;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &console_screen_buffer_info);

	return console_screen_buffer_info.dwCursorPosition.Y;
}

/* Window */

// Get window rows
int WindowRows() {
	CONSOLE_SCREEN_BUFFER_INFO console_screen_buffer_info;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &console_screen_buffer_info);

  return console_screen_buffer_info.srWindow.Bottom - console_screen_buffer_info.srWindow.Top + 1;
}

// Get window columns
int WindowColumns() {
	CONSOLE_SCREEN_BUFFER_INFO console_screen_buffer_info;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &console_screen_buffer_info);

  return console_screen_buffer_info.srWindow.Right - console_screen_buffer_info.srWindow.Left + 1;
}
