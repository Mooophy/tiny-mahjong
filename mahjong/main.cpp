#include <iostream>
#include <box.h>

int main()
{
    mj::Box box{};

    std::cout << box[0].title() << std::endl;
    for(const auto& elem    :   box)
        elem.print() << " ";

    box.print();

    std::cout << "exit normally\n";
    return 0;
}

