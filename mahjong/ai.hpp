#ifndef AI_HPP
#define AI_HPP

#include <iostream>

namespace mj {

template<typename Container>
class Ai
{
public:
    using SizeType  =   typename Container::size_type;
    using CIter     =   typename Container::const_pointer;

    Ai(const Container& ih, const Container&ob):
        in_hand{ih},on_board{ob}
    {}

    SizeType operator()() const
    {
        std::cout <<"\n\t\t\t @debug: ai is thinking..\n";
        return 0;
    }

private:
    const Container& in_hand;
    const Container& on_board;
};

}//namespace
#endif // AI_HPP
