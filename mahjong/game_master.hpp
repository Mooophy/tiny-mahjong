#ifndef GAME_MASTER_HPP
#define GAME_MASTER_HPP

#include "tiles.hpp"
#include <random>
#include <vector>

namespace mj {

class GameMaster
{
public:
    using SizeType  =   typename mj::Box::SizeType;
    using OrderType =   typename std::vector<SizeType>;

    GameMaster():
        box{},curr{0}
    {}

//    void shuffle()
//    {

//    }

//    const Tile& license()
//    {

//    }

private:
    const Box box;
    SizeType curr;
    OrderType sequence;

//    OrderType generate_sequece()const
//    {

//    }

};
}//namespace
#endif // GAME_MASTER_HPP
