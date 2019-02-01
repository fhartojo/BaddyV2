#ifndef _BADDY_LED_DISPLAY_H
#define _BADDY_LED_DISPLAY_H

#include <Arduino.h>

void ledSetup();
void printByte(byte character []);
void printLevels();
void printSquares();
void printSmiley();
void printFrown();

#endif // _BADDY_LED_DISPLAY_H