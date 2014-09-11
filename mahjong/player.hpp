#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <algorithm>
#include "win.hpp"

namespace mj {

template<typename Container>
class Player
{
public:
    using ValueType =   typename Container::value_type;
    using SizeType  =   typename Container::size_type;

    Player(const Container& c):
        in_hand{c}
    {}

    Player(Container &&c):
        in_hand{std::move(c)}
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
    virtual SizeType consider() const = 0;
};

template<typename Container>
class Npc : public Player<Container>
{
public:
    using Base = mj::Player<Container>;
    using Base::Player;

private:
    virtual typename Base::SizeType consider() const override
    {
        return ai();
    }

    typename Base::SizeType ai()const
    {
        return 3;
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
