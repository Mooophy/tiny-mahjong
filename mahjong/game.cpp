#include "game.h"
#include <algorithm>

/**
 * @brief init_in_hand_for_all_players
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
 * @brief allocate_all_players
 */
void mj::Game::allocate_all_players(std::size_t size)
{
    all_players[0] = std::make_shared<mj::Human<Vector>>();

    for(unsigned sz = 1; sz != size; ++sz)
        all_players[sz] = std::make_shared<mj::Npc<Vector>>();
}

/**
 * @brief play
 *
 *  the main process
 */
void mj::Game::play()
{
    game_start_prompt();

    //! check if maker won already:
    if(all_players[0]->win())
    {
        std::cout << "Maker win!\n";
        return;
    }

    //! process
    for(bool end{false}; end != true   &&  !sequence.empty(); sequence.pop_back())
    {
        std::cout << "\n\n\n";

        //! each player
        std::for_each(all_players.begin(), all_players.end(),
                      [&end,this](decltype(*all_players.begin()) player)
        {

            //! draw
            player->draw(box[sequence.back()]);

            //! check if win
            if(player->win())
            {
                std::cout <<    (player == *all_players.begin()?    "you"   :   "PC")
                          <<    "win\n";
                end = true;
            }

            on_board.push_back(player->bring_out());
        });

        std::cout << "\n\n\n";
        show_tiles_on_board();
    }

    game_end_prompt();
}

/**
 * @brief show_tiles_on_board
 */
void mj::Game::show_tiles_on_board()
{
    std::cout << "piles on board:\nlast round:  ";
    for(auto it = on_board.end() - 1; it != on_board.end() - 1 - all_players.size(); --it)
        std::cout << *it << "   ";
    std::cout << "\n";

    for(std::size_t count = 0; count != on_board.size(); ++count)
    {
        on_board[count].print();
        std::cout << ((count + 1) % 10?   "  "    :   "\n");
    }
    std::cout << "\n";
}

/**
 * @brief game_start_prompt
 */
inline std::ostream&
mj::Game::game_start_prompt()
{
    std::cout << "\t\t==WELCOME==\n\n";
    return std::cout;
}

/**
 * @brief game_end_prompt
 */
inline std::ostream&
mj::Game::game_end_prompt()
{
    std::cout << "\t\t==GAME OVER==\n\n";
    return std::cout;
}
