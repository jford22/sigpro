#include "Target.h"
#include <cmath>

State::State():
    x(0.0),
    y(0.0),
    z(0.0)
{
}

State::State(double x_in, double y_in, double z_in):
    x(x_in),
    y(y_in),
    z(z_in)
{
}

State::~State()
{
}

double State::getMagnitude()
{
    const double magsqr = x*x + y*y + z*z;
    const double mag = std::sqrt(magsqr);
    return mag;
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

double KinematicState::getRange()
{
    return pos_meters.getMagnitude();
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
