#include <iostream>
#include "player.hpp"
#include "tile.hpp"
#include <memory>
#include <game.h>

int main()
{
    mj::Game game(2);

    game.play();

    std::cout << "exit normally\n";
    return 0;
}
