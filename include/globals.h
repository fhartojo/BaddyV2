#ifndef _BADDY_GLOBALS_H
#define _BADDY_GLOBALS_H

#include <Arduino.h>

extern int baddy_firmware_version;

extern bool flag_new_sequence;
extern bool station_connected;
extern bool buddy_server_mode;
extern bool buddy_client_connected;
extern String JsonSequence;
extern String JsonConfigure;
extern String JsonSpeeds;

//Json Object values:
extern String type_seq;
extern int stroke_seq[];
extern int stroke_seq_buddy[];
extern int speed_seq[];
extern int speed_seq_buddy[];
extern int loop_mode_seq;
extern int PlayMode;
extern int i; //integer that parses the sequence int Array. We make a global value to manage it in the main loop()
extern int speed;
extern int flag_first_shot;
extern int random_id;        // used in random loop
extern int random_id_next;   //used in random_loop
extern int stroke_count; //used in random loop
extern String json_config;   // Needed to expose variable to Rest API
extern String json_status;
extern String json_playmode_dump;

extern bool running_status; // boolean flag that indicates if BADDY running or stopped (motors don't spin), initialized with 0
extern int battery_level;           // Battery level management

/////////////////////////////JSON DOCUMENT FORMAT END//////////////////////////////

/////////////////////////////Statistics counter and functions//////////////////////////////

extern int COUNTER_DROP_LEFT;
extern int COUNTER_DROP_CENTER;
extern int COUNTER_DROP_RIGHT;
extern int COUNTER_DRIVE_LEFT;
extern int COUNTER_DRIVE_CENTER;
extern int COUNTER_DRIVE_RIGHT;
extern int COUNTER_CLEAR_LEFT;
extern int COUNTER_CLEAR_CENTER;
extern int COUNTER_CLEAR_RIGHT;

// Use at Json config object creation
extern int SpeedProfileInit[];
extern int SwitchProfileInit[];
extern int RetainerProfileInit[];

#endif // _BADDY_GLOBALS_H