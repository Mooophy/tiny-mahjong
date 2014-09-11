#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include "win.hpp"


namespace mj {

/**
 * @brief Player class
 */
template<typename Container>
class Player
{
public:
    using ValueType =   typename Container::value_type;
    using SizeType  =   typename Container::size_type;

    Player():
        in_hand{}
    {}

    Player(const Container& c):
        in_hand{c}
    {}

    void draw(const ValueType& tile)
    {
        in_hand.push_back(tile);
        std::sort(in_hand.begin(), in_hand.end());
    }

    bool win() const
    {
        return mj::check_if_win(in_hand.begin(), in_hand.end());
    }

    /**
     * @brief bring_out
     *
     * using virtual consider()
     */
    ValueType bring_out()
    {
        std::swap(in_hand.back(), in_hand[consider()]);

        auto ret = in_hand.back();
        in_hand.resize(in_hand.size() - 1);

        return ret;
    }


    virtual ~Player(){}

protected:
    Container in_hand;

private:
    /**
     * @brief consider
     *
     * absolute virtual function
     */
    virtual SizeType consider() const = 0;
};

/**
 * @brief The Npc class
 */
template<typename Container>
class Npc : public Player<Container>
{
public:
    using Base = mj::Player<Container>;
    using Base::Player;
    using SizeType  =   typename Base::SizeType;

private:
    /**
     * @brief consider
     *
     * virtual
     */
    virtual SizeType consider() const override
    {
        return ai();
    }

    /**
     * @brief ai
     *
     * to be implemented.
     */
    SizeType ai()const
    {
        return 3;
    }
};

template<typename Container>
class Human : public Player<Container>
{
public:
    using Base = mj::Player<Container>;
    using Base::Player;
    using SizeType  =   typename Base::SizeType;

private:
    /**
     * @brief consider
     *
     * virtual
     */
    virtual SizeType consider() const override
    {
        return interact();
    }

    /**
     * @brief interact
     */
    SizeType interact()const
    {
        for(unsigned u = 0; u != 14; ++u)
            std::cout << u << " : [" << Base::in_hand[u] << "]  ";

        std::cout << "\nwhich to bring out? type 0 to 13\n";
        SizeType input;
        std::cin >> input;

        if(input <= 13  &&  input >= 0)
            return input;
        else
            throw std::out_of_range{"out ot range"};
    }
};

}//namespace
#endif // PLAYER_HPP

//! @test   player and npc
//!
//#include <iostream>
//#include "player.hpp"
//#include "tile.hpp"
//#include <memory>

//int main()
//{
//    //! init an npc
//    using Vec = std::vector<mj::Tile>;
//    Vec tiles{
//        {false, "Bai"},
//        {false, "Bai"},
//        {false, "Zho"},
//        {false, "Zho"},
//        {false, "Zho"},
//        {true , "dot", 1},
//        {true , "dot", 2},
//        {true , "dot", 3},
//        {true , "bam", 5},
//        {true , "bam", 6},
//        {true , "bam", 7},
//        {true , "bam", 2},
//        {true , "bam", 3},
//    };
//    std::shared_ptr<mj::Player<Vec>> npc
//            = std::make_shared<mj::Npc<Vec>>(std::move(tiles));
//    std::cout << (npc->win()?    "you win!\n"   :   "not win yet..\n");

//    //! draw
//    npc->draw({true , "bam", 1});
//    std::cout << (npc->win()?    "you win!\n"   :   "not win yet..\n");

//    //! bring out
//    npc->bring_out().print() << std::endl;

//    std::cout << "exit normally\n";
//    return 0;
//}
//! @output
//!
//not win yet..
//you win!
//Zho
//exit normally

//! @output
//!
//#include <iostream>
//#include "player.hpp"
//#include "tile.hpp"
//#include <memory>

//int main()
//{
//    //! init a human
//    using Vec = std::vector<mj::Tile>;
//    Vec tiles{
//        {false, "Bai"},
//        {false, "Bai"},
//        {false, "Zho"},
//        {false, "Zho"},
//        {false, "Zho"},
//        {true , "dot", 1},
//        {true , "dot", 2},
//        {true , "dot", 3},
//        {true , "bam", 5},
//        {true , "bam", 6},
//        {true , "bam", 7},
//        {true , "bam", 2},
//        {true , "bam", 3},
//    };
//    std::shared_ptr<mj::Player<Vec>> player
//            = std::make_shared<mj::Human<Vec>>(std::move(tiles));
//    std::cout << (player->win()?    "you win!\n"   :   "not win yet..\n");

//    //! draw
//    player->draw({true , "bam", 1});
//    std::cout << (player->win()?    "you win!\n"   :   "not win yet..\n");

//    //! bring out
//    player->bring_out().print() << std::endl;

//    std::cout << "exit normally\n";
//    return 0;
//}
//! @output
//!
//not win yet..
//you win!

//which to bring out? type 0 to 13
//3
//Zho
//exit normally

