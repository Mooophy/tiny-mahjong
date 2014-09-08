#ifndef PLAYER_H
#define PLAYER_H

#include "tile.h"
#include <vector>

namespace mj{

/**
 * @brief abastract class
 */
class player
{
public:
    using Container =   std::vector<mj::Tile>;

    player():
        in_hand{}
    {}

    void draw(const tile& tl)
    {
        in_hand.push_back(tl);

        //  switch to develop in_hand.hpp.
    }
protected:
    Container in_hand;

private:

};

}//namespace
#endif // PLAYER_H
