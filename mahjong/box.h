#ifndef BOX_H
#define BOX_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "tile.h"

namespace mj {
class Box
{
public:
    using Container =   std::vector<mj::Tile>;
    using SizeType  =   typename Container::size_type;
    using CIter     =   typename Container::const_iterator;

    /**
     * @brief default Ctor
     */
    explicit Box():
        vec{construct_and_sort()}
    {}

    /**
     * @brief operator []
     */
    const Tile& operator [](SizeType index) const
    {
        return vec[index];
    }

    /**
     * @brief begin
     */
    CIter begin()const
    {
        return vec.cbegin();
    }

    /**
     * @brief end
     */
    CIter end()const
    {
        return vec.cend();
    }

    /**
     * @brief print
     */
    std::ostream& print()const
    {
        std::size_t count = 0;
        for(const auto& elem : vec)
        {
            std::cout << elem
                      << (count++ == 3?   "\n"    :   " ");
            count %= 4;
        }

        std::cout << std::endl << vec.size() << " tiles in all";

        return std::cout;
    }

    /**
     * @brief size
     * @return
     */
    SizeType size()const
    {
        return vec.size();
    }
private:
    Container vec;

    /**
     * @brief construct_and_sort
     * @return
     */
    Container construct_and_sort()
    {
        Container ret{};

        //! insert all tiles
        for(auto four = 0; four != 4; ++four)
        {
            for(const auto& elem :  data::suit)
                for(unsigned val = 0; val != 9; ++val)
                    ret.push_back({true, elem, val + 1});

            for(const auto& elem :  data::honor)
                ret.push_back({false, elem, 0});
        }

        //! sort
        std::sort(ret.begin(), ret.end());

        return ret;
    }
};
}//namespace
#endif // BOX_H

//! @test
//!
//#include <iostream>
//#include <box.h>

//int main()
//{
//    mj::Box box{};

//    std::cout << box[0].title() << std::endl;
//    for(const auto& elem    :   box)
//        elem.print() << " ";

//    box.print();

//    std::cout << "exit normally\n";
//    return 0;
//}
