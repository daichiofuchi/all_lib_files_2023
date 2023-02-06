#ifndef _MD_SERVO_H_
#define _MD_SERVO_H_

#include "mbed.h"
#include "pid.h"
#include "dc_motor_1.h"
#include "rotary_encoder.h"

class MD_Servo
{
public:
    MD_Servo(dc_motor_1 motor, rotary_encoder encoder, float CTRL_PERIOD);
    void rot(float deg);
    void drive(float value);
    void set_gain(float p_gain, float i_gain, float d_gain);
    void set_output_limit(float value);

private:
    float CTRL_PERIOD_;
    float deg_;
    float now_enc_;
    float pid_output_;
    PID pid_;
    dc_motor_1 motor_;
    rotary_encoder encoder_;
};
#endif
