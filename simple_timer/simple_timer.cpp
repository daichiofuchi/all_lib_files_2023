#include "simple_timer.h"

simple_timer::simple_timer(float CTRL_TIME){
    CTRL_TIME_ = CTRL_TIME;
}

void simple_timer::start(float finish_time){
    finish_time_ = finish_time;
    now_count_ = 0;
    flag_ = false;
}

bool simple_timer::check(){
    if(now_count_ * CTRL_TIME_ > finish_time_){
        flag_ = true;
    }
    now_count_++;
    return flag_;
}
