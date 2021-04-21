#include "Timer.h"
Timer* Timer::sInstance = NULL;

Timer* Timer::Instance() {

    if(sInstance == NULL)
        sInstance = new Timer();

    return sInstance;
}

void Timer::Release() {
    delete sInstance;
    sInstance = NULL;
}

Timer::Timer() {
    Reset();
    mTimeScale = 1.0f;
}

Timer::~Timer() {}

void Timer::Reset() {

    mStartTicks = SDL_GetTicks();
    mElapsedTicks = 0;
    mDelataTime = 0.0f;
}

float Timer::DeltaTime() {
    return mDelataTime;
}

void Timer::TimeScale(float t) {

    mTimeScale = t;
}

float Timer::TimeScale() {
    return mTimeScale;
}

void Timer::Update() {
    int currentTicks = SDL_GetTicks();
    mElapsedTicks = currentTicks - mStartTicks;
    mStartTicks = currentTicks;
    mDelataTime = mElapsedTicks * 0.001f;
}
