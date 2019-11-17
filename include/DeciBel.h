#pragma once

enum dB_REF_UNIT {
    WATT,
    VOLT,
    MILLIWATT,
    MILLIVOLT,
    METER_SQ,
    METER};

class DeciBel
{
    private:
        double value_dB;
        dB_REF_UNIT ref_unit;
        double ref_factor;
    public:
        // Static Functions
        static double getDbRefFactor(dB_REF_UNIT ref_unit);
        static double from_dB(double value_in_dB, dB_REF_UNIT ref_type); 
        static double to_dB(double value_in_unit, dB_REF_UNIT ref_type);

        // Member only Functions
        DeciBel(double  init_value_in_dB, dB_REF_UNIT ref_unit_in);
        ~DeciBel();
        void set_dB(double value_db_in, dB_REF_UNIT ref_unit);
        double get_dB() { return value_dB;};
        double get_unit(dB_REF_UNIT ref_unit_in);
};
