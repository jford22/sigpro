#pragma once

class ChannelMeta
{
private:
    double startTime_seconds;
    double startRange_meters;
    double stopRange_meters;
    double binSize_meters;
    long   numberOfBins;

public:
    ChannelMeta():
        startTime_seconds(0.0),
        startRange_meters(0.0),
        stopRange_meters(0.0),
        binSize_meters(0.0),
        numberOfBins(0)
        {};
    ~ChannelMeta() {};

    void set(double startTime_sec,
            double startRange_m,
            double stopRange_m,
            double binSize_m,
            long numBins)
    {
        startTime_seconds = startTime_sec;
        startRange_meters = startRange_m;
        stopRange_meters  = stopRange_m;
        binSize_meters    = binSize_m;
        numberOfBins      = numBins;
    };

    // Getters
    double getStartTime_seconds()   { return startTime_seconds;};
    double getStartRange_meters()   { return startRange_meters;};
    double getStopRange_meters()    { return stopRange_meters;};
    double getRangeBinSize_meters() { return binSize_meters;};
    long   getNumberOfBins()        { return numberOfBins;};

    // Setters
    void setStartTime_seconds(double seconds_in)
           {startTime_seconds = seconds_in;};
    void setStartRange_meters(double meters_in)
           {startRange_meters = meters_in;};
    void setStopRange_meters(double meters_in)    
           {stopRange_meters = meters_in;};
    void setRangeBinSize_meters(double meters_in) 
           {binSize_meters = meters_in;};
    void setNumberOfBins(long numBins_in) 
           {numberOfBins = numBins_in;};
};
