#pragma once
// This Class Should Contain Information about The Transmit Waveform, it's timing and the receive window

class TxRxMeta
{
    // Transmit (TX) Parameters
    double tx_start_time_seconds;
    double tx_stop_time_seconds;
    double tx_start_frequency_GHz;
    double tx_stop_frequency_GHz;
    double tx_bandwidth_MHz;
    double tx_power_watts;

    // Receive (RX) Parameters
    double rx_window_start_time_seconds;
    double rx_window_stop_time_seconds;
    double rx_bandwidth_MHz;
    double rx_window_rangeBin_resolution_meters;
    double rx_window_planned_doppler_Khz;

    double rx_window_front_padding_bins;
    double rx_window_back_padding_bins;
};
