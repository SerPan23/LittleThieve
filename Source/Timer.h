#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED
#include <SDL.h>
class Timer {

private:
    static Timer* sInstance;
    unsigned int mStartTicks;
    unsigned int mElapsedTicks;
    float mDelataTime;
    float mTimeScale;

public:
    static Timer* Instance();
    static void Release();
    void Reset();
    float DeltaTime();
    void TimeScale(float t = 1.0f);
    float TimeScale();
    void Update();

private:
    Timer();
    ~Timer();
};

#endif // TIMER_H_INCLUDED
