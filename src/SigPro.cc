#include <iostream>

#include "SigPro.h"
#include "TargetDecorator.h"
#include "NoiseDecorator.h"
#include "SignalDecorator.h"
#include "SignalImpl.h"
#include "Signal.h"
#include "Channel.h"

SigPro::SigPro():
    signal()
{
    signal = new TargetDecorator(new NoiseDecorator(new SignalDecorator(new SignalImpl(30))));
}

SigPro::~SigPro()
{
}

void SigPro::setupSignal()
{
    std::cout << "SigPro SetupSignal() " << std::endl;
    signal->init();
}

void SigPro::generateScene()
{
    signal->setup();
    signal->stage();
    signal->contribute();
}
