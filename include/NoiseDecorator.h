#pragma once
#include "SignalDecorator.h"
#include "Channel.h"

class NoiseDecorator : public SignalDecorator
{
    private:
        Signal* child;
        Channel staged_noise;

        void generateGaussianWhiteNoise();
    public:
        NoiseDecorator(Signal *s);
        ~NoiseDecorator();

        // Interface Methods to Implement
        void init();
        void setup();
        void stage();
        void contribute();
};
