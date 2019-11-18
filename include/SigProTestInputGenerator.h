#pragma once

#include "Target.h"
#include "TxRxMeta.h"

#include <map>

class SigProTestInputGenerator
{
    private:
        std::map<unsigned int,TxRxMeta> control_set;
        std::map<unsigned int,Target> target_set;
    public:
        SigProTestInputGenerator();
        ~SigProTestInputGenerator();

        std::map<unsigned int,TxRxMeta>& generateControl(unsigned int numPRIs, unsigned int set_selector=0);
        std::map<unsigned int,Target>&   generateTargets(unsigned int numTargets, unsigned int set_selector=0);
        void buildControl();
        void buildTarget();
};
