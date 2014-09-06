#include <iostream>
#include <tiles.hpp>

int main()
{
    mj::Box box{};

    std::cout << box[9].type << std::endl;
    std::cout << box[0].title() << std::endl;

    for(const auto& elem    :   box)
        std::cout << elem.title() << " ";

    box.print() << std::endl;

    std::cout << "\nexit normally\n";
    return 0;
}

