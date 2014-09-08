#include <iostream>
#include <tile.h>
#include "in_hand.hpp"

int main()
{
    mj::InHand<mj::Tile> in_hand;
    in_hand.push_back({true , "bam", 4});
    in_hand.push_back({true , "bam", 3});
    in_hand.push_back({true , "bam", 2});
    in_hand.push_back({true , "bam", 1});
    in_hand.push_back({true , "bam", 6});
    in_hand.push_back({true , "bam", 9});

    in_hand.draw({true , "dot", 2});

    for(const auto& elem : in_hand)
        elem.print()<<std::endl;

    in_hand.bring_out(3).print();

    std::cout << "\nexit normally\n";
    return 0;
}

