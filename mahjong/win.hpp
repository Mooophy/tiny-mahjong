#ifndef WIN_HPP
#define WIN_HPP

#include "tile.h"
#include <set>
#include <list>
#include <iterator>
#include <algorithm>

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
    auto second = first;
    std::advance(second, 1);
    auto third  = first;
    std::advance(third, 2);

    return *first   ==  *second    &&      *first  ==  *third;
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
    auto second = first;
    std::advance(second, 1);

    return *first   ==  *second;
}


/**
 * @brief check_if_win
 * @param first
 * @param last
 * @note    sort the sequence first before calling this function
 */
template<typename Iter>
bool check_if_win(Iter first, Iter last)
{
    auto size = std::distance(first, last);

    //! trivial case
    if(size == 0)
        return true;

    //! case 1  :   1 1 1
    bool case_1 = find_1_1_1(first);
    if(case_1)
    {
        auto next = first;
        std::advance(next, 3);
        case_1 = check_if_win(next, last);
    }

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
            case_2 = check_if_win(list.begin(), list.end());
        }
    }

    //! case 3  :   1 1
    bool case_3 {size % 3    &&  find_1_1(first)};
    if(case_3)
    {
        auto next = first;
        std::advance(next, 2);
        case_3  =   check_if_win(next, last);
    }

    return case_1   ||  case_2  ||  case_3;
}

}//namespace
#endif // WIN_HPP

//! @test
//!
//#include <iostream>
//#include "game_master.h"
//#include "win.hpp"

//int main()
//{
//    //! init and sort
//    mj::GameMaster gm;
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
