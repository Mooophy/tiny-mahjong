#ifndef PLAYER_H
#define PLAYER_H

#include "tile.h"
#include "in_hand.hpp"
#include <vector>

namespace mj{

/**
 * @brief abastract class
 */
class player
{
public:
    player():
        in_hand{}
    {}

    void draw(const mj::Tile& tl)
    {
        in_hand.push_back(tl);
    }
protected:
    mj::InHand in_hand;

private:

};

}//namespace
#endif // PLAYER_H
