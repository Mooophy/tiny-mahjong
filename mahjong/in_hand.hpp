#ifndef IN_HAND_HPP
#define IN_HAND_HPP

#include <vector>
#include <algorithm>

namespace mj {

/**
 * @brief The InHand class
 */
template<typename ValueType>
class InHand : public std::vector<ValueType>
{
public:
    using Base  =   std::vector<ValueType>;

    /**
     * @brief push_back
     * @param added
     */
    void push_back(const ValueType& added)
    {
        std::vector<ValueType>::push_back(added);
        std::sort(Base::begin(), Base::end());
    }

    /**
     * @brief draw
     * @param drawn
     */
    void draw(const ValueType& drawn)
    {
        Base::back()    =   drawn;
        std::sort(Base::begin(), Base::end());
    }

    /**
     * @brief bring_out
     * @param index
     * @return
     */
    ValueType bring_out(std::size_t index)
    {
        std::swap(Base::back(), (*this)[index]);
        return Base::back();
    }
};

}//namespace

#endif // IN_HAND_HPP
