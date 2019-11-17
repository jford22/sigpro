#pragma once
#include <iostream>

#include "Signal.h"

class SignalDecorator : public Signal
{
    private:
        Signal* child;

    public:
        SignalDecorator(Signal *s): child(s) {};
        ~SignalDecorator() {};

        // Interface Methods to Implement
        void init()
        {
            child->init();
            std::cout << "init() - SignalDecorator" << std::endl;
        };
        void setup()
        {
            child->setup();
            std::cout << "setup() - SignalDecorator" << std::endl;
        };
        void stage()
        {
            child->stage();
            std::cout << "stage() - SignalDecorator" << std::endl;
        }

        void contribute()
        {
            child->contribute();
            std::cout << "contribute() - SignalDecorator" << std::endl;
        }
};
