#include <iostream>
#include <tile.h>
#include "in_hand.hpp"

int main()
{
    mj::InHand<mj::Tile> in_hand;
    in_hand.push_back({true , "bam", 1});
    in_hand.push_back({true , "bam", 2});
    in_hand.push_back({true , "bam", 3});

    in_hand.push_back({true , "bam", 4});
    in_hand.push_back({true , "bam", 5});
    in_hand.push_back({true , "bam", 6});

    in_hand.push_back({true , "bam", 7});
    in_hand.push_back({true , "bam", 8});
    in_hand.push_back({true , "bam", 9});

    in_hand.push_back({true , "bam", 7});
    in_hand.push_back({true , "bam", 8});
    in_hand.push_back({true , "bam", 9});

    in_hand.push_back({true , "bam", 1});
    in_hand.push_back({true , "bam", 1});

    for(const auto& elem : in_hand)
        elem.print()<<std::endl;

    std::cout << in_hand.did_win();

    std::cout << "\nexit normally\n";
    return 0;
}

