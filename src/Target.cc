#include "Target.h"

State::State():
    x(0.0),
    y(0.0),
    z(0.0)
{
}

State::~State()
{
}

KinematicState::KinematicState():
    pos_meters(),
    velocity_mps(),
    acceleration_mps2(),
    jerk_mps3()
{
}

KinematicState::~KinematicState()
{
}

TargetAmplification::TargetAmplification():
    name("TestTarget"),
    inputFile("NOT_SET")
{
}

TargetAmplification::~TargetAmplification()
{
}

TargetResponse::TargetResponse():
    rcs_db(10.0, WATT)  // TODO - default test value
{
}

TargetResponse::~TargetResponse()
{
}

Target::Target():
    truthId(0),
    state(),
    targetAmp(),
    targetResponse()
{
}

Target::~Target()
{
}
