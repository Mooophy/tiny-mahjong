#include <iostream>
#include "player.hpp"
#include "tile.hpp"
#include <memory>

int main()
{
    //! init an npc
    using Vec = std::vector<mj::Tile>;
    Vec tiles{
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
    };
    std::shared_ptr<mj::Player<Vec>> npc
            = std::make_shared<mj::Npc<Vec>>(std::move(tiles));
    std::cout << (npc->win()?    "you win!\n"   :   "not win yet..\n");

    //! draw
    npc->draw({true , "bam", 1});
    std::cout << (npc->win()?    "you win!\n"   :   "not win yet..\n");

    //! bring out
    npc->bring_out().print() << std::endl;

    std::cout << "exit normally\n";
    return 0;
}
