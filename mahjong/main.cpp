#include <iostream>
#include <random_sequence.hpp>

int main()
{
    using Container = std::vector<std::size_t>;
    auto sequence = mj::generate_random_sequence<Container>(10);

    for(auto i : sequence)
        std::cout << i << "\n";

    std::cout << "exit normally\n";
    return 0;
}
