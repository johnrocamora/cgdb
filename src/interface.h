/* interface.h:
 * ------------
 * 
 * Provides the routines for displaying the interface, and interacting with
 * the user via keystrokes.
 */

#ifndef _INTERFACE_H_
#define _INTERFACE_H_

/* Local Includes */
#include "sources.h"

/* --------- */
/* Functions */
/* --------- */

/* if_init: Initializes the interface.
 * --------
 *
 * Return Value: Zero on success, or...
 *               1: Initializing curses failed
 *               2: Signal handler install failed
 *               3: Terminal too small
 *               4: Can't create new GDB scroller
 *               5: Can not init the file dialog
 */
int if_init(void);

/* if_input: Handles special input keys from user.
 * ---------
 *
 *   key:  Key code that was received.
 *
 * Return Value:  0 if internal key was used, 
 *                1 if input to gdb,
 *                2 if input to tty or ...
 *                -1        : Error resizing terminal -- terminal too small
 *                -2        : Quit cgdb
 *                KEY_UP    : Send up arrow key to GDB
 *                KEY_DOWN  : Send down arrow key to GDB
 *                KEY_LEFT  : Send left arrow key to GDB
 *                KEY_RIGHT : Send right arrow key to GDB
 */
int if_input(int key);

/* if_print: Prints data to the GDB input/output window.
 * ---------
 *
 *   buf:  NULL-terminated buffer to display.
 */
void if_print(const char *buf);

/* if_tty_print: Prints data to the tty input/output window.
 * -------------
 *
 *   buf:  NULL-terminated buffer to display.
 */
void if_tty_print(const char *buf);

/* if_show_file: Displays the requested file in the source display window.
 * -------------
 *
 *   path:  Full path to the file to display
 *   line:  Current line of the file being executed
 */
void if_show_file(char *path, int line);

/* if_get_sview: Return a pointer to the source viewer object.
 * -------------
 */
struct sviewer *if_get_sview();

/* if_display_message: Displays a message on the source window status bar.
 * -------------------
 *
 * msg:     A message to the user. This will not be truncated unless the width
 *          of the terminal is smaller than this message. 
 *          msg should never be NULL. use "" instead.
 *          
 * width:   The width of the status bar to use up before truncating. 
 *          If width is 0 then if_display_message will assume the whole width
 *          of the terminal.
 *
 * fmt:     The message to display
 */
void if_display_message(const char *msg, int width, const char *fmt, ...);


/* if_clear_filedlg: Clears all the files the file dialog has to show the user.
 * -----------------
 */
void if_clear_filedlg(void);

/* if_add_fildlg_choice: adds the file filename to the choices the user gets.
 * ---------------------
 *
 *  filename: a file the user can choose to open.
 */
void if_add_filedlg_choice(const char *filename);

/* if_show_filedlg: Displays the file dialog to the user.
 * ----------------
 *
 *  filename: An out parameter that is used to show the name of the file that
 *            the user wants to see.
 */
void if_show_filedlg(char *filename);

/* if_filedlg_display_message: Displays a message on the filedlg window status bar.
 * ---------------------------
 *
 * message: The message to display
 */
void if_filedlg_display_message(char *message);

/* if_shutdown: Cleans up, and restores the terminal (shuts off curses).
 * ------------
 */
void if_shutdown(void);

#endif
