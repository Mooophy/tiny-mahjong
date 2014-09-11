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

    Game(std::size_t size):
        box{mj::build_box<Vector>()},
        sequence{mj::generate_random_sequence<SequenceType>()},
        all_players(size)
    {
        all_players[0] = std::make_shared<mj::Human<Vector>>();

        for(unsigned sz = 1; sz != size; ++sz)
            all_players[sz] = std::make_shared<mj::Npc<Vector>>();

        init_in_hand_for_all_players();
    }

    void play();

private:
    Vector box;
    SequenceType sequence;
    AllPlayersType all_players;

    /**
     * @brief init_in_hand_for_all_players
     */
    void init_in_hand_for_all_players()
    {
        //! 13 tiles each player
        for(unsigned u = 0; u != 13; ++u)
            for(auto& player : all_players)
            {
                const auto& tile = box[sequence.back()];
                player->draw(tile);
                sequence.pop_back();
            }

        //! the 14th tile for maker
        //! i.e.human player in this version
        const auto& tile_for_maker = box[sequence.back()];
        all_players[0]->draw(tile_for_maker);
        sequence.pop_back();
    }
};

}//namespace

#endif // GAME_H
