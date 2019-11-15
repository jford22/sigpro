#pragma once
#include <vector>
#include <complex>

class ChannelMeta
{
    private:
    double startTime_seconds;
    double startRange_meters;
    double stopRange_meters;
    double binSize_meters;
    public:
    ChannelMeta():
        startTime_seconds(0.0),
        startRange_meters(0.0),
        stopRange_meters(0.0),
        binSize_meters(0.0)
        {};
    ~ChannelMeta() {};

    void set(double startTime_sec,
            double startRange_m,
            double stopRange_m,
            double binSize_m)
    {
        startTime_seconds = startTime_sec;
        startRange_meters = startRange_m;
        stopRange_meters  = stopRange_m;
        binSize_meters    = binSize_m;
    };
};

class Channel
{
    private:
    ChannelMeta meta;
    std::vector<std::complex<double>> d;
    public:
    Channel();
    ~Channel();
};
