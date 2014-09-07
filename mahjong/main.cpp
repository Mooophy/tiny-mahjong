#include <iostream>
#include "game_master.h"
#include "win.hpp"

int main()
{
    //! init and sort
    mj::GameMaster gm;
    std::vector<mj::Tile> tiles{
        {false, "Bai"},
        {false, "Bai"},
        {false, "Zho"},
        {false, "Zho"},
        {false, "Zho"},
        {true , "dot", 1},
        {true , "dot", 2},
        {true , "dot", 3},
        {true , "bam", 5},
        {true , "bam", 6},
        {true , "bam", 7},
        {true , "bam", 2},
        {true , "bam", 3},
        {true , "bam", 4},
    };
    std::sort(tiles.begin(), tiles.end());

    //! print
    for(const auto& elem : tiles)
        elem.print()<< "\n";

    //! check if win
    if(mj::check_if_win(tiles.begin(),tiles.end()))
        std::cout << "you win\n";
    else
        std::cout << "not won yet\n";


    std::cout << "\nexit normally\n";
    return 0;
}

