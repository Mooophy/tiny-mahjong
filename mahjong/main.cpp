#include <iostream>
#include "tile.hpp"
#include "random_sequence.hpp"
#include <deque>

int main()
{
    auto box = mj::build_box<std::vector<mj::Tile>>();
    auto sequence = mj::generate_random_sequence<std::deque<unsigned>>();

    for(unsigned u = 0; u != box.size(); ++u)
    {
        box[sequence.back()].print() << " u=" << u << "\n";
        sequence.pop_back();
    }

    std::cout << "exit normally\n";
    return 0;
}
