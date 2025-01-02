#include <iostream>
#include <functional>

void foo(std::pair<int, int> p) {}
void goo(int a) {}
void goo(int a, int b) {}

template<class F, class ... T> 
decltype(auto) fforward(F&& f, T&& ... arg) {
    return std::invoke(std::forward<F>(f), std::forward<T>(arg)...);
}

int main() {
    // error - needs to explicitly show the type of argument
    // fforward(foo, {1,2}); 
    fforward(foo, std::pair{1,2});

    // if same function name is overloaded
    // need to cast the type of function explicitly
    fforward(static_cast<void(*)(int)>(goo), 1);
    fforward(static_cast<void(*)(int, int)>(goo), 1,2); 
}
