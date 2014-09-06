/***************************************************************************
 *  @file       tiles.hpp
 *  @author     Yue Wang
 *  @date       6  Sep 2014
 *  @version
 *  @remark     implemented for tiny-mahjong
 ***************************************************************************/
#ifndef TILES_HPP
#define TILES_HPP

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

inline bool
is_honor(const std::string& pile_type)
{
    auto iter_found = std::find(honor.begin(), honor.end(), pile_type);
    return iter_found != honor.end();
}
}//namespace data

/**
 * @brief The tile struct
 */
struct Tile
{
    using SizeType  =   std::size_t;

    std::string title() const
    {
        return  data::is_honor(type)?  type  :  type + std::to_string(value);
    }

    std::ostream& print() const
    {
        std::cout << title();
        return std::cout;
    }

    std::string type;
    SizeType value;
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
 */
inline Tile
operator +(const Tile& lhs, Tile::SizeType rhs)
{
    bool is_honor = data::is_honor(lhs.type);
    return is_honor?    Tile{lhs.type, 100}     :   Tile{lhs.type,  lhs.value + rhs};
}

/**
 * @brief a box of mahjong tiles
 */
class Box
{
public:
    using Container =   std::vector<mj::Tile>;
    using SizeType  =   typename Container::size_type;
    using CIter     =   typename Container::const_iterator;

    /**
     * @brief default Ctor
     */
    explicit Box():
        vec(construct_and_sort())
    {}

    /**
     * @brief operator []
     */
    const Tile& operator [](SizeType index) const
    {
        return vec[index];
    }

    /**
     * @brief begin
     */
    CIter begin()const
    {
        return vec.cbegin();
    }

    /**
     * @brief end
     */
    CIter end()const
    {
        return vec.cend();
    }

    /**
     * @brief print
     */
    std::ostream& print()const
    {
        std::size_t count = 0;
        for(const auto& elem : vec)
        {
            std::cout << elem
                      << (count++ == 3?   "\n"    :   " ");
            count %= 4;
        }

        std::cout << std::endl << vec.size() << " tiles in all";

        return std::cout;
    }

    /**
     * @brief size
     * @return
     */
    SizeType size()const
    {
        return vec.size();
    }

private:
    Container vec;

    /**
     * @brief construct_and_sort
     * @return  a vector storing all tiles inserted.
     */
    Container construct_and_sort()
    {
        Container ret{};

        //! insert all tiles
        for(std::size_t four = 0; four != 4; ++four)
        {
            for(const auto& elem :  data::suit)
                for(std::size_t val = 0; val != 9; ++val)
                    ret.push_back({elem, val + 1});

            for(const auto& elem :  data::honor)
                ret.push_back({elem, 0});
        }

        //! sort
        std::sort(ret.begin(), ret.end());

        return ret;
    }
};



}//namespace
#endif // TILES_HPP

//! @test   for Tile
//!
//#include <iostream>
//#include <tiles.hpp>

//int main()
//{
//    mj::Tile tile{"dot", 9};
//    std::cout << tile;

//    return 0;
//}

//! @test   for Box
//!
//#include <iostream>
//#include <tiles.hpp>

//int main()
//{
//    mj::Box box{};

//    std::cout << box[9].type << std::endl;
//    std::cout << box[0].title() << std::endl;

//    for(const auto& elem    :   box)
//        std::cout << elem.title() << " ";

//    std::cout << "\nexit normally\n";
//    return 0;
//}
