#include <iostream>
#include <memory>
#include <game.h>
#include "player.hpp"
#include "tile.hpp"

int main()
{
    mj::Game game(2);

    game.play();

    std::cout << "exit normally\n";
    return 0;
}
