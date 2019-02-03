#include "constants.h"
#include "params.h"
#include "globals.h"
#include "motorControl.h"
#include <Servo.h>

// Servos instances

Servo ShuttleRetainer;
Servo ShuttleSwitch;
Servo MotorLeft;
Servo MotorRight;

// Servo instances End


// Servo functions

void servo_fire()
{

    ShuttleRetainer.write(RETAINER_UP_POSITION);
    delay(RETAINER_TIMER);

    ShuttleSwitch.write(SWITCH_LONG_POSITION);
    delay(SWITCH_TIMER);

    ShuttleSwitch.write(SWITCH_SHORT_POSITION);
    delay(SWITCH_TIMER);
    ShuttleRetainer.write(RETAINER_DOWN_POSITION);

    delay(RETAINER_TIMER); // Just in case
}

// Servo functions end

void motorSetup()
{
    // Motor pins allocation
    MotorRight.attach(MOTOR_RIGHT_PIN);
    MotorRight.writeMicroseconds(STOP);
    MotorLeft.attach(MOTOR_LEFT_PIN);
    MotorLeft.writeMicroseconds(STOP);

    ShuttleSwitch.attach(SHUTTLE_SWITCH_PIN);
    ShuttleSwitch.write(SWITCH_SHORT_POSITION);
    ShuttleRetainer.attach(SHUTTLE_RETAINER_PIN);
    ShuttleRetainer.write(RETAINER_DOWN_POSITION);
    // Motor pins allocation end
}

void motorStop()
{
    MotorLeft.writeMicroseconds(STOP);
    MotorRight.writeMicroseconds(STOP);
}

int warmup(int stroke)
{
    if (stroke == 1)
    {
        Serial.println("Drop left shot speed command sent to motor");
        MotorLeft.writeMicroseconds(DROP_LEFT_SHOT_LEFT_MOTOR);
        MotorRight.writeMicroseconds(DROP_LEFT_SHOT_RIGHT_MOTOR);
    }
    else if (stroke == 2)
    {
        Serial.println("Drop Center shot speed command sent to motor");
        MotorLeft.writeMicroseconds(DROP_CENTER_SHOT_LEFT_MOTOR);
        MotorRight.writeMicroseconds(DROP_CENTER_SHOT_RIGHT_MOTOR);
    }
    else if (stroke == 3)
    {
        Serial.println("Drop Right shot speed command sent to motor");
        MotorLeft.writeMicroseconds(DROP_RIGHT_SHOT_LEFT_MOTOR);
        MotorRight.writeMicroseconds(DROP_RIGHT_SHOT_RIGHT_MOTOR);
    }
    else if (stroke == 4)
    {
        Serial.println("Drive Left shot speed command sent to motor");
        MotorLeft.writeMicroseconds(DRIVE_LEFT_SHOT_LEFT_MOTOR);
        MotorRight.writeMicroseconds(DRIVE_LEFT_SHOT_RIGHT_MOTOR);
    }
    else if (stroke == 5)
    {
        Serial.println("Drive Center shot speed command sent to motor");
        MotorLeft.writeMicroseconds(DRIVE_CENTER_SHOT_LEFT_MOTOR);
        MotorRight.writeMicroseconds(DRIVE_CENTER_SHOT_RIGHT_MOTOR);
    }
    else if (stroke == 6)
    {
        Serial.println("Drive Right shot speed command sent to motor");
        MotorLeft.writeMicroseconds(DRIVE_RIGHT_SHOT_LEFT_MOTOR);
        MotorRight.writeMicroseconds(DRIVE_RIGHT_SHOT_RIGHT_MOTOR);
    }
    else if (stroke == 7)
    {
        Serial.println("Clear Left shot speed command sent to motor");
        MotorLeft.writeMicroseconds(CLEAR_LEFT_SHOT_LEFT_MOTOR);
        MotorRight.writeMicroseconds(CLEAR_LEFT_SHOT_RIGHT_MOTOR);
    }
    else if (stroke == 8)
    {
        Serial.println("Clear Center shot speed command sent to motor");

        // Special trick to handle potential battery cut off
        MotorLeft.writeMicroseconds(1300);
        MotorRight.writeMicroseconds(1300);
        delay(130);
        //End of special trick
        MotorLeft.writeMicroseconds(CLEAR_CENTER_SHOT_LEFT_MOTOR);
        MotorRight.writeMicroseconds(CLEAR_CENTER_SHOT_RIGHT_MOTOR);
    }
    else if (stroke == 9)
    {
        Serial.println("Clear Center shot speed command sent to motor");
        MotorLeft.writeMicroseconds(CLEAR_RIGHT_SHOT_LEFT_MOTOR);
        MotorRight.writeMicroseconds(CLEAR_RIGHT_SHOT_RIGHT_MOTOR);
    }

    if (buddy_server_mode)
    {
        delay(1000);
        Serial.println("We wait 1 sec to sync with BADDY master...");
    }
    else
    {
        delay(2000);
    }
    // We wait 2 sec so that motor gets nominal speed - important at start up especially for drop shots
    return 1;
}

