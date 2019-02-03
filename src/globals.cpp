#include <Arduino.h>
#include "params.h"

int baddy_firmware_version = 01;

bool flag_new_sequence = false;
bool station_connected = false;
bool buddy_server_mode = false;
bool buddy_client_connected = false;
String JsonSequence;
String JsonConfigure;
String JsonSpeeds;

//Json Object values:
String type_seq;
int stroke_seq[20];
int stroke_seq_buddy[20];
int speed_seq[20];
int speed_seq_buddy[20];
int loop_mode_seq;
int PlayMode = 0;
int i; //integer that parses the sequence int Array. We make a global value to manage it in the main loop()
int speed;
int flag_first_shot = 1;
int random_id;        // used in random loop
int random_id_next;   //used in random_loop
int stroke_count = 0; //used in random loop
String json_config;   // Needed to expose variable to Rest API
String json_status;
String json_playmode_dump;

bool running_status = false; // boolean flag that indicates if BADDY running or stopped (motors don't spin), initialized with 0
int battery_level;           // Battery level management

/////////////////////////////JSON DOCUMENT FORMAT END//////////////////////////////

/////////////////////////////Statistics counter and functions//////////////////////////////

int COUNTER_DROP_LEFT = 0;
int COUNTER_DROP_CENTER = 0;
int COUNTER_DROP_RIGHT = 0;
int COUNTER_DRIVE_LEFT = 0;
int COUNTER_DRIVE_CENTER = 0;
int COUNTER_DRIVE_RIGHT = 0;
int COUNTER_CLEAR_LEFT = 0;
int COUNTER_CLEAR_CENTER = 0;
int COUNTER_CLEAR_RIGHT = 0;

// Use at Json config object creation
int SpeedProfileInit[18] = {
    DROP_LEFT_SHOT_LEFT_MOTOR
    , DROP_LEFT_SHOT_RIGHT_MOTOR
    , DROP_CENTER_SHOT_LEFT_MOTOR
    , DROP_CENTER_SHOT_RIGHT_MOTOR
    , DROP_RIGHT_SHOT_LEFT_MOTOR
    , DROP_RIGHT_SHOT_RIGHT_MOTOR
    , DRIVE_LEFT_SHOT_LEFT_MOTOR
    , DRIVE_LEFT_SHOT_RIGHT_MOTOR
    , DRIVE_CENTER_SHOT_LEFT_MOTOR
    , DRIVE_CENTER_SHOT_RIGHT_MOTOR
    , DRIVE_RIGHT_SHOT_LEFT_MOTOR
    , DRIVE_RIGHT_SHOT_RIGHT_MOTOR
    , CLEAR_LEFT_SHOT_LEFT_MOTOR
    , CLEAR_LEFT_SHOT_RIGHT_MOTOR
    , CLEAR_CENTER_SHOT_LEFT_MOTOR
    , CLEAR_CENTER_SHOT_RIGHT_MOTOR
    , CLEAR_RIGHT_SHOT_LEFT_MOTOR
    , CLEAR_RIGHT_SHOT_RIGHT_MOTOR
};
int SwitchProfileInit[2] = {
    SWITCH_LONG_POSITION
    , SWITCH_SHORT_POSITION
};
int RetainerProfileInit[2] = {
    RETAINER_UP_POSITION
    , RETAINER_DOWN_POSITION
};
