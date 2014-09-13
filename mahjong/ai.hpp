#ifndef AI_HPP
#define AI_HPP

namespace mj {

template<typename Container>
class Ai
{
public:
    using SizeType  =   typename Container::size_type;
    using CIter     =   typename Container::const_pointer;

    Ai(const Container& c):
        data(c)
    {}

    SizeType operator()() const
    {

    }


private:
    const Container& data;

    CIter begin()const
    {
        return data.cbegin();
    }

    CIter end()const
    {
        return data.cend();
    }

};

}//namespace
#endif // AI_HPP