void break_motor_right(int outputspeed)
{

    //Break
    Serial.println("Break Right Motor");
    MotorRight.writeMicroseconds(STOP);
    delay(210);
    //Restart at idle low speed
    //Serial.println("Acceleration");
    MotorRight.writeMicroseconds(1700);
    delay(270);
    //Serial.println("Normal cruise");
    MotorRight.writeMicroseconds(outputspeed);
}

void break_motor_left(int outputspeed)
{
    //Break
    Serial.println("Break Left Motor");
    MotorLeft.writeMicroseconds(STOP);
    delay(210);
    //Restart at idle low speed
    //Serial.println("Acceleration");
    MotorLeft.writeMicroseconds(1700);
    delay(270);
    //Serial.println("Normal cruise");
    MotorLeft.writeMicroseconds(outputspeed);
}

void break_motor_all(int outputspeed)
{

    Serial.println("Break all Motors");
    motorStop();
    delay(210);
    //Restart at idle low speed
    //Serial.println("Acceleration");
    MotorLeft.writeMicroseconds(1300);
    MotorRight.writeMicroseconds(1300);
    delay(270);
    //Serial.println("Normal cruise all motors");
    MotorLeft.writeMicroseconds(outputspeed);
    MotorRight.writeMicroseconds(outputspeed);
}

