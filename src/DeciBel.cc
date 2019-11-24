#include "DeciBel.h"
#include <iostream>
#include <cmath>
#include "Enums.h"

double DeciBel::getDbRefFactor(UNITS ref_unit)
{
    double reference_factor = 20.0;
    switch(ref_unit)
    {
        case WATT:
        case MILLIWATT:
            reference_factor = 10.0;
            break;
        case VOLT:
        case MILLIVOLT:
            reference_factor = 20.0;
            break;
        case METER_SQ:  // TODO - not sure if this is needed or what is value is right off
        case METER:
            reference_factor = 40.0;  // TODO Check this out - Usually R^4
        default:
            break;
    }
    return reference_factor;
}

double DeciBel::from_dB(double value_in_dB, UNITS ref_type) 
{
    const double ref_factor = getDbRefFactor(ref_type);
    const double value_in_unit = std::pow(10.0 , value_in_dB / ref_factor );
    return value_in_unit;
}

double DeciBel::to_dB(double value_in_unit, UNITS ref_type)
{
    const double ref_factor = getDbRefFactor(ref_type);
    const double value_in_dB = ref_factor * std::log10(value_in_unit);
    return value_in_dB;
}

DeciBel::DeciBel(double  init_value_in_dB, UNITS ref_unit_in):
    value_dB(init_value_in_dB),
    ref_unit(ref_unit_in),
    ref_factor(10.0)
{
    ref_factor = getDbRefFactor(ref_unit);
}

DeciBel::~DeciBel()
{
}


void DeciBel::set_dB(double value_db_in, UNITS ref_unit_in)
{
    value_dB = value_db_in;
    ref_unit = ref_unit_in;
    ref_factor = getDbRefFactor(ref_unit);
}

double DeciBel::get_unit(UNITS ref_unit_in)
{
    if(ref_unit_in != ref_unit)
    {
        std::cerr << "WARNING: DB Ref_Unit requested does not match set value" << std::endl;
    }
    return from_dB(value_dB, ref_unit_in);
}
