#pragma once
#include "SignalDecorator.h"
#include "Channel.h"
#include "Target.h"
#include <map>

class TargetDecorator : public SignalDecorator
{
    private:
        Signal* child;
        Target* target;
        Channel waveform;
        std::map<int,Channel> targetContributions;

        void constructWaveform(const TxRxMeta& txrx_config);
        void selectTargets(const TxRxMeta& txrx_config, Target& target);
        void buildTargetResponse();
    public:
        TargetDecorator(Signal *s);
        ~TargetDecorator();

        // Interface Methods to Implement
        void init();
        void setup(const TxRxMeta& txrx_config, Target& target);
        void stage(Channel& Channel);
        void contribute(Channel& Channel);
};
