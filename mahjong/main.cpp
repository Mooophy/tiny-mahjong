#include <iostream>
#include "tile.h"


int main()
{
    mj::Tile tile{true, "dot", 2};

    tile.print();
    std::cout << tile + 1 << std::endl;



    return 0;
}

