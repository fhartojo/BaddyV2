#ifndef _BADDY_CONSTANTS_H
#define _BADDY_CONSTANTS_H
// ESP Pin configurations

#define LED_DIN D2
#define LED_CS D1
#define LED_CLK D3
#define MOTOR_RIGHT_PIN D5
#define MOTOR_LEFT_PIN D7
#define SHUTTLE_SWITCH_PIN D6
#define SHUTTLE_RETAINER_PIN D8
//In case you want to use the EXT pin header for your Retainer servo motor, comment the line above and uncomment the line just below 
// #define SHUTTLE_RETAINER_PIN D0 
#define ANALOG_READ_BATTERY A0

// ESP Pin configurations end

#define BADDY_CONFIG_FILENAME "/BADDY_CONFIG_FILE"
#endif // _BADDY_CONSTANTS_H