#pragma once
#include "Signal.h"
class Signal;

class SigPro
{
    private:
        Signal * signal;
    public:
        SigPro();
        ~SigPro();
        void setupSignal(); 
        void generateScene();
};
