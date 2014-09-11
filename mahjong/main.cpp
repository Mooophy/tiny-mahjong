#include <iostream>
#include <tile.hpp>

int main()
{
    auto box = mj::build_box<std::vector<mj::Tile>>();
    for(const auto& tile : box)
        tile.print() << "\n";

    std::cout << "exit normally\n";
    return 0;
}
