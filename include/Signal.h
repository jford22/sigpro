#pragma once

class Signal
{
public:
    Signal() {};
    ~Signal() {};
    virtual void StageSignal() = 0;
    virtual void PopulateSignal() = 0;
};
