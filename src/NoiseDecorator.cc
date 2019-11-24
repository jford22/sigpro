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
void NoiseDecorator::setup(const TxRxMeta& txrx_config, Target& target)
{
    child->setup(txrx_config, target);
    std::cout << "setup() - NoiseDecorator" << std::endl;
}
void NoiseDecorator::stage(Channel& channel)
{
    child->stage(channel);   // Child call
    std::cout << "stage() - NoiseDecorator" << std::endl;
    generateGaussianWhiteNoise();
}
void NoiseDecorator::contribute(Channel& channel)
{
    child->contribute(channel);   // Child call
    std::cout << "contribute() - NoiseDecorator" << std::endl;
    channel += staged_noise;
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
