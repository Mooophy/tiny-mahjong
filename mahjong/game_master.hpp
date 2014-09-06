/***************************************************************************
 *  @file       game_master.hpp
 *  @author     Yue Wang
 *  @date       6  Sep 2014
 *  @version
 *  @remark     implemented for tiny-mahjong
 ***************************************************************************/
#ifndef GAME_MASTER_HPP
#define GAME_MASTER_HPP

#include "tiles.hpp"
#include "random_sequence.hpp"
#include <random>
#include <vector>

namespace mj {

/**
 * @brief The GameMaster class
 */
class GameMaster
{
public:
    using SizeType  =   typename mj::Box::SizeType;
    using OrderType =   typename std::vector<SizeType>;

    /**
     * @brief default Ctor
     */
    GameMaster():
        box{},curr{0},sequence{generate_sequece()}
    {}

    /**
     * @brief shuffle
     */
    GameMaster& shuffle()
    {
        sequence = generate_sequece();
        curr = 0;

        return *this;
    }

    /**
     * @brief license
     */
    const Tile& license()
    {
        return box[sequence[curr++]];
    }

    /**
     * @brief current
     */
    SizeType current()const
    {
        return curr;
    }

private:
    const Box box;
    SizeType curr;
    OrderType sequence;

    OrderType generate_sequece()const
    {
        OrderType seq{};
        for(SizeType index = 0; index != box.size(); ++index)
            seq.push_back(index);

        mj::make_random(seq.begin(), seq.end());

        return seq;
    }

};
}//namespace
#endif // GAME_MASTER_HPP
