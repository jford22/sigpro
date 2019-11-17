#pragma once
#include "SignalDecorator.h"
#include "Channel.h"
#include <map>

class TargetDecorator : public SignalDecorator
{
    private:
        Signal* child;
        std::map<int,Channel> targetContributions;

        void buildTargetResponse();
    public:
        TargetDecorator(Signal *s);
        ~TargetDecorator();

        // Interface Methods to Implement
        void init();
        void setup();
        void stage();
        void contribute();
};
