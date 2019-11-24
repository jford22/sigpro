#pragma once
#include "Enums.h"

class Interval
{
    private:
        double start;
        double stop;
        double step;
        UNITS units;
    public:
        Interval(UNITS units_in) : 
            start(0.0),
            stop(0.0),
            step(0.0),
            units(units_in)
    {};
        ~Interval() {};

        // GETTERS
        double getStart() const { return start; };
        double getStop()  const { return stop;  };
        double getStep()  const { return step;  };
        UNITS  getUnits() const { return units; };
        // SETTERS 
        void setStart(double start_in) { start = start_in; };
        void setStop(double stop_in)   { stop = stop_in;  };
        void setStep(double step_in)   { step = step_in;  };
        void setUnits(UNITS units_in)  { units = units_in; };
};
        
class ChannelMeta
{
private:
    long numberOfBins;
    Interval time;
    Interval range;

public:
    ChannelMeta():
        numberOfBins(0),
        time(SECOND),
        range(METER)
        {};
    ~ChannelMeta() {};

    // Getters
    double getStartTime_seconds()   const { return time.getStart();};
    double getStopTime_seconds()    const { return time.getStop();};
    double getTimeStep_seconds()    const { return time.getStep();};
    double getStartRange_meters()   const { return range.getStart();};
    double getStopRange_meters()    const { return range.getStop();};
    double getRangeStep_meters()    const { return range.getStep();};
    long   getNumberOfBins()        const { return numberOfBins;};

    long   getIndexForTime(double time_in_sec) const;

    // Setters
    void setStartTime_seconds(double seconds_in)
           {time.setStart(seconds_in);};
    void setStopTime_seconds(double seconds_in)
            {time.setStop(seconds_in);};
    void setTimeBinSize_seconds(double seconds_in)
            {time.setStep(seconds_in);};
    void setStartRange_meters(double meters_in)
           {range.setStart(meters_in);};
    void setStopRange_meters(double meters_in)    
           {range.setStop(meters_in);};
    void setRangeBinSize_meters(double meters_in) 
           {range.setStep(meters_in);};
    void setNumberOfBins(long numBins_in) 
           {numberOfBins = numBins_in;};

    bool containsTime(double time_in_sec) const;
};
