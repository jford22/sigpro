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
    State(double x_in, double y_in, double z_in);
    ~State();
    double getMagnitude();
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

    void setPosition_meters(State pos_m_in) { pos_meters = pos_m_in;};
    void setVelocity_mps(State vel_mps_in) { velocity_mps = vel_mps_in;};
    void setAcceleration_mps2(State acc_mps2_in) { acceleration_mps2 = acc_mps2_in;};
    void setJerk_mps3(State jerk_mps3_in) { jerk_mps3 = jerk_mps3_in;};

    double getRange();
};

class TargetAmplification
{
    private:
    std::string name;
    std::string inputFile;
    public:
    TargetAmplification();
    ~TargetAmplification();

    const std::string& getName() { return name;};
    void setName(const std::string& name_in) { name = name_in;};
    // Add for InputFile etc.
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
        void setId(unsigned int truthId_in) { truthId = truthId_in;};
        KinematicState& getState()      { return state;};
        TargetAmplification getAmp()    { return targetAmp;};
        TargetResponse& getResponse()   { return targetResponse;};
        Target();
        ~Target();
};
