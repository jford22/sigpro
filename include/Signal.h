#pragma once
class TxRxMeta;
class Target;
class Channel;

class Signal
{
public:
    Signal() {};
    ~Signal() {};
    // Do Initialization Tasks That doesn't Need to be done every Pass
    virtual void init() = 0;
    // Prepare - take in and setup parameters for specific pulse
    virtual void setup(const TxRxMeta& txrx_config, Target& target) = 0;
    // Stage intermediate processing that can be done prior to contributing to agregate signal
    virtual void stage(Channel& channel) = 0;
    // Contribute specific peice to agregate structure
    virtual void contribute(Channel& channel) = 0;
};
