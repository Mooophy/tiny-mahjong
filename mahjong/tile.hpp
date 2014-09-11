#ifndef TILE_HPP
#define TILE_HPP

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

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
    friend bool operator==(const Tile& lhs, const Tile& rhs);
public:
    using ValueType  =   std::size_t;
    Tile(bool cnt, const std::string& tp, ValueType val = 0):
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

inline bool
operator ==(const Tile& lhs, const Tile& rhs)
{
    return (lhs.countable    ==  rhs.countable)
            &&  (lhs.type    ==  rhs.type)
            &&  (lhs.value   ==  rhs.value);
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

template<typename Container>
inline Container build_box()
{
    Container box{};
    //! insert all tiles
    for(auto four = 0; four != 4; ++four)
    {
        for(const auto& elem :  data::suit)
            for(unsigned val = 0; val != 9; ++val)
                box.push_back({true, elem, val + 1});

        for(const auto& elem :  data::honor)
            box.push_back({false, elem, 0});
    }

    //! sort
    std::sort(box.begin(), box.end());

    return box;

}

}//namespace
#endif // TILE_HPP

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

//! @test
//!
//#include <iostream>
//#include <tile.hpp>

//int main()
//{
//    auto box = mj::build_box<std::vector<mj::Tile>>();
//    for(const auto& tile : box)
//        tile.print() << "\n";

//    std::cout << "exit normally\n";
//    return 0;
//}
