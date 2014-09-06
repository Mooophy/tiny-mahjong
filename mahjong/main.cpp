#include <iostream>
#include <tiles.hpp>

int main()
{
    mj::Box box{};

    for(const auto& elem    :   box)
        std::cout << elem.title() << " ";

    return 0;
}

