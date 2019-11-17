#pragma once
#include <string>
#include "DeciBel.h"

class State
{
    private:
    double x;
    double y;
    double z;
    public:
    State();
    ~State();
};

class KinematicState
{
    private:
    State pos_meters;
    State velocity_mps;
    State acceleration_mps2;
    State jerk_mps3;
    public:
    KinematicState();
    ~KinematicState();
};

class TargetAmplification
{
    private:
    std::string name;
    std::string inputFile;
    public:
    TargetAmplification();
    ~TargetAmplification();
};

class TargetResponse
{
    private:
        DeciBel rcs_db; // db relative to 1mw;
    public:
        double getRcs_dB() { return rcs_db.get_dB();};
        double getRcs_mW() { return rcs_db.get_unit(MILLIWATT);};
        double getRcs_V()  { return rcs_db.get_unit(VOLT);};

        TargetResponse();
        ~TargetResponse();
        void setRcs_dB(double rcs_db_in, dB_REF_UNIT ref_unit_in)
        { rcs_db.set_dB(rcs_db_in,ref_unit_in);};
};

class Target
{
    private:
        unsigned int truthId;
        KinematicState state;
        TargetAmplification targetAmp;
        TargetResponse targetResponse;
    public:
        unsigned int getId()            { return truthId;};
        KinematicState& getState()      { return state;};
        TargetAmplification getAmp()    { return targetAmp;};
        TargetResponse& getResponse()   { return targetResponse;};
        Target();
        ~Target();
};
