// Function object is object that is callable like function using () 
#include <iostream>

struct mul {
    int operator()(int arg1, int arg2) { return arg1 * arg2; }
};

// Better function object definition
// 1) Use template to handle various types
// 2) Write operator() in const function
// 3) Use [[nodiscard]] to prevent ignoring return value
// 4) Use constexpr for performance, it enables compile-time eval
// 5) Use noexcept if possible for performance 
// 6) Use perfect forwarding and template specialization
// 7) Use is_transparent() function if necessary
template<class T>
struct bettermul {
    [[nodiscard]] constexpr
    T operator()(const T& arg1, const T& arg2) const {
        return arg1 * arg2;
    }
};

int main() {
    mul m;
    // Able to call object m using () as opeator() is defined
    int n = m(20, 30); 
    std::cout << n << std::endl;

    // Use function object because
    // 1) Can have state 
    // 2) Can increase speed using inline operator
    // 3) Function object can have its type/signature
    const bettermul<double> bm;
    // bm(20.2, 30.7) // error because of [[nodiscard]]
    double n2 = bm(20.2, 30.7);
    std::cout << n2 << std::endl;
}