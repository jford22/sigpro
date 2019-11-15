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
        void StageSignal()
        {
            std::cout << "SignalImp: stageImpl() " << std::endl;
        };
        void PopulateSignal()
        {
            std::cout << "SignalImp: PopulateSignal() " << std::endl;
        };
};
