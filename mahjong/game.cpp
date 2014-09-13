#include "game.h"

/**
 * @brief mj::Game::init_in_hand_for_all_players
 */
void mj::Game::init_in_hand_for_all_players()
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

/**
 * @brief mj::Game::allocate_all_players
 */
void mj::Game::allocate_all_players(std::size_t size)
{
    all_players[0] = std::make_shared<mj::Human<Vector>>();

    for(unsigned sz = 1; sz != size; ++sz)
        all_players[sz] = std::make_shared<mj::Npc<Vector>>();
}

void mj::Game::play()
{
    game_start_prompt();

    //! check if maker won already:
    if(all_players[0]->win())
    {
        std::cout << "Maker win!\n";
        return;
    }

    //! game start
    for(bool end{false}; end != true   &&  !sequence.empty(); sequence.pop_back())
    {
        //! each player
        for(auto curr = all_players.begin(); curr != all_players.end(); ++curr)
        {
            //! draw
            const auto& tile = box[sequence.back()];
            (*curr)->draw(tile);

            //! check if win
            if((*curr)->win())
            {
                std::cout <<    (curr == all_players.begin()?    "you"   :   "PC")
                          <<    "win\n";
                end = true;
            }

            //! bring out
            on_board.push_back((*curr)->bring_out());
        }

        show_tiles_on_board();
    }


    std::cout << "==Game end==.\n";
}

void mj::Game::show_tiles_on_board()
{
    std::cout << "piles on board:\n";
    for(std::size_t count = 0; count != on_board.size(); ++count)
    {
        on_board[count].print();
        std::cout << ((count + 1) % 10?   "  "    :   "\n");
    }
    std::cout << "\n";
}

inline void mj::Game::game_start_prompt()
{
    std::cout << "\t\t==WELCOME==\n\n";
}
