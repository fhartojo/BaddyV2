#ifndef _BADDY_PARAMS_H
#define _BADDY_PARAMS_H

///////////////////////////////////////////////////////////////////////////////////
/////////////////////////////CONFIGURATION PARAMETERS - FACTORY SETTINGS //////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

//Warm up, break timer, stop speed, computation timer - modify only if you know what you are doing
int WARM_UP_SPEED=890;
int TRANSITION_SPEED=875;
int TRANSITION_SPEED_HIGH = 990;
int STOP = 750;
int WARM_UP_TIMER = 2000;
int COMPUTATION_TIMER = 600;
int BREAK_TIMER = 500;
int BUDDY_TIMER = 1000; // Timer to synchronize BADDY and BUDDY

// DROP SHOTS
int DROP_LEFT_SHOT_LEFT_MOTOR=910;//950;
int DROP_LEFT_SHOT_RIGHT_MOTOR=843;//860;
int DROP_CENTER_SHOT_LEFT_MOTOR=845;//880;
int DROP_CENTER_SHOT_RIGHT_MOTOR=845;//880;
int DROP_RIGHT_SHOT_LEFT_MOTOR=840;//860;
int DROP_RIGHT_SHOT_RIGHT_MOTOR=910;//950;
//DRIVE SHOTS
int DRIVE_LEFT_SHOT_LEFT_MOTOR=1050;
int DRIVE_LEFT_SHOT_RIGHT_MOTOR=875;
int DRIVE_CENTER_SHOT_LEFT_MOTOR=990;
int DRIVE_CENTER_SHOT_RIGHT_MOTOR=990;
int DRIVE_RIGHT_SHOT_LEFT_MOTOR=875;
int DRIVE_RIGHT_SHOT_RIGHT_MOTOR=1050;
//CLEAR SHOTS
int CLEAR_LEFT_SHOT_LEFT_MOTOR=1300;
int CLEAR_LEFT_SHOT_RIGHT_MOTOR=930;
int CLEAR_CENTER_SHOT_LEFT_MOTOR=1350;
int CLEAR_CENTER_SHOT_RIGHT_MOTOR=1350;
int CLEAR_RIGHT_SHOT_LEFT_MOTOR=930;
int CLEAR_RIGHT_SHOT_RIGHT_MOTOR=1300;

//Switch movement and timers
int SWITCH_LONG_POSITION = 75;
int SWITCH_SHORT_POSITION = 140;
int SWITCH_WAIT_POSITION = 90;
int SWITCH_TIMER = 300;//320 // value in millisecond to wait Switch to fetch its long position
int SWITCH_SPEED=600; // Special speed for slow motion movement (configuration)

// Shuttle retainer movemement and timers
int RETAINER_UP_POSITION = 115;
int RETAINER_DOWN_POSITION = 158;
int RETAINER_TIMER = 160;//150

#endif // _BADDY_PARAMS_H