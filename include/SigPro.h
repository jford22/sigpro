#pragma once
#include "Signal.h"

#include <map>

class Signal;
class TxRxMeta;
class Target;

class SigPro
{
    private:
        Signal * signal;
        std::map<unsigned int,TxRxMeta> control_set;
        std::map<unsigned int,Target>   target_set;

    public:
        SigPro();
        ~SigPro();
        void setupSignal(); 
        void generateScene();
};
