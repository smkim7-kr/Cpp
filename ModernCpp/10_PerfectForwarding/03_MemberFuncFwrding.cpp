#include <iostream>
#include <functional>

// Case 3: what if function is member function of object?
void foo(int n) {}
class Obj {
    public:
        void foo(int n) { std::cout << "I'm member func!" << std::endl; }
};

template<class F, class ... T> 
decltype(auto) fforward(F f, T&& ... arg) {
    // std::invoke can handle member functions (ref: 05 >> 04_std::invoke.cpp)
    return std::invoke(f, std::forward<T>(arg)...);
}

int main() {
    fforward(foo, 10);
    Obj o;
    fforward(&Obj::foo, &o, 10); // can handle member function of class object
}