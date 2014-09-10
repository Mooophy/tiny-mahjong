#ifndef IN_HAND_HPP
#define IN_HAND_HPP

#include <vector>
#include <algorithm>
#include "win.hpp"

namespace mj {

const std::size_t FULL_SIZE = 14;

/**
 * @brief The InHand class
 *
 * use [13] for the 14th pile always
 */
template<typename ValueType>
class InHand : public std::vector<ValueType>
{
public:
    using Base  =   std::vector<ValueType>;

    /**
     * @brief push_back
     * @param added
     *
     * only used for first 13 tiles (14 tiles for maker)
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

    /**
     * @brief did_win
     * @return
     */
    bool did_win()const
    {
        if(Base::size() !=  mj::FULL_SIZE)
            return false;
        return mj::check_if_win(Base::begin(), Base::end());
    }
};

}//namespace

#endif // IN_HAND_HPP
