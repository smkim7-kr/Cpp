#include <iostream>
#include <functional>
#include <string>
#include <ranges>
#include <vector>

template<class U, class Comp = std::less<void>, class Proj2 = std::identity>
const U& cmpobj(const U& obj1, const U& obj2, Comp comp = {}, Proj2 proj = {}) {
    // added compare operator instead of using <
    return std::invoke(comp, std::invoke(proj, obj1), std::invoke(proj, obj2)) ? obj2 : obj1;
}

int main() {
    std::string s1 = "hello";
    std::string s2 = "world";

    auto implcmp = cmpobj(s1, s2, std::greater{}, &std::string::size);
    // C++20 - ranges algorithm, std::ranges::max is function object
    auto cppcmp = std::ranges::max({s1, s2}, std::ranges::greater{}, &std::string::size);
}

