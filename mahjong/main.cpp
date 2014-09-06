#include <iostream>
#include <tiles.hpp>
#include "game_master.hpp"
#include "random_sequence.hpp"

int main()
{
    mj::GameMaster gm;

    std::cout << "Pls enter:\n";
    for(std::string buff; std::cin >> buff;/* */)
        gm.license().print() << std::endl;

    std::cout << "\nexit normally\n";
    return 0;
}

