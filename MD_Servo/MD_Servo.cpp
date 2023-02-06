#include "MD_Servo.h"

MD_Servo::MD_Servo(dc_motor_1 motor, rotary_encoder encoder, float CTRL_PERIOD) : motor_{motor}, encoder_{encoder}
{
    CTRL_PERIOD_ = CTRL_PERIOD;
    pid_.set(CTRL_PERIOD_);
    pid_.setTarget(0);
    pid_.setGain(10.0f, 0.0f, 0.5f);
    pid_.setFirstPosition(0.0);
    pid_.setLimitOutput(50);
}

void MD_Servo::rot(float deg)
{
    pid_.setTarget(deg);
    now_enc_ = encoder_.getRad();
    pid_output_ = pid_.control(now_enc_);
    motor_.drive(pid_output_);
}

void MD_Servo::drive(float value)
{
    motor_.drive(value);
}

void MD_Servo::set_gain(float p_gain, float i_gain, float d_gain)
{
    pid_.setGain(p_gain, i_gain, d_gain);
}

void MD_Servo::set_output_limit(float value)
{
    pid_.setLimitOutput(value);
}
