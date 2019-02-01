// Led management instances and objects

#include <Arduino.h>
#include <LedControl.h>
#include "constants.h"
#include "ledDisplay.h"

int refresh_period_square = 100;
int refresh_period_level = 40;
int refresh_period_smiley = 1000;

byte level8[8] = {B11111111, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000};
byte level7[8] = {B11111111, B11111111, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000};
byte level6[8] = {B11111111, B11111111, B11111111, B00000000, B00000000, B00000000, B00000000, B00000000};
byte level5[8] = {B11111111, B11111111, B11111111, B11111111, B00000000, B00000000, B00000000, B00000000};
byte level4[8] = {B11111111, B11111111, B11111111, B11111111, B11111111, B00000000, B00000000, B00000000};
byte level3[8] = {B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B00000000, B00000000};
byte level2[8] = {B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B00000000};
byte level1[8] = {B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111};

byte square1[8] = {B00000000, B00000000, B00000000, B00011000, B00011000, B00000000, B00000000, B00000000};
byte square2[8] = {B00000000, B00000000, B00111100, B00100100, B00100100, B00111100, B00000000, B00000000};
byte square3[8] = {B00000000, B01111110, B01000010, B01000010, B01000010, B01000010, B01111110, B00000000};
byte square4[8] = {B11111111, B10000001, B10000001, B10000001, B10000001, B10000001, B10000001, B11111111};

byte smile[8] = {B00010000, B00100110, B01000110, B01000000, B01000000, B01000110, B00100110, B00010000};
byte frown[8] = {B01000000, B00100110, B00010110, B00010000, B00010000, B00010110, B00100110, B01000000};

LedControl lc = LedControl(LED_DIN, LED_CLK, LED_CS, 0);

// Led management instances end

// Functions for Led display
//Functions for LED forms display

void ledSetup()
{
    // Led display Set up

    // Led set up and ready for pairing
    lc.shutdown(0, false); //The MAX72XX is in power-saving mode on startup
    lc.setIntensity(0, 2); // Set the brightness to average value
    lc.clearDisplay(0);    // and clear the display
    printLevels();
    lc.clearDisplay(0); // and clear the display

    // Led display set up end
}

void printByte(byte character[])
{
    int i = 0;
    for (i = 0; i < 8; i++)
    {
        lc.setRow(0, i, character[i]);
    }
}

void printLevels()
{
    printByte(level8);
    delay(refresh_period_level);
    printByte(level7);
    delay(refresh_period_level);
    printByte(level6);
    delay(refresh_period_level);
    printByte(level5);
    delay(refresh_period_level);
    printByte(level4);
    delay(refresh_period_level);
    printByte(level3);
    delay(refresh_period_level);
    printByte(level2);
    delay(refresh_period_level);
    printByte(level1);
    delay(refresh_period_level);
    printByte(level2);
    delay(refresh_period_level);
    printByte(level3);
    delay(refresh_period_level);
    printByte(level4);
    delay(refresh_period_level);
    printByte(level5);
    delay(refresh_period_level);
    printByte(level6);
    delay(refresh_period_level);
    printByte(level7);
    delay(refresh_period_level);
    printByte(level8);
    delay(refresh_period_level);
    lc.clearDisplay(0); // clear the display
}

void printSquares()
{

    printByte(square1);
    delay(refresh_period_square);
    printByte(square2);
    delay(refresh_period_square);
    printByte(square3);
    delay(refresh_period_square);
    printByte(square4);
    delay(refresh_period_square);
    printByte(square3);
    delay(refresh_period_square);
    printByte(square2);
    delay(refresh_period_square);
    printByte(square1);
    delay(refresh_period_square);
    lc.clearDisplay(0); // clear the display
}

void printSmiley()
{

    printByte(smile);
    delay(refresh_period_smiley);
    lc.clearDisplay(0); // clear the display
}

void printFrown()
{

    printByte(frown);
    delay(refresh_period_smiley);
    lc.clearDisplay(0); // and clear the display
}
// End of functions for Led display
