#ifndef TILES_HPP
#define TILES_HPP

#include <string>
#include <iostream>

namespace mj {

struct tile
{
    std::string title() const
    {
        return type + std::to_string(value);
    }

    std::string type;
    std::size_t value;
};

inline std::ostream&
operator <<(std::ostream& os, const tile& tl)
{
    os << tl.title();
    return os;
}

}//namespace
#endif // TILES_HPP
