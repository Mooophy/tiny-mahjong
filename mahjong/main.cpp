#include <iostream>
#include <tiles.hpp>
#include "game_master.hpp"
#include "random_sequence.hpp"

int main()
{
    std::vector<int> v {1,2,3,4,5};
    mj::make_random(v.begin(), v.end());

    for(auto elem : v)
        std::cout << elem << " ";

    std::cout << "\nexit normally\n";
    return 0;
}