int set_stroke(int stroke)
{
    if (stroke == 1)
    {
        Serial.println("Drop left shot speed command sent to motor");
        MotorLeft.writeMicroseconds(DROP_LEFT_SHOT_LEFT_MOTOR);
        MotorRight.writeMicroseconds(DROP_LEFT_SHOT_RIGHT_MOTOR);
        if (PlayMode == 2)
        {
            COUNTER_DROP_CENTER++;
        }
        else
        {
            COUNTER_DROP_LEFT++;
        }
    }
    else if (stroke == 2)
    {
        Serial.println("Drop Center shot speed command sent to motor");
        MotorLeft.writeMicroseconds(DROP_CENTER_SHOT_LEFT_MOTOR);
        MotorRight.writeMicroseconds(DROP_CENTER_SHOT_RIGHT_MOTOR);
        if (PlayMode == 2)
        {
            COUNTER_DROP_RIGHT++;
        }
        else
        {
            COUNTER_DROP_CENTER++;
        }
    }
    else if (stroke == 3)
    {
        Serial.println("Drop Right shot speed command sent to motor");
        MotorLeft.writeMicroseconds(DROP_RIGHT_SHOT_LEFT_MOTOR);
        MotorRight.writeMicroseconds(DROP_RIGHT_SHOT_RIGHT_MOTOR);
        COUNTER_DROP_RIGHT++;
        // Stroke not used in BADDY BUDDY mode
    }
    else if (stroke == 4)
    {
        Serial.println("Drive Left shot speed command sent to motor");
        MotorLeft.writeMicroseconds(DRIVE_LEFT_SHOT_LEFT_MOTOR);
        MotorRight.writeMicroseconds(DRIVE_LEFT_SHOT_RIGHT_MOTOR);
        if (PlayMode == 2)
        {
            COUNTER_DRIVE_CENTER++;
        }
        else
        {
            COUNTER_DRIVE_LEFT++;
        }
    }
    else if (stroke == 5)
    {
        Serial.println("Drive Center shot speed command sent to motor");
        MotorLeft.writeMicroseconds(DRIVE_CENTER_SHOT_LEFT_MOTOR);
        MotorRight.writeMicroseconds(DRIVE_CENTER_SHOT_RIGHT_MOTOR);
        if (PlayMode == 2)
        {
            COUNTER_DRIVE_RIGHT++;
        }
        else
        {
            COUNTER_DRIVE_CENTER++;
        }
    }
    else if (stroke == 6)
    {
        Serial.println("Drive Right shot speed command sent to motor");
        MotorLeft.writeMicroseconds(DRIVE_RIGHT_SHOT_LEFT_MOTOR);
        MotorRight.writeMicroseconds(DRIVE_RIGHT_SHOT_RIGHT_MOTOR);
        COUNTER_DRIVE_RIGHT++;
        // Stroke not used in BADDY BUDDY mode
    }
    else if (stroke == 7)
    {
        Serial.println("Clear Left shot speed command sent to motor");
        MotorLeft.writeMicroseconds(CLEAR_LEFT_SHOT_LEFT_MOTOR);
        MotorRight.writeMicroseconds(CLEAR_LEFT_SHOT_RIGHT_MOTOR);
        if (PlayMode == 2)
        {
            COUNTER_CLEAR_CENTER++;
        }
        else
        {
            COUNTER_CLEAR_LEFT++;
        }
    }
    else if (stroke == 8)
    {
        Serial.println("Clear Center shot speed command sent to motor");
        // Special trick to handle potential battery cut off
        MotorLeft.writeMicroseconds(1300);
        MotorRight.writeMicroseconds(1300);
        delay(130);
        //End of special trick

        MotorLeft.writeMicroseconds(CLEAR_CENTER_SHOT_LEFT_MOTOR);
        MotorRight.writeMicroseconds(CLEAR_CENTER_SHOT_RIGHT_MOTOR);
        if (PlayMode == 2)
        {
            COUNTER_CLEAR_RIGHT++;
        }
        else
        {
            COUNTER_CLEAR_CENTER++;
        }
    }
    else if (stroke == 9)
    {
        Serial.println("Clear Center shot speed command sent to motor");
        MotorLeft.writeMicroseconds(CLEAR_RIGHT_SHOT_LEFT_MOTOR);
        MotorRight.writeMicroseconds(CLEAR_RIGHT_SHOT_RIGHT_MOTOR);
        COUNTER_CLEAR_RIGHT++;
        // Stroke not used in BADDY BUDDY mode
    }
    else if (stroke > 10) // Only in BADDY BUDDY mode
    {
        if (stroke == 11)
        {
            COUNTER_DROP_LEFT++;
        }
        else if (stroke == 12)
        {
            COUNTER_DROP_CENTER++;
        }
        else if (stroke == 13)
        {
            COUNTER_DROP_RIGHT++;
        }
        else if (stroke == 14)
        {
            COUNTER_DRIVE_LEFT++;
        }
        else if (stroke == 15)
        {
            COUNTER_DRIVE_CENTER++;
        }
        else if (stroke == 16)
        {
            COUNTER_DRIVE_RIGHT++;
        }
        else if (stroke == 17)
        {
            COUNTER_CLEAR_LEFT++;
        }
        else if (stroke == 18)
        {
            COUNTER_CLEAR_CENTER++;
        }
        else if (stroke == 19)
        {
            COUNTER_CLEAR_RIGHT++;
        }
        Serial.println("Idle Speed set");
        MotorLeft.writeMicroseconds(900);
        MotorRight.writeMicroseconds(900);
    }
    return 1;
}

