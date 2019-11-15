#include <iostream>

#include "SigPro.h"
#include "NoiseDecorator.h"
#include "SignalDecorator.h"
#include "SignalImpl.h"
#include "Signal.h"
#include "Channel.h"

SigPro::SigPro():
    signal()
{
    signal = new NoiseDecorator(new SignalDecorator(new SignalImpl(30)));
}

SigPro::~SigPro()
{
}

void SigPro::setupSignal()
{
    std::cout << "SigPro SetupSignal() " << std::endl;
}

void SigPro::generateScene()
{
    signal->StageSignal();
    signal->PopulateSignal();
}
