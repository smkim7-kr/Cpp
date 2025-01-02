#include <iostream>
#include <functional> // STL for function objects in here

int main() {
    int x[4] = {4, 5, 2, 1};

    std::greater<int> f; // function object in STL
    std::sort(x, x+4, f);
    std::sort(x, x+4, std::greater<int>()); // temporary function obj
    std::sort(x, x+4, std::greater()); // C++17 - can ignore type
    std::sort(x, x+4, std::greater{});
}