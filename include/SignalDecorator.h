#pragma once
#include <iostream>

#include "Signal.h"

class SignalDecorator : public Signal
{
    private:
        Signal* child;

    public:
        SignalDecorator(Signal *s): child(s) {};
        ~SignalDecorator();
        void StageSignal()
        {
            std::cout << "SignalDecorator: StageSignal() " << std::endl;
        }

        void PopulateSignal()
        {
            std::cout << "SignalDecorator: PopulateSignal() " << std::endl;
        }
};
