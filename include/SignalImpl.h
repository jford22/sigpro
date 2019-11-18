#pragma once
#include <iostream>
#include "Channel.h"
#include "Signal.h"

class TxRxMeta;
class ChannelMeta;

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
        void setup(const TxRxMeta& txrx_config, Target& target)
        {
            setupChannels(txrx_config);
            (void)target;
            std::cout << "setup() - SignalImp" << std::endl;
        };
        void stage(Channel& /*channel*/)
        {
            std::cout << "stage() - SignalImp" << std::endl;
        };
        void contribute(Channel& /*channel*/)
        {
            std::cout << "contribute() - SignalImp" << std::endl;
        };

        // Setup Phase Helper Methods
        void setupChannels(const TxRxMeta& txrx_config);
        ChannelMeta buildChannelMeta(const TxRxMeta& txrx_config);
};
