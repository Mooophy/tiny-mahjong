#ifndef TILES_HPP
#define TILES_HPP

#include <string>
#include <iostream>

namespace mj {

/**
 * @brief The tile struct
 */
struct Tile
{
    std::string title() const
    {
        return type + std::to_string(value);
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

}//namespace
#endif // TILES_HPP
