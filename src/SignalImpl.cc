#include "SignalImpl.h"
#include "TxRxMeta.h"
#include <iostream>

void SignalImpl::setupChannels(const TxRxMeta& txrx_config)
{
    ChannelMeta channelMeta = buildChannelMeta(txrx_config);
    sum.setMeta(channelMeta);
    angle.setMeta(channelMeta);
} 
ChannelMeta SignalImpl::buildChannelMeta(const TxRxMeta& txrx_config)
{
    ChannelMeta channelMeta;
    channelMeta.setStartTime_seconds(txrx_config.get_rx_window_start_time_seconds()); // Maybe should be time on trget?
    channelMeta.setStartRange_meters(txrx_config.get_pulse_start_range_meters());
    channelMeta.setStopRange_meters(txrx_config.get_pulse_stop_range_meters());
    channelMeta.setRangeBinSize_meters(txrx_config.get_rx_window_rangeBin_resolution_meters());
    long numBins  = txrx_config.get_rx_window_front_padding_bins() +
                   ( (txrx_config.get_pulse_stop_range_meters() - txrx_config.get_pulse_start_range_meters()) /
                   txrx_config.get_rx_window_rangeBin_resolution_meters() ) +
                   txrx_config.get_rx_window_back_padding_bins();
    /*
       std::cout << "Front Pad\t" << txrx_config.get_rx_window_front_padding_bins()  << std::endl 
       << "Resolution\t" <<  txrx_config.get_rx_window_rangeBin_resolution_meters()  << std::endl
       << "stop Range\t" <<  txrx_config.get_pulse_stop_range_meters()  << std::endl
       << "Start Range\t" << txrx_config.get_pulse_start_range_meters() << std::endl
       << "Delta Range\t" << (txrx_config.get_pulse_stop_range_meters() - txrx_config.get_pulse_start_range_meters())  << std::endl
       << "Back Pad \t" << txrx_config.get_rx_window_back_padding_bins() << std::endl;
     */
    std::cout << "NumBins for Sum Channel is: " << numBins << std::endl;
    channelMeta.setNumberOfBins(numBins);
    return channelMeta;
}
