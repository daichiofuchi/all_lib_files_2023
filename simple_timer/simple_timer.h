#ifndef _SIMPLE_TIMER_
#define _SIMPLE_TIMER_

class simple_timer
{

public:
    simple_timer(float CTRL_TIME);
    void start(float finish_time);
    bool check();


private:
    float now_count_;
    float CTRL_TIME_;
    float finish_time_;
    static bool flag_;
};
#endif
