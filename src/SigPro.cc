#include <iostream>

#include "SigPro.h"
#include "TxRxMeta.h"
#include "SigProTestInputGenerator.h"
#include "Target.h"
#include "TargetDecorator.h"
#include "NoiseDecorator.h"
#include "SignalDecorator.h"
#include "SignalImpl.h"
#include "Signal.h"
#include "Channel.h"

SigPro::SigPro():
    signal(),
    control_set(),
    target_set()
{
    signal = new TargetDecorator(new NoiseDecorator(new SignalDecorator(new SignalImpl(30))));
}

SigPro::~SigPro()
{
}

void SigPro::setupSignal()
{
    std::cout << "SigPro SetupSignal() " << std::endl;
    SigProTestInputGenerator testgen;
    unsigned int set_selector = 0;
    control_set = testgen.generateControl(MAX_PULSES, set_selector);
    target_set  = testgen.generateTargets(MAX_TARGETS, set_selector);
    signal->init();
}

void SigPro::generateScene()
{
    // Setup Config Data
    std::map<int,Channel> channel_set;
    for(auto control : control_set)
    {
        std::cout << "----------- PRI # " << control.first << " --------------" << std::endl;
        Channel& channel = channel_set[control.first]; // Create or Re-use pri Channel
        const TxRxMeta& txrx_config = control.second;
        // Setup Target Data
        Target tgt = target_set.at(0);

        // Run SigPro Class
        signal->setup(txrx_config, tgt);
        signal->stage(channel);
        signal->contribute(channel);
    }
}
