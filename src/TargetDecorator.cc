#include "TargetDecorator.h"
#include "Target.h"
#include "Constants.h"
#include "TxRxMeta.h"

TargetDecorator::TargetDecorator(Signal *s): SignalDecorator(s),
    child(s),
    target(),
    waveform(),
    targetContributions()
{
}

// Interface Methods to Implement
void TargetDecorator::init()
{
    child->init();
    std::cout << "init() - TargetDecorator" << std::endl;
    targetContributions.clear();
}
void TargetDecorator::setup(const TxRxMeta& txrx_config, Target& target)
{
    child->setup(txrx_config, target);
    std::cout << "setup() - TargetDecorator" << std::endl;
    constructWaveform(txrx_config);
    selectTargets(txrx_config, target);

}
void TargetDecorator::stage(Channel& channel)
{
    child->stage(channel);   // Child call
    std::cout << "stage() - TargetDecorator" << std::endl;
    buildTargetResponse();
}
void TargetDecorator::contribute(Channel& channel)
{
    child->contribute(channel);   // Child call
    std::cout << "contribute() - TargetDecorator" << std::endl;
    for(auto tgtResponse: targetContributions)
    {
        std::cout << "Adding Contribution for TgtId: " << tgtResponse.first << std::endl;
        //channel += tgtResponse.second; // TODO - re-add once += operator works for Channel Class
    }
}

void TargetDecorator::constructWaveform(const TxRxMeta& txrx_config)
{
    const double pulsewidth_sec = txrx_config.get_tx_pulsewidth_sec();
    const double meters_per_bin = txrx_config.get_rx_window_rangeBin_resolution_meters();
    long numberOfSamples = pulsewidth_sec * LIGHTSPEED_m_p_sec / meters_per_bin; 

    waveform.resize(numberOfSamples);
    const double start_frequency = txrx_config.get_tx_start_frequency_GHz() * GHz_to_Hz;
    const double stop_frequency  = txrx_config.get_tx_stop_frequency_GHz() * GHz_to_Hz;
    const double seconds_per_sample = pulsewidth_sec / (double)(numberOfSamples);

    // c = ( f1 - f0 ) / T
    // c: (chirpFactor) is chirpyness used to calculate phase
    // f1: is Final Frequency
    // f0: is initial Frequency
    // T: Time it takes to sweep
    const double chirpFactor = (stop_frequency - start_frequency) / pulsewidth_sec;

    const double initialPhase = 0.0;

    // Calculate Phase for LFM Chirp
    // Phi = Phi_0 + 2*PI*(c/2*t^2+f0*t)
    // Phi: is Phase at time (t)
    // Phi_0: is initial Phase at t=0
    // c: is chirpFactor - define above
    // f0: is initial frequency (start_frequency)
    double t = 0;
    for(auto waveformSample : waveform)
    {
        double phase = initialPhase + TWO_PI * (0.5 * chirpFactor * t * t + start_frequency * t); // TODO confirm this and optimize
        waveformSample = std::exp(phase); // TODO May need to normalize this ??
        t += seconds_per_sample;
    }
     
}

void TargetDecorator::selectTargets(const TxRxMeta& txrx_config, Target& target_in)
{
    const double window_start_range_meters = txrx_config.get_pulse_start_range_meters();
    const double window_stop_range_meters  = txrx_config.get_pulse_stop_range_meters();
    const double pulse_length_meters       = txrx_config.get_tx_pulsewidth_sec() * LIGHTSPEED_m_p_sec;
    const double target_range_meters = target_in.getState().getRange();

    std::cout << "Win Start\t" << window_start_range_meters << std::endl
              << "Win Stop\t" << window_stop_range_meters << std::endl
              << "PulseLengh\t" << pulse_length_meters << std::endl
              << "tgt Range\t" << target_range_meters << std::endl;

    // Check if TargetRange += PulseRange is in Window
    if(window_start_range_meters <= (target_range_meters + pulse_length_meters) &&
            (target_range_meters - pulse_length_meters)  <= window_stop_range_meters)
    {
        // Target response is within the range
        std::cout << "Target Is in Range" << std::endl;
        target = &target_in;
    }
}

// Generate Target Response
void TargetDecorator::buildTargetResponse()
{
    // TODO - Should not modify waveform for specific target - should make copy or find better approach
    // Apply Target RCS to Waveform
    for(auto waveformSample : waveform)
    {
        waveformSample *= target->getResponse().getRcs_V(); // TODO This test hack may not be right
    }
    targetContributions.insert(std::pair<int,Channel>(target->getId(), waveform));
}
