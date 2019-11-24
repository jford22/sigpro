#include "Channel.h"
#include <vector>
#include <iostream>

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

void Channel::setMeta(ChannelMeta meta_in) 
{ 
    meta = meta_in;
    applyMeta();
}

void Channel::applyMeta()
{
    resize(meta.getNumberOfBins());
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

bool Channel::compatibilityTest(const Channel& lhs, const Channel& rhs)
{
    bool areCompatible = true;
    if( lhs.getConstMeta().getRangeStep_meters() != rhs.getConstMeta().getRangeStep_meters() )
    {
        std::cerr << "ERROR: Channel binSizes are not compatible" << std::endl;
        areCompatible = false;
    }
    return areCompatible;
}

bool Channel::determineIntersectIndices(const Channel& lhs, 
                                        const Channel& rhs,
                                        unsigned int& lhs_start_idx, 
                                        unsigned int& rhs_start_idx,
                                        unsigned int& lhs_stop_idx,
                                        unsigned int& rhs_stop_idx)
{
    bool intersectFound = false;
    const double lhs_start_time_sec = lhs.getConstMeta().getStartTime_seconds();
    const double rhs_start_time_sec = rhs.getConstMeta().getStartTime_seconds();
    const double lhs_stop_time_sec  = lhs.getConstMeta().getStopTime_seconds();
    const double rhs_stop_time_sec  = rhs.getConstMeta().getStopTime_seconds();

    // Determine Start Indices
    // -- If RHS start Time is within LHS time window
    if ( lhs.getConstMeta().containsTime(rhs_start_time_sec) )
    {
        intersectFound = true;
        rhs_start_idx = 0;
        lhs_start_idx = lhs.getConstMeta().getIndexForTime( rhs_start_time_sec);
    }
    //-- If LHS start Time is within RHS time window
    else if ( rhs.getConstMeta().containsTime(lhs_start_time_sec) )
    {
        intersectFound = true;
        lhs_start_idx = 0;
        rhs_start_idx = rhs.getConstMeta().getIndexForTime( lhs_start_time_sec);
    }
    if (intersectFound )
    {
        // Determine Stop Indices
        // -- If RHS stop Time is within LHS time window
        if ( lhs.getConstMeta().containsTime(rhs_stop_time_sec) )
        {
            rhs_stop_idx = 0;
            lhs_stop_idx = lhs.getConstMeta().getIndexForTime( rhs_stop_time_sec);
        }
        //-- If LHS stop Time is within RHS time window
        else if ( rhs.getConstMeta().containsTime(lhs_stop_time_sec) )
        {
            lhs_stop_idx = 0;
            rhs_stop_idx = rhs.getConstMeta().getIndexForTime( lhs_stop_time_sec);
        }
    }
    return intersectFound;
}

Channel& Channel::operator+=(const Channel& rhs)
{
    bool passCompatibilityTest = compatibilityTest(*this, rhs);

    if( passCompatibilityTest )
    {
        unsigned int lhs_start_idx, rhs_start_idx, lhs_stop_idx, rhs_stop_idx = 0;
        bool hasIntersect = determineIntersectIndices(*this, rhs, lhs_start_idx, rhs_start_idx, lhs_stop_idx, rhs_stop_idx);
        if( hasIntersect )
        {
            std::cout << "Intersect Found" << std::endl;
            std::cout << "LHS_IDXs = [ " << lhs_start_idx << " , " << lhs_stop_idx << " ]" << std::endl;
            std::cout << "RHS_IDXs = [ " << rhs_start_idx << " , " << rhs_stop_idx << " ]" << std::endl;
            // Do Math
        }
    }
    return *this;
}