int motor_speed_transition(int type, int next_type)
{
    // Manage motor speed transitions, to avoid getting too much speed when switching from clear shot to drop
    // Manage transitions from drop shot to clear shot!
    // Left and right transitions as well
    // That's BADDY's trickiest part - shapped with experience and iterative approach. Propose your own parameters!

    if (type == next_type)
    {
        return 0;
    }

    if (next_type > 10)
    {
        MotorRight.writeMicroseconds(860); // setting an idle speed
        MotorRight.writeMicroseconds(860); // setting an idle speed
        return 0;
    }

    if (((type == 1) || (type == 2) || (type > 10)) && ((next_type == 3)))
    {
        // Preferable to break in case if Drop Left and right sequence, to ensure excentricity
        break_motor_left(DROP_RIGHT_SHOT_LEFT_MOTOR);
        //MotorLeft.writeMicroseconds(DROP_RIGHT_SHOT_LEFT_MOTOR);
        MotorRight.writeMicroseconds(1250); // Well, we need to accelerate a bit more with more heavy duty wheels
        delay(80);
        MotorRight.writeMicroseconds(DROP_RIGHT_SHOT_RIGHT_MOTOR); //Adjustement trick to faster make ESC get nominal speed
        return 480;
    }
    // That's BADDY's trickiest part - shapped with experience and iterative approach. Propose your own parameters!

    if (next_type == 10)
    {
        MotorRight.writeMicroseconds(860); // setting an idle speed
        MotorRight.writeMicroseconds(860); // setting an idle speed
        return 0;
    }

    if (((type == 1) || (type == 2) || (type > 10)) && ((next_type == 3)))
    {
        // Preferable to break in case if Drop Left and right sequence, to ensure excentricity
        break_motor_left(DROP_RIGHT_SHOT_LEFT_MOTOR);
        //MotorLeft.writeMicroseconds(DROP_RIGHT_SHOT_LEFT_MOTOR);
        MotorRight.writeMicroseconds(1250); // Well, we need to accelerate a bit more with more heavy duty wheels
        delay(80);
        MotorRight.writeMicroseconds(DROP_RIGHT_SHOT_RIGHT_MOTOR); //Adjustement trick to faster make ESC get nominal speed
        return 480;
    }

    if (((type == 2) || (type == 3) || (type > 10)) && ((next_type == 1)))
    {
        MotorLeft.writeMicroseconds(1250); // Well, we need more acceleration to accomodate heavy duty wheels
        delay(80);
        MotorLeft.writeMicroseconds(DROP_LEFT_SHOT_LEFT_MOTOR); //Adjustement trick to faster make ESC get nominal speed
        break_motor_right(DROP_LEFT_SHOT_RIGHT_MOTOR);
        //MotorRight.writeMicroseconds(DROP_LEFT_SHOT_RIGHT_MOTOR);
        return 480;
    }
    // New, manage transitions from drop to clear shot

    if (((type == 1) || (type == 2) || (type == 3) || (type > 10)) && ((next_type == 4)))
    {

        MotorLeft.writeMicroseconds(DRIVE_LEFT_SHOT_LEFT_MOTOR);
        MotorRight.writeMicroseconds(DRIVE_LEFT_SHOT_RIGHT_MOTOR);
        return 0;
    }

    if (((type == 1) || (type == 2) || (type == 3) || (type > 10)) && ((next_type == 5)))
    {
        MotorLeft.writeMicroseconds(DRIVE_CENTER_SHOT_LEFT_MOTOR);
        MotorRight.writeMicroseconds(DRIVE_CENTER_SHOT_RIGHT_MOTOR);
        return 0;
    }

    if (((type == 1) || (type == 2) || (type == 3) || (type > 10)) && ((next_type == 6)))
    {
        MotorLeft.writeMicroseconds(DRIVE_RIGHT_SHOT_LEFT_MOTOR);
        MotorRight.writeMicroseconds(DRIVE_RIGHT_SHOT_RIGHT_MOTOR);
        return 0;
    }

    if (((type == 1) || (type == 2) || (type == 3) || (type > 10)) && ((next_type == 7)))
    {
        MotorLeft.writeMicroseconds(CLEAR_LEFT_SHOT_LEFT_MOTOR);
        MotorRight.writeMicroseconds(CLEAR_LEFT_SHOT_RIGHT_MOTOR);
        return 0;
    }

    if (((type == 1) || (type == 2) || (type == 3) || (type > 10)) && ((next_type == 8)))
    {

        Serial.println("Transitioning from drop to clear, with a gradual spin up");
        // Special trick to handle potential battery cut off
        MotorLeft.writeMicroseconds(1150);
        MotorRight.writeMicroseconds(1150);
        delay(200);
        MotorLeft.writeMicroseconds(1200);
        MotorRight.writeMicroseconds(1200);
        delay(200);
        MotorLeft.writeMicroseconds(1250);
        MotorRight.writeMicroseconds(1250);
        delay(200);
        MotorLeft.writeMicroseconds(1300);
        MotorRight.writeMicroseconds(1300);
        delay(200);
        //End of special trick

        MotorLeft.writeMicroseconds(CLEAR_CENTER_SHOT_LEFT_MOTOR);
        MotorRight.writeMicroseconds(CLEAR_CENTER_SHOT_RIGHT_MOTOR);
        return 600;
    }

    if (((type == 1) || (type == 2) || (type == 3) || (type > 10)) && ((next_type == 9)))
    {
        MotorLeft.writeMicroseconds(CLEAR_RIGHT_SHOT_LEFT_MOTOR);
        MotorRight.writeMicroseconds(CLEAR_RIGHT_SHOT_RIGHT_MOTOR);
        return 0;
    }
    // End manage transitions from drop to clear

    if (type > 3)
    {
        if (next_type == 1)
        {
            if ((type == 4) && (type == 5))
            {
                MotorLeft.writeMicroseconds(TRANSITION_SPEED);
                break_motor_right(DROP_LEFT_SHOT_RIGHT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
            if (type == 6)
            {
                MotorLeft.writeMicroseconds(DROP_LEFT_SHOT_LEFT_MOTOR);
                break_motor_right(DROP_LEFT_SHOT_RIGHT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
            if (type == 7)
            {
                break_motor_left(DROP_LEFT_SHOT_LEFT_MOTOR + 50);
                break_motor_right(DROP_LEFT_SHOT_RIGHT_MOTOR); // Trick to fetch motor's speed faster (accomodate ESC potential lack reactivity/wheels intertia)
                return (480);                                  // we deduce by the time needed to break
            }
            if (type == 8)
            {
                break_motor_left(DROP_LEFT_SHOT_LEFT_MOTOR + 50);
                break_motor_right(DROP_LEFT_SHOT_RIGHT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
            if (type == 9)
                ;
            {
                break_motor_left(DROP_LEFT_SHOT_LEFT_MOTOR + 50);
                break_motor_right(DROP_LEFT_SHOT_RIGHT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
        }
        else if (next_type == 2)
        {
            if (type == 4)
            {
                break_motor_left(DROP_CENTER_SHOT_LEFT_MOTOR);
                MotorRight.writeMicroseconds(DROP_CENTER_SHOT_RIGHT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
            if (type == 5)
            {
                break_motor_all(DROP_CENTER_SHOT_RIGHT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
            if (type == 6)
            {
                MotorLeft.writeMicroseconds(DROP_CENTER_SHOT_LEFT_MOTOR);
                break_motor_right(DROP_CENTER_SHOT_RIGHT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
            if (type == 7)
            {
                break_motor_all(DROP_CENTER_SHOT_RIGHT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
            if (type == 8)
            {
                break_motor_all(DROP_CENTER_SHOT_RIGHT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
            if (type == 9)
                ;
            {
                break_motor_all(DROP_CENTER_SHOT_RIGHT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
        }
        else if (next_type == 3)
        {
            if (type == 4)
            {
                break_motor_left(DROP_RIGHT_SHOT_LEFT_MOTOR);
                MotorRight.writeMicroseconds(DROP_RIGHT_SHOT_RIGHT_MOTOR + 50);
                return (480); // we deduce by the time needed to break
            }
            if (type == 5)
            {
                MotorRight.writeMicroseconds(DROP_RIGHT_SHOT_RIGHT_MOTOR + 50);
                break_motor_left(DROP_RIGHT_SHOT_LEFT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
            if (type == 6)
            {
                MotorLeft.writeMicroseconds(DROP_RIGHT_SHOT_LEFT_MOTOR + 50);
                break_motor_right(DROP_RIGHT_SHOT_RIGHT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
            if (type == 7)
            {
                break_motor_left(DROP_RIGHT_SHOT_LEFT_MOTOR); // ESC trick
                break_motor_right(DROP_RIGHT_SHOT_RIGHT_MOTOR + 50);
                return (480); // we deduce by the time needed to break
            }
            if (type == 8)
            {
                break_motor_left(DROP_RIGHT_SHOT_LEFT_MOTOR);
                break_motor_right(DROP_RIGHT_SHOT_RIGHT_MOTOR + 50);
                return (480); // we deduce by the time needed to break
            }
            if (type == 9)
                ;
            {
                break_motor_left(DROP_RIGHT_SHOT_LEFT_MOTOR);
                break_motor_right(DROP_RIGHT_SHOT_RIGHT_MOTOR + 50);
                return (480); // we deduce by the time needed to break
            }
        }
        else if (next_type == 4)
        {

            if (type == 5)
            {
                MotorLeft.writeMicroseconds(DRIVE_LEFT_SHOT_LEFT_MOTOR);
                break_motor_right(DRIVE_LEFT_SHOT_RIGHT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
            else if (type == 6)
            {
                MotorLeft.writeMicroseconds(DRIVE_LEFT_SHOT_LEFT_MOTOR);
                break_motor_right(DRIVE_LEFT_SHOT_RIGHT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
            else if (type == 7)
            {
                MotorRight.writeMicroseconds(DRIVE_LEFT_SHOT_RIGHT_MOTOR);
                MotorLeft.writeMicroseconds(DRIVE_LEFT_SHOT_LEFT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
            else if (type == 8)
            {
                MotorLeft.writeMicroseconds(DRIVE_LEFT_SHOT_LEFT_MOTOR);
                break_motor_right(DRIVE_LEFT_SHOT_RIGHT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
            else if (type == 9)
            {
                MotorLeft.writeMicroseconds(DRIVE_LEFT_SHOT_LEFT_MOTOR);
                break_motor_right(DRIVE_LEFT_SHOT_RIGHT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
            else
            {
                MotorRight.writeMicroseconds(TRANSITION_SPEED); // Restart motor
                MotorLeft.writeMicroseconds(TRANSITION_SPEED);  // Restart motor
                return (0);
            }
        }
        else if (next_type == 5)
        {
            if (type == 6)
            {
                MotorLeft.writeMicroseconds(DRIVE_CENTER_SHOT_LEFT_MOTOR);
                break_motor_right(DRIVE_CENTER_SHOT_RIGHT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
            else if (type == 7)
            {
                MotorRight.writeMicroseconds(DRIVE_CENTER_SHOT_RIGHT_MOTOR);
                break_motor_left(DRIVE_CENTER_SHOT_LEFT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
            else if (type == 8)
            {
                break_motor_all(DRIVE_CENTER_SHOT_LEFT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
            else if (type == 9)
            {
                MotorLeft.writeMicroseconds(DRIVE_CENTER_SHOT_LEFT_MOTOR);
                break_motor_right(DRIVE_CENTER_SHOT_RIGHT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
            else
            {
                MotorRight.writeMicroseconds(TRANSITION_SPEED); // Restart motor
                MotorLeft.writeMicroseconds(TRANSITION_SPEED);  // Restart motor
                return (0);
            }
        }
        else if (next_type == 6)
        {
            if (type == 4)
            {
                MotorRight.writeMicroseconds(DRIVE_RIGHT_SHOT_RIGHT_MOTOR);
                break_motor_left(DRIVE_RIGHT_SHOT_LEFT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
            else if (type == 5)
            {
                MotorRight.writeMicroseconds(DRIVE_RIGHT_SHOT_RIGHT_MOTOR);
                break_motor_left(DRIVE_RIGHT_SHOT_LEFT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
            else if (type == 7)
            {
                MotorRight.writeMicroseconds(DRIVE_RIGHT_SHOT_RIGHT_MOTOR);
                break_motor_left(DRIVE_RIGHT_SHOT_LEFT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
            else if (type == 8)
            {
                break_motor_right(DRIVE_RIGHT_SHOT_RIGHT_MOTOR);
                break_motor_left(DRIVE_RIGHT_SHOT_LEFT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
            else if (type == 9)
            {
                MotorLeft.writeMicroseconds(DRIVE_RIGHT_SHOT_LEFT_MOTOR);
                break_motor_right(DRIVE_RIGHT_SHOT_RIGHT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
            else
            {
                MotorRight.writeMicroseconds(TRANSITION_SPEED); // Restart motor
                MotorLeft.writeMicroseconds(TRANSITION_SPEED);  // Restart motor
                return (0);
            }
        }
        else if (next_type == 7)
        {

            // Manage transitions for drop to clear shots

            if ((type == 4) || (type == 5) || (type == 6))
            {
                MotorLeft.writeMicroseconds(CLEAR_LEFT_SHOT_LEFT_MOTOR);
                MotorRight.writeMicroseconds(CLEAR_LEFT_SHOT_RIGHT_MOTOR);
                return (0); // we deduce by the time needed to break
            }

            // end of manage transitions from drop to clear shots

            if (type == 9)
            {
                MotorLeft.writeMicroseconds(CLEAR_LEFT_SHOT_LEFT_MOTOR);
                break_motor_right(CLEAR_LEFT_SHOT_RIGHT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
            else if (type == 8)
            {
                MotorLeft.writeMicroseconds(CLEAR_LEFT_SHOT_LEFT_MOTOR);
                break_motor_right(CLEAR_LEFT_SHOT_RIGHT_MOTOR);
                return (480); // we deduce by the time needed to break
            }

            else
            {
                MotorRight.writeMicroseconds(TRANSITION_SPEED); // Restart motor
                MotorLeft.writeMicroseconds(TRANSITION_SPEED);  // Restart motor
                return (0);
            }
        }

        else if (next_type == 8)
        {

            // Manage transitions for drop to clear shots

            if ((type == 4) || (type == 5) || (type == 6) || (type == 7) || (type == 9))
            {
                // Special trick to handle potential battery cut off
                MotorLeft.writeMicroseconds(1150);
                MotorRight.writeMicroseconds(1150);
                delay(200);
                MotorLeft.writeMicroseconds(1200);
                MotorRight.writeMicroseconds(1200);
                delay(200);
                MotorLeft.writeMicroseconds(1250);
                MotorRight.writeMicroseconds(1250);
                delay(200);
                MotorLeft.writeMicroseconds(1300);
                MotorRight.writeMicroseconds(1300);
                delay(200);
                //End of special trick

                MotorLeft.writeMicroseconds(CLEAR_CENTER_SHOT_LEFT_MOTOR);
                MotorRight.writeMicroseconds(CLEAR_CENTER_SHOT_RIGHT_MOTOR);
                return (600); // we deduce by the time needed to accelerate
            }

            else
            {
                MotorRight.writeMicroseconds(TRANSITION_SPEED); // Restart motor
                MotorLeft.writeMicroseconds(TRANSITION_SPEED);  // Restart motor
                return (0);
            }
        }

        else if (next_type == 9)
        {

            // Manage transitions for drop to clear shots

            if ((type == 4) || (type == 5) || (type == 6))
            {
                MotorLeft.writeMicroseconds(CLEAR_RIGHT_SHOT_RIGHT_MOTOR);
                MotorRight.writeMicroseconds(CLEAR_RIGHT_SHOT_LEFT_MOTOR);
                return (0); // we deduce by the time needed to break
            }

            // end of manage transitions from drop to clear shots

            if (type == 7)
            {
                MotorRight.writeMicroseconds(CLEAR_RIGHT_SHOT_RIGHT_MOTOR);
                break_motor_left(CLEAR_RIGHT_SHOT_LEFT_MOTOR);
                return (480); // we deduce by the time needed to break
            }
            else if (type == 8)
            {
                MotorRight.writeMicroseconds(CLEAR_RIGHT_SHOT_RIGHT_MOTOR);
                break_motor_left(CLEAR_RIGHT_SHOT_LEFT_MOTOR);
                return (480); // we deduce by the time needed to break
            }

            else
            {
                MotorRight.writeMicroseconds(TRANSITION_SPEED); // Restart motor
                MotorLeft.writeMicroseconds(TRANSITION_SPEED);  // Restart motor
                return (0);
            }
        }
    }
    else
    {
        MotorLeft.writeMicroseconds(TRANSITION_SPEED);
        MotorRight.writeMicroseconds(TRANSITION_SPEED);
        return (0);
    }
}