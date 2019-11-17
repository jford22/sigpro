#include "Channel.h"
#include <vector>

Channel::Channel():
    meta(),
    d()
{
}
Channel::~Channel()
{
}

// Data Mutators
void Channel::resize(size_t newSize)
{
    d.resize(newSize);
}

void Channel::clear()
{
    d.clear();
}

void Channel::fill(const std::complex<double> fillValue)
{
    std::fill(d.begin(), d.end(), fillValue);
}

// Iterator Function passthroughs
ch_data::iterator Channel::begin()
{
    return d.begin();
}
ch_data::const_iterator Channel::begin() const
{
    return d.begin();
}
ch_data::iterator Channel::end()
{
    return d.end();
}
ch_data::const_iterator Channel::end() const
{
    return d.end();
}
