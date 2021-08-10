/**
 * @file screen.cpp
 * @brief Screen related helper functions
 * Many bits of this code were pulled from the Heltec library
 */
#include "screen.h"
#include "defines.h"
#include "oled/SSD1306Wire.h"
SSD1306Wire *display =
    new SSD1306Wire(0x3c, SDA_OLED, SCL_OLED, RST_OLED, GEOMETRY_128_64);
; /* The OLED display object */

/**
 * @brief Powers up and initializes the OLED display
 * This function powers up the display, flips it vertically, and sets the font
 * (ArialMT, plain, 10pt)
 */
void displayInit() {
  display->init();
  display->flipScreenVertically();
  display->setFont(ArialMT_Plain_10);
  display->display();
}

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
void displayLongString(char *toDisplay) {
  display->clear();
  display->drawStringMaxWidth(0, 0, display->getWidth(), toDisplay);
  display->display();
}