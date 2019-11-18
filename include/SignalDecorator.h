#pragma once
#include <iostream>

#include "Signal.h"

class TxRxMeta;
class Target;

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
        void setup(const TxRxMeta& txrx_config, Target& target)
        {
            child->setup(txrx_config, target);
            std::cout << "setup() - SignalDecorator" << std::endl;
        };
        void stage(Channel& channel)
        {
            child->stage(channel);
            std::cout << "stage() - SignalDecorator" << std::endl;
        }

        void contribute(Channel& channel)
        {
            child->contribute(channel);
            std::cout << "contribute() - SignalDecorator" << std::endl;
        }
};
