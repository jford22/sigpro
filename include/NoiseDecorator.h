#pragma once
#include "SignalDecorator.h"
#include "Channel.h"
// Forward Declare Classes
class TxRxMeta;
class Target;

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
        void setup(const TxRxMeta& txrx_config, Target& target);
        void stage(Channel& channel);
        void contribute(Channel& channel);
};
