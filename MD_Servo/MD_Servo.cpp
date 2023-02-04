#include "MD_Servo.h"

MD_Servo::MD_Servo(PinName pwm_pin, PinName dir_pin, PinName enc_a, PinName enc_b, int pulse_per_rev, float CTRL_PERIOD, float p_gain, float i_gain, float d_gain)
{
    pwm_pin_ = pwm_pin;
    dir_pin_ = dir_pin;
    enc_a_ = enc_a;
    enc_b_ = enc_b;
    pulse_per_rev_ = pulse_per_rev;
    CTRL_PERIOD_ = CTRL_PERIOD;
    p_gain_ = p_gain;
    i_gain_ = i_gain;
    d_gain_ = d_gain;
    pid.set(CTRL_PERIOD_);
    motor->set(pwm_pin_, dir_pin, 1);
    encoder->set(enc_a_, enc_b_, NC, pulse_per_rev_, rotary_encoder::X4_ENCODING);
    pid.setTarget(0);
    pid.setGain(p_gain_, i_gain_, d_gain_);
    pid.setFirstPosition(0.0);
    pid.setLimitOutput(50);
}

void MD_Servo::rot(float deg)
{
    pid.setTarget(deg);
    now_enc_ = encoder->getRad();
    pid_output_ = pid.control(now_enc_);
    motor->drive(pid_output_);
}

void MD_Servo::drive(float value){
    motor->drive(value);
}
