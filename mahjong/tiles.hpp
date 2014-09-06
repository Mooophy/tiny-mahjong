#ifndef TILES_HPP
#define TILES_HPP

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

namespace mj {
namespace data
{
    const std::vector<std::string> honor
    {
        "Eas", "Sou","Wes","Nor", "Zho", "Fah", "Bai"
    };

    const std::vector<std::string> suit
    {
        "dot", "bam", "cha"
    };
}

/**
 * @brief The tile struct
 */
struct Tile
{
    std::string title() const
    {
        //! check if it's an honor
        bool is_honor =
                data::honor.end()   !=
                    std::find(data::honor.begin(), data::honor.end(), type);

        return is_honor?    type    :   type + std::to_string(value);
    }

    std::string type;
    std::size_t value;
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
operator <(const Tile& lhs, const Tile& rhs)
{
    return lhs.title() < rhs.title();
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

    explicit Box():
        vec(construct_and_sort())
    {}

    const Tile& operator [](SizeType index) const
    {
        return vec[index];
    }

    CIter begin()const
    {
        return vec.cbegin();
    }

    CIter end()const
    {
        return vec.cend();
    }

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

private:
    Container vec;

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

//! @test   for tile
//!
//#include <iostream>
//#include <tiles.hpp>

//int main()
//{
//    mj::Tile tile{"dot", 9};
//    std::cout << tile;

//    return 0;
//}
