#include "main.h"
#include <iostream>
#include "SigPro.h"

int main(int argc, char* argv[])
{
    if(argc)
    {
        std::cout << "Num Arguements: " <<  argc << std::endl;
        for(int argIdx = 0; argIdx < argc; ++argIdx)
        {
            std::cout << "\t" << argIdx << ": "  << argv[argIdx] << std::endl;
        }
    }
    //Channel ch1();
    SigPro sigPro;
    sigPro.setupSignal();
    sigPro.generateScene();

    
    std::cout << "Done - GoodBye" << std::endl;
    return 0;
}
