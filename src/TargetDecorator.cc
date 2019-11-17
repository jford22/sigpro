#include "TargetDecorator.h"

TargetDecorator::TargetDecorator(Signal *s): SignalDecorator(s),
    child(s),
    targetContributions()
{
}

// Interface Methods to Implement
void TargetDecorator::init()
{
    child->init();
    std::cout << "init() - TargetDecorator" << std::endl;
    targetContributions.clear();
}
void TargetDecorator::setup()
{
    child->setup();
    std::cout << "setup() - TargetDecorator" << std::endl;
}
void TargetDecorator::stage()
{
    child->stage();   // Child call
    std::cout << "stage() - TargetDecorator" << std::endl;
    buildTargetResponse();
}
void TargetDecorator::contribute()
{
    child->contribute();   // Child call
    std::cout << "contribute() - TargetDecorator" << std::endl;
}

// Generate Target Response
void TargetDecorator::buildTargetResponse()
{
}
