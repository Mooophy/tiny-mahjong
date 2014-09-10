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
 *
 * @note    based on Fisher–Yates shuffle.
 * @complx  O(n)
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

/**
 * @brief generate_random_sequence
 * @param size
 * @param first_value
 * @param step
 *
 * for each round of a game
 */
template<typename Container>
inline Container
generate_random_sequence(typename Container::size_type size = 136,
                         const typename Container::value_type& first_value = 0,
                         const typename Container::value_type& step = 1)
{
    //! construct the sequence
    Container sequence(size);
    auto value = first_value;
    for(auto& elem : sequence)
    {
        elem = value;
        value += step;
    }

    //! make it random
    mj::make_random(sequence.begin(), sequence.end());

    return sequence;
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

//! @test   generate_random_sequence
//!
//#include <iostream>
//#include <random_sequence.hpp>

//int main()
//{
//    using Container = std::vector<std::size_t>;
//    auto sequence = mj::generate_random_sequence<Container>(10);

//    for(auto i : sequence)
//        std::cout << i << "\n";

//    return 0;
//}
//! @output
//!
//3
//6
//4
//9
//2
//5
//8
//7
//1
//0
//exit normally

