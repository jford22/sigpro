#pragma once
#include "Enums.h"

class DeciBel
{
    private:
        double value_dB;
        UNITS ref_unit;
        double ref_factor;
    public:
        // Static Functions
        static double getDbRefFactor(UNITS ref_unit);
        static double from_dB(double value_in_dB, UNITS ref_type); 
        static double to_dB(double value_in_unit, UNITS ref_type);

        // Member only Functions
        DeciBel(double  init_value_in_dB, UNITS ref_unit_in);
        ~DeciBel();
        void set_dB(double value_db_in, UNITS ref_unit);
        double get_dB() { return value_dB;};
        double get_unit(UNITS ref_unit_in);
};
