/***************************************************************************
 *  @file       random_sequence.hpp
 *  @author     Yue Wang
 *  @date       6  Sep 2014
 *  @version
 *  @remark     implemented for tiny-mahjong
 ***************************************************************************/
#ifndef RANDOM_SEQUENCE_HPP
#define RANDOM_SEQUENCE_HPP

#include <random>

namespace mj {

/**
 * @brief random
 * @param min
 * @param max
 * @return
 */
template<typename T>
T random(T min , T max)
{
    static std::default_random_engine e;
    static std::uniform_int_distribution<T> ud(min,max);
    return ud(e);
}

/**
 * @brief make_random
 * @param first
 * @param last
 */
template<typename Iter>
void make_random(Iter first, Iter last)
{
    for(auto it = last - 1; it != first; --it)
    {
        auto roll = random(0, it - first);
        std::swap(*it, *(first + roll));
    }
}

}//namespace
#endif // RANDOM_SEQUENCE_HPP

//! @test    make_random
//!
//#include <iostream>
//#include <tiles.hpp>
//#include "game_master.hpp"
//#include "random_sequence.hpp"

//int main()
//{
//    std::vector<int> v {1,2,3,4,5};
//    mj::make_random(v.begin(), v.end());

//    for(auto elem : v)
//        std::cout << elem << " ";

//    std::cout << "\nexit normally\n";
//    return 0;
//}
//! @output
//!
//4 5 2 3 1
//exit normally

