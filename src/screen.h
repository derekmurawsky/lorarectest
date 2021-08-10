/**
 * @file screen.h
 * @brief Screen related helper functions
 * Many bits of this code were pulled from the Heltec library
 */
#include "string.h"

/**
 * @brief Powers up and initializes the OLED display
 * This function powers up the display, flips it vertically, and sets the font
 * (ArialMT, plain, 10pt)
 */
void displayInit();

/**
 * @brief This function attempts to display as much of a long string as is
 * possible
 *
 * This function parses out a string and attempts to print as much as the screen
 * will support. I'm sure there is a better way to do this, but I have no idea
 * how, so this will have to do.
 *
 * @param toDisplay The String to display
 */
void displayLongString(char *toDisplay);