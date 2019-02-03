#ifndef _BADDY_PARAMS_H
#define _BADDY_PARAMS_H

///////////////////////////////////////////////////////////////////////////////////
/////////////////////////////CONFIGURATION PARAMETERS - FACTORY SETTINGS //////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

//Warm up, break timer, stop speed, computation timer - modify only if you know what you are doing
extern int WARM_UP_SPEED;
extern int TRANSITION_SPEED;
extern int TRANSITION_SPEED_HIGH;
extern int STOP;
extern int WARM_UP_TIMER;
extern int COMPUTATION_TIMER;
extern int BREAK_TIMER;
extern int BUDDY_TIMER; // Timer to synchronize BADDY and BUDDY

// DROP SHOTS
extern int DROP_LEFT_SHOT_LEFT_MOTOR;//950;
extern int DROP_LEFT_SHOT_RIGHT_MOTOR;//860;
extern int DROP_CENTER_SHOT_LEFT_MOTOR;//880;
extern int DROP_CENTER_SHOT_RIGHT_MOTOR;//880;
extern int DROP_RIGHT_SHOT_LEFT_MOTOR;//860;
extern int DROP_RIGHT_SHOT_RIGHT_MOTOR;//950;
//DRIVE SHOTS
extern int DRIVE_LEFT_SHOT_LEFT_MOTOR;
extern int DRIVE_LEFT_SHOT_RIGHT_MOTOR;
extern int DRIVE_CENTER_SHOT_LEFT_MOTOR;
extern int DRIVE_CENTER_SHOT_RIGHT_MOTOR;
extern int DRIVE_RIGHT_SHOT_LEFT_MOTOR;
extern int DRIVE_RIGHT_SHOT_RIGHT_MOTOR;
//CLEAR SHOTS
extern int CLEAR_LEFT_SHOT_LEFT_MOTOR;
extern int CLEAR_LEFT_SHOT_RIGHT_MOTOR;
extern int CLEAR_CENTER_SHOT_LEFT_MOTOR;
extern int CLEAR_CENTER_SHOT_RIGHT_MOTOR;
extern int CLEAR_RIGHT_SHOT_LEFT_MOTOR;
extern int CLEAR_RIGHT_SHOT_RIGHT_MOTOR;

//Switch movement and timers
extern int SWITCH_LONG_POSITION;
extern int SWITCH_SHORT_POSITION;
extern int SWITCH_WAIT_POSITION;
extern int SWITCH_TIMER;//320 // value in millisecond to wait Switch to fetch its long position
extern int SWITCH_SPEED; // Special speed for slow motion movement (configuration)

// Shuttle retainer movemement and timers
extern int RETAINER_UP_POSITION;
extern int RETAINER_DOWN_POSITION;
extern int RETAINER_TIMER;//150

//Wifi related static values for BADDY as a server
extern const char *BADDY_ID;
extern const char *ssid;
extern const char *ssid_buddy;

//const char *ssid = "BADDY-WIFI-TEST";

extern const char *password;

#endif // _BADDY_PARAMS_H