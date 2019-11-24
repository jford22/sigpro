#include "ChannelMeta.h"
#include "Constants.h"

long ChannelMeta::getIndexForTime(double time_in_sec) const
{
    const double timeDelta_sec = time_in_sec - time.getStart();
    const double binSize_sec = range.getStep() / LIGHTSPEED_m_p_sec;
    const double binOffsetForDelta = timeDelta_sec / binSize_sec;
    const long fullIndex = std::floor(binOffsetForDelta);
    //const double remainder = binOffsetForDelta - (double)fullIndex;
    return fullIndex;
}

bool ChannelMeta::containsTime(double time_in_sec) const
{
    const bool isTimeBefore = time_in_sec < time.getStart();
    const bool isTimeAfter  = time_in_sec > time.getStop();

    return !(isTimeBefore && isTimeAfter);
}
