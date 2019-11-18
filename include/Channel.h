#pragma once
#include <vector>
#include <complex>
#include "ChannelMeta.h"

// Define Channel Data Type
typedef std::complex<double> ch_complex;
typedef std::vector<ch_complex> ch_data;

class Channel
{
    private:
        ChannelMeta meta;
        ch_data d;
    public:
        Channel();
        ~Channel();

        // Data Mutators
        void resize(size_t newSize);
        void clear();
        void fill(const ch_complex fillValue);

        ch_data::iterator begin();
        ch_data::const_iterator begin() const;
        ch_data::iterator end();
        ch_data::const_iterator end() const;
        void setMeta(ChannelMeta meta_in);
        void applyMeta();
};
