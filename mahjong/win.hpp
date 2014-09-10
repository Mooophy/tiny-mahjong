#ifndef WIN_HPP
#define WIN_HPP

#include <set>
#include <list>
#include <iterator>
#include <algorithm>

namespace std {

//! @typedef
template<typename Iter>
using DifferenceType = typename std::iterator_traits<Iter>::difference_type;

/**
 * @brief operator +
 * @param lhs   iterator
 * @param rhs   offset
 * @return iterator
 *
 * extend std for simplicity.
 */
template<typename Iter>
Iter operator +(Iter lhs, DifferenceType<Iter> rhs )
{
    std::advance(lhs,rhs);
    return lhs;
}

/**
 * @brief operator +
 * @param lhs   offset
 * @param rhs   iterator
 * @return  iterator
 *
 * extend std for simplicity.
 */
template<typename Iter>
Iter operator +(DifferenceType<Iter> lhs,Iter rhs)
{
    return rhs + lhs;
}

}//namespace std

namespace mj {

/**
 * @brief find_1_1_1
 * @param first
 * @return bool
 *
 * for Triplet
 */
template<typename Iter>
inline bool find_1_1_1(Iter first)
{
    return *first   ==  *(first + 1)    &&      *first  ==  *(first + 2);
}

/**
 * @brief find_1_1
 * @param first
 * @return bool
 *
 * for eyes
 */
template<typename Iter>
inline bool find_1_1(Iter first)
{
    return *first   ==  *(first + 1);
}


/**
 * @brief check_if_win
 * @param first
 * @param last
 * @note    sort the sequence first before calling this function
 * @complx  O(3^n)  quit slow, but n == 4 in this case.
 */
template<typename Iter>
bool check_if_win(Iter first, Iter last)
{
    auto size = std::distance(first, last);

    //! trivial case
    if(size == 0)
        return true;

    //! case 1  :   1 1 1
    bool case_1 = find_1_1_1(first)     &&  check_if_win(first + 3, last);  //recur

    //! case 2  :   1 2 3
    using ValueType =   typename std::iterator_traits<Iter>::value_type;
    std::list<ValueType> list {first, last};

    bool case_2 = false;
    {
        auto second = std::find(list.begin(), list.end(), *first + 1);
        auto third  = std::find(list.begin(), list.end(), *first + 2);
        if(second != list.end()  &&  third != list.end())
        {
            list.erase(list.begin());
            list.erase(second);
            list.erase(third);
            case_2 = check_if_win(list.begin(), list.end());                //recur
        }
    }

    //! case 3  :   1 1
    bool case_3 {size % 3    &&  find_1_1(first)};
    if(case_3)
        case_3  =   check_if_win(first + 2, last);                          //recur

    return case_1   ||  case_2  ||  case_3;
}

}//namespace
#endif // WIN_HPP

//! @test
//!
//#include <iostream>
//#include "win.hpp"
//#include "tile.h"

//int main()
//{
//    //! init and sort
//    std::vector<mj::Tile> tiles{
//        {false, "Bai"},
//        {false, "Bai"},
//        {false, "Zho"},
//        {false, "Zho"},
//        {false, "Zho"},
//        {true , "dot", 1},
//        {true , "dot", 2},
//        {true , "dot", 3},
//        {true , "bam", 5},
//        {true , "bam", 6},
//        {true , "bam", 7},
//        {true , "bam", 2},
//        {true , "bam", 3},
//        {true , "bam", 4},
//    };
//    std::sort(tiles.begin(), tiles.end());

//    //! print
//    for(const auto& elem : tiles)
//        elem.print()<< "\n";

//    //! check if win
//    if(mj::check_if_win(tiles.begin(),tiles.end()))
//        std::cout << "you win\n";
//    else
//        std::cout << "not won yet\n";

//    std::cout << "\nexit normally\n";
//    return 0;
//}

//! @output
//!
//Bai
//Bai
//Zho
//Zho
//Zho
//bam2
//bam3
//bam4
//bam5
//bam6
//bam7
//dot1
//dot2
//dot3
//you win

//exit normally
