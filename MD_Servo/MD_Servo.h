#ifndef _MD_SERVO_H_
#define _MD_SERVO_H_

#include "mbed.h"
#include "pid.h"
#include "dc_motor_1.h"
#include "rotary_encoder.h"

class MD_Servo
{
public:
    MD_Servo(PinName pwm_pin, PinName dir_pin, PinName enc_a, PinName enc_b, int pulse_per_rev, float CTRL_PERIOD, float p_gain, float i_gain, float d_gain);
    void rot(float deg);
    void reset();

private:
    PinName pwm_pin_;
    PinName dir_pin_;
    PinName enc_a_;
    PinName enc_b_;
    int pulse_per_rev_;
    float CTRL_PERIOD_;
    float p_gain_;
    float i_gain_;
    float d_gain_;
    float deg_;
    float now_enc_;
    float pid_output_;
    PID pid;
    dc_motor_1* motor;
    rotary_encoder* encoder;
};
#endif
