#include "SignalDecorator.h"
#include "NoiseDecorator.h"
#include <random>

NoiseDecorator::NoiseDecorator(Signal *s): SignalDecorator(s),
    child(s),
    staged_noise()
{
}

// Interface Methods to Implement
void NoiseDecorator::init()
{
    child->init();
    std::cout << "init() - NoiseDecorator" << std::endl;
    size_t size = 10;
    staged_noise.resize(size);
}
void NoiseDecorator::setup()
{
    child->setup();
    std::cout << "setup() - NoiseDecorator" << std::endl;
}
void NoiseDecorator::stage()
{
    child->stage();   // Child call
    std::cout << "stage() - NoiseDecorator" << std::endl;
    generateGaussianWhiteNoise();
}
void NoiseDecorator::contribute()
{
    child->contribute();   // Child call
    std::cout << "contribute() - NoiseDecorator" << std::endl;
}

// Generate Guassian Normal Noise
void NoiseDecorator::generateGaussianWhiteNoise()
{
    double mean = 0.0;
    double std_dev = 1.0;
    std::random_device randDevice;
    std::mt19937 e2(randDevice());
    std::normal_distribution<> dist(mean, std_dev);
    for(auto noiseSample : staged_noise)
    {
        noiseSample = dist(e2);
        std::cout << "Rand Call Returns: " << noiseSample << std::endl;
    }
}
