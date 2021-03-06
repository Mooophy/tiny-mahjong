#ifndef GAME_H
#define GAME_H

#include <deque>
#include <memory>
#include "tile.hpp"
#include "player.hpp"
#include "random_sequence.hpp"
#include "win.hpp"

namespace mj{

class Game
{
public:
    using Vector        =   std::vector<mj::Tile>;
    using SequenceType  =   std::deque<std::size_t>;
    using AllPlayersType=   std::vector<std::shared_ptr<mj::Player<Vector>>>;

    Game(std::size_t sz = 2):
        box{mj::build_box<Vector>()},
        sequence{mj::generate_random_sequence<SequenceType>()},
        on_board{},
        all_players(sz)
    {
        allocate_all_players(sz);
        init_in_hand_for_all_players();
    }

    void play();

private:
    Vector box;
    SequenceType sequence;
    Vector on_board;
    AllPlayersType all_players;

    void allocate_all_players(std::size_t size);
    void init_in_hand_for_all_players();
    void show_tiles_on_board();
    std::ostream& game_start_prompt();
    std::ostream& game_end_prompt();
};

}//namespace

#endif // GAME_H

//! @test
//!
//#include <iostream>
//#include <game.h>
//#include "player.hpp"
//#include "tile.hpp"

//int main()
//{
//    mj::Game game(2);
//    game.play();

//    std::cout << "exit normally\n";
//    return 0;
//}
