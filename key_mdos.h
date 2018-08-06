
#ifndef _KEY_MDOS
#define _KEY_MDOS

extern int XOP_KEY;

#define KEY_MODE_LAST 0
#define KEY_MODE_LEFT 1
#define KEY_MODE_RIGHT 2
#define KEY_MODE_STANDARD 3
#define KEY_MODE_PASCAL 4
#define KEY_MODE_BASIC 5
#define KEY_MODE_ABASIC 6
#define KEY_MODE_BREAK 7
#define KEY_MODE_RAW 8

/*
 * Scan the keyboard. Non-blocking. status EQ bit indicates
 * if a new key was pressed. If no key has been pressed >FF is returned.
 *
 * mode - the desired keyboard mode
 * status - location to store scan status
 * returns - last read keycode
 */
unsigned char key_scan(int mode, int* status);

/*
 * Block and wait for a standard mode key press.
 * returns - new keycode.
 */
unsigned char key_getkey();

#endif

