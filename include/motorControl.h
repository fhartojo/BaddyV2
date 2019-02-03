#ifndef _BADDY_MOTOR_CONTROL_H
#define _BADDY_MOTOR_CONTROL_H

#include <Servo.h>

// Servos instances

extern Servo ShuttleRetainer;
extern Servo ShuttleSwitch;
extern Servo MotorLeft;
extern Servo MotorRight;

// Servo instances End

void servo_fire();
void motorSetup();
void motorStop();
int warmup(int stroke);
void break_motor_right(int outputspeed);
void break_motor_left(int outputspeed);
void break_motor_all(int outputspeed);
int set_stroke(int stroke);
int motor_speed_transition(int type, int next_type);

#endif // _BADDY_MOTOR_CONTROL_H