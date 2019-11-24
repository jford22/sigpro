#include "SigProTestInputGenerator.h"
#include "Target.h"
#include "Constants.h"
#include "TxRxMeta.h"
#include "Enums.h"

#include <string>

SigProTestInputGenerator::SigProTestInputGenerator():
    control_set(),
    target_set()
{
    buildControl();
    buildTarget();
}

SigProTestInputGenerator::~SigProTestInputGenerator()
{
}

std::map<unsigned int,TxRxMeta>& SigProTestInputGenerator::generateControl(unsigned int numPRIs, unsigned int set_selector)
{
    //std::map<unsigned int, TxRxMeta> controls;
    if(numPRIs > 0)
    {
        switch(set_selector)
        {
            case 0:
                break;
            case 1:
                break;
            default:
                break;
        }
    }
    return control_set;
}

std::map<unsigned int,Target>& SigProTestInputGenerator::generateTargets(unsigned int numTargets, unsigned int set_selector)
{
    //std::map<unsigned int, Target> targets;
    if(numTargets > 0)
    {
        switch(set_selector)
        {
            case 0:
                break;
            case 1:
                break;
            default:
                break;
        }
    }
    return target_set;
}

void SigProTestInputGenerator::buildControl()
{
    double pulseStartTime = 0.0;
    double pulseRepitionInterval = 1.0e-3;  // Test Value
    for(int pulseCounter=0; pulseCounter<MAX_PULSES; ++pulseCounter)
    {
        TxRxMeta& control = control_set[pulseCounter];  // Add if doesn't exist
        pulseStartTime += pulseRepitionInterval;
        control.set_tx_start_time_seconds(pulseStartTime + 0.0);
        control.set_tx_stop_time_seconds(pulseStartTime + 10e-6);
        control.set_tx_start_frequency_GHz(2.20);
        control.set_tx_start_frequency_GHz(2.225);
        control.set_tx_bandwidth_MHz(25.0);
        control.set_tx_power_watts(100.0e3);
        control.set_wf_modulation(Modulation::TEST);

        control.set_rx_window_start_time_seconds(pulseStartTime + 100.0e-6);
        control.set_rx_window_stop_time_seconds(pulseStartTime + 140.0e-6);
        control.set_rx_bandwidth_MHz(25.0);
        control.set_rx_window_rangeBin_resolution_meters(10.0); // Test Values
        control.set_rx_window_planned_doppler_Khz(0.0);
        control.set_rx_window_front_padding_bins(100);
        control.set_rx_window_back_padding_bins(100);
    }
}

void SigProTestInputGenerator::buildTarget()
{
    for(int targetCounter =0; targetCounter < MAX_TARGETS; ++targetCounter)
    {
        Target& target = target_set[targetCounter]; // Add if doesn't exist
        target.setId(targetCounter);
        target.getAmp().setName("TestTgt");

        target.getState().setPosition_meters(   State(10000.0+(TARGET_OFFSET*targetCounter), 20000.0, 20000.0));
        target.getState().setVelocity_mps(      State(100.0, 200.0, 0.0));
        target.getState().setAcceleration_mps2( State(1.0, -2.0, 0.0));
        target.getState().setJerk_mps3(         State(0.0, 0.0, 0.0));
        target.getResponse().setRcs_dB(10.0, VOLT); // Should be WATT , but TESTING with VOLT

    }

}
