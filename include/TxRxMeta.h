#pragma once
#include "Constants.h"

// This Class Should Contain Information about The Transmit Waveform, it's timing and the receive window

enum  Modulation {
    LFM,
    NLFM,
    DPC,
    TEST};
class TxRxMeta
{
    private: 
    // Transmit (TX) Parameters
    double tx_start_time_seconds;
    double tx_stop_time_seconds;
    double tx_start_frequency_GHz;
    double tx_stop_frequency_GHz;
    double tx_bandwidth_MHz;
    double tx_power_watts;
    Modulation wf_modulation;

    // Receive (RX) Parameters
    double rx_window_start_time_seconds;
    double rx_window_stop_time_seconds;
    double rx_bandwidth_MHz;
    double rx_window_rangeBin_resolution_meters;
    double rx_window_planned_doppler_Khz;

    long rx_window_front_padding_bins;
    long rx_window_back_padding_bins;
    public:
TxRxMeta();
~TxRxMeta();

// Getters
    double get_tx_start_time_seconds() const {return tx_start_time_seconds;};
    double get_tx_stop_time_seconds()  const { return tx_stop_time_seconds;};
    double get_tx_start_frequency_GHz()const { return tx_start_frequency_GHz;};
    double get_tx_stop_frequency_GHz() const { return tx_stop_frequency_GHz;};
    double get_tx_bandwidth_MHz()      const { return tx_bandwidth_MHz;};
    double get_tx_power_watts()        const { return tx_power_watts;};
    Modulation get_wf_modulation()     const { return wf_modulation;};

    double get_rx_window_start_time_seconds() const { return rx_window_start_time_seconds;};
    double get_rx_window_stop_time_seconds()  const { return rx_window_stop_time_seconds;};
    double get_rx_bandwidth_MHz()             const { return rx_bandwidth_MHz;};
    double get_rx_window_rangeBin_resolution_meters() const { return rx_window_rangeBin_resolution_meters;};
    double get_rx_window_planned_doppler_Khz() const { return rx_window_planned_doppler_Khz;};

    long get_rx_window_front_padding_bins() const { return rx_window_front_padding_bins;};
    long get_rx_window_back_padding_bins()  const { return rx_window_back_padding_bins;};

    // Simple Calculated Getters
    double get_tx_pulsewidth_sec()     const { return tx_stop_time_seconds - tx_start_time_seconds;};
    double get_pulse_center_freq_GHz() const 
            { return (tx_start_frequency_GHz + tx_stop_frequency_GHz) / 2.0;};

    double get_pulse_start_on_target_seconds() const
           { return (tx_start_time_seconds + rx_window_start_time_seconds) / 2.0;};

    double get_pulse_stop_on_target_seconds() const
           { return (tx_stop_time_seconds + rx_window_stop_time_seconds) / 2.0;};

    double get_pulse_start_range_meters() const
            { return (rx_window_start_time_seconds - tx_start_time_seconds) * LIGHTSPEED_m_p_sec;};

    double get_pulse_stop_range_meters() const
            { return (rx_window_stop_time_seconds - tx_stop_time_seconds) * LIGHTSPEED_m_p_sec;};

    // Setters
    void set_tx_start_time_seconds(double tx_start_time_seconds_in) 
                {tx_start_time_seconds = tx_start_time_seconds_in;};
    void set_tx_stop_time_seconds( double tx_stop_time_seconds_in) 
                {tx_stop_time_seconds = tx_stop_time_seconds_in;};
    void set_tx_start_frequency_GHz( double tx_start_frequency_GHz_in) 
                {tx_start_frequency_GHz = tx_start_frequency_GHz_in;};
    void set_tx_stop_frequency_GHz(double tx_stop_frequency_GHz_in)
                {tx_stop_frequency_GHz = tx_stop_frequency_GHz_in;};
    void set_tx_bandwidth_MHz(double tx_bandwidth_MHz_in)
                {tx_bandwidth_MHz = tx_bandwidth_MHz_in;};
    void set_tx_power_watts(double tx_power_watts_in)
                {tx_power_watts = tx_power_watts_in;};
    void set_wf_modulation(Modulation wf_modulation_in)
                {wf_modulation = wf_modulation_in;};

    // Receive (RX) Parameters
    void set_rx_window_start_time_seconds(double rx_window_start_time_seconds_in)
                {rx_window_start_time_seconds = rx_window_start_time_seconds_in;};
    void set_rx_window_stop_time_seconds(double rx_window_stop_time_seconds_in)
                {rx_window_stop_time_seconds = rx_window_stop_time_seconds_in;};
    void set_rx_bandwidth_MHz(double rx_bandwidth_MHz_in)
                {rx_bandwidth_MHz = rx_bandwidth_MHz_in;};
    void set_rx_window_rangeBin_resolution_meters(double rx_window_rangeBin_resolution_meters_in)
                {rx_window_rangeBin_resolution_meters = rx_window_rangeBin_resolution_meters_in;};
    void set_rx_window_planned_doppler_Khz(double rx_window_planned_doppler_Khz_in)
                {rx_window_planned_doppler_Khz = rx_window_planned_doppler_Khz_in;};

    void set_rx_window_front_padding_bins(long rx_window_front_padding_bins_in)
                {rx_window_front_padding_bins = rx_window_front_padding_bins_in;};
    void set_rx_window_back_padding_bins(long rx_window_back_padding_bins_in)
                {rx_window_back_padding_bins = rx_window_back_padding_bins_in;};

};
