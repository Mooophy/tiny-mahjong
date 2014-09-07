/***************************************************************************
 *  @file       hu.hpp
 *  @author     Yue Wang
 *  @date       7  Sep 2014
 *  @version
 *  @remark     implemented for tiny-mahjong
 ***************************************************************************/

#ifndef HU_HPP
#define HU_HPP

#include "tiles.hpp"
#include <set>
#include <functional>
#include <iterator>
#include <algorithm>

namespace mj {

template<typename Iter>
inline bool find_1_1_1(Iter first)
{
    return *first   ==  *(first + 1)    ==  *(first + 2);
}

template<typename Iter>
inline bool find_1_1(Iter first)
{
    return *first   ==  *(first + 1);
}



template<typename Iter>
bool check_if_win(Iter first, Iter last)
{
    auto size = last - first;

    if(size == 0)
        return true;

    //! case 1  :   1 1 1
    bool case_1 {find_1_1_1(first)   &&  check_if_win(first + 3, last)};

    //! case 2  :   1 2 3
    using ValueType =   typename std::iterator_traits<Iter>::value_type;
    std::set<ValueType> set {first, last};
    auto second = std::find(set.begin(), set.end(), *first + 1);
    auto third  = std::find(set.begin(), set.end(), *first + 2);

    bool case_2 {false};
    if(second != set.end()  &&  third != set.end())
    {
        set.erase(*second);
        set.erase(*third);

        case_2 = check_if_win(set.begin(), set.end());
    }

    //! case 3  :   1 1
    bool case_3 {size % 3    &&  find_1_1(first)};
    case_3  =   case_3  &&  check_if_win(first + 2, last);

    return case_1   ||  case_2  ||  case_3;
}



}//namespace
#endif // HU_HPP
