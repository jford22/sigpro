#include "NoiseDecorator.h"
#include "SignalDecorator.h"

NoiseDecorator::NoiseDecorator(Signal *s): SignalDecorator(s),
    child(s)
{
}
