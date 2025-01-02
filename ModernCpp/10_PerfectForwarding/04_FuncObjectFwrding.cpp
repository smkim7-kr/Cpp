#include <iostream>
#include <functional>

// Case 4: passing rvalue function object
struct Func {
    void operator()(int n) & {
        std::cout << "lvalue" << std::endl;
    }

    void operator()(int n) && {
        std::cout << "rvalue" << std::endl;
    }
};

// use F&& with std::forward
// because then it can handle first argument f with rvalue
template<class F, class ... T> 
decltype(auto) fforward(F&& f, T&& ... arg) {
    return std::invoke(std::forward<F>(f), std::forward<T>(arg)...);
}

int main() {
    Func f;
    fforward(f, 10);
    
}