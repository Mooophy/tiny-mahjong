#ifndef TILE_H
#define TILE_H

#include <string>
#include <iostream>
#include <vector>

namespace mj {

namespace data{
const std::vector<std::string> honor
{
    "Eas", "Sou","Wes","Nor", "Zho", "Fah", "Bai"
};

const std::vector<std::string> suit
{
    "dot", "bam", "cha"
};
}//namespace data

/**
 * @brief The Tile class
 */
class Tile
{
    friend Tile operator +(const Tile& lhs, std::size_t rhs);
public:
    using ValueType  =   std::size_t;
    Tile(bool cnt, const std::string& tp, ValueType val):
        countable{cnt},type{tp},value{val}
    {}

    std::string title()const
    {
        return countable?   type + std::to_string(value)  :   type;
    }

    std::ostream& print()const
    {
        std::cout << title();
        return std::cout;
    }

private:
    bool countable;
    std::string type;
    ValueType value;
};

/**
 * @brief operator <<
 * @param os
 * @param tl
 */
inline std::ostream&
operator <<(std::ostream& os, const Tile& tl)
{
    os << tl.title();
    return os;
}

/**
 * @brief operator <
 * @param lhs
 * @param rhs
 */
inline bool
operator <(const Tile& lhs, const Tile& rhs)
{
    return lhs.title() < rhs.title();
}

/**
 * @brief operator +
 * @param lhs
 * @param rhs
 * @return  Tile
 */
inline Tile
operator +(const Tile& lhs, Tile::ValueType rhs)
{
    return lhs.countable ?
                Tile{lhs.countable, lhs.type, lhs.value + rhs} :
                Tile{lhs.countable, lhs.type, 100};
}

}//namespace
#endif // TILE_H

//! @test
//!
//#include <iostream>
//#include "tile.h"

//int main()
//{
//    mj::Tile tile{true, "dot", 2};
//    tile.print();
//    std::cout << tile + 1 << std::endl;

//    std::cout << "exit normally\n";
//    return 0;
//}
//! @output
//!
//dot2dot3
//exit normally
