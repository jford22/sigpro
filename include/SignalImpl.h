#pragma once
#include <iostream>
#include "Channel.h"
#include "Signal.h"

class SignalImpl : public Signal
{
    private:
        Channel sum;
        Channel angle;
//        PriSigProPrams params;

    public:
        SignalImpl(int size): sum(), angle()
        {
            std::cout << "Making SigImpl with Size " << size << std::endl;
        };
        ~SignalImpl();
       
        // Interface Methods to Implement
        void init()
        {
            std::cout << "init() - SignalImp" << std::endl;
        };
        void setup()
        {
            std::cout << "setup() - SignalImp" << std::endl;
        };
        void stage()
        {
            std::cout << "stage() - SignalImp" << std::endl;
        };
        void contribute()
        {
            std::cout << "contribute() - SignalImp" << std::endl;
        };
};
