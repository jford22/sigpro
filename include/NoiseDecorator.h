#pragma once
#include "SignalDecorator.h"

class NoiseDecorator : public SignalDecorator
{
    private:
        Signal* child;

    public:
    NoiseDecorator(Signal *s);
    ~NoiseDecorator();
    void StageSignal()
    {
        child->StageSignal();   // Child call
        std::cout << "Noise Decorator: StageSignal() " << std::endl;
    }
    void PopulateSignal()
    {
        child->PopulateSignal();   // Child call
        std::cout << "Noise Decorator: PopulateSignal() " << std::endl;
    }
};
