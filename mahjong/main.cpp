#include <iostream>
#include "game_master.h"
int main()
{
    mj::GameMaster gm;
    for(auto i = 0; i != 136; ++i)
        gm.license().print() << "\n";

    std::cout << "exit normally\n";
    return 0;
}

