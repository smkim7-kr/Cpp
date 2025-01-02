#include <iostream>

// Case 2: functions have different input numbers and return type
void foo(int val) {}
int& goo(int v, int& v2, int&& v3) { 
    v2 = 20; 
    return v2;
}

// ... is variadic template, accept variable number of parameters
// return type auto since function f has different return type
// decltype added to preserve reference property e.g. int&
template<class F, class ... T> 
decltype(auto) fforward(F f, T&& ... arg) {
    return f(std::forward<T>(arg)...);
}

int main() {
    int n = 10;
    fforward(foo, n);
    fforward(foo, 10);
    std::cout << n << std::endl;

    int n2 = -10;
    int n3 = 99;
    fforward(goo, n, n2, std::move(n3));
    std::cout << n2 << std::endl;
}