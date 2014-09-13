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
        all_players(sz),
        on_board{}
    {
        allocate_all_players(sz);
        init_in_hand_for_all_players();
    }

    void play();

private:
    Vector box;
    SequenceType sequence;
    AllPlayersType all_players;
    Vector on_board;

    void allocate_all_players(std::size_t size);
    void init_in_hand_for_all_players();
};

}//namespace

#endif // GAME_H
