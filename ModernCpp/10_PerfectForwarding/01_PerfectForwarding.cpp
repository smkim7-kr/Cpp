// Perfect forwarding is forwarding arguments without change in properties(value, const atrribute etc.)
#include <iostream>

// Case 1: different input argument types
void foo(int val) {}
void goo(int& val) { val = 20; }
void hoo(int&& val) {}

template<class F, class T>
void fforward(F f, T arg) {
    f(arg);
}

template<class F2, class T2>
void fforward2(F2 f, T2&& arg) { // rvalue reference - bind both lvalue and rvalue
    // f( std::forward<T>(arg) ) // this has the same effect
    f(static_cast<T2&&>(arg)); // this is because arg is no longer rvalue when passed by argument name arg
    // therefore, this does std::move() only if arg is rvalue
}

int main() {
    int n = 10;
    fforward(foo, 10);
    fforward(goo, n);  
    // n prints 10 here since n is pass-by-value (T) in fforward function
    std::cout << n << std::endl; 

    // may use "const T&"" for input argument
    // but this forces all arguments with const property

    // better approach
    fforward2(foo, 10);

    // T2 deduces int& => (int&)(&&) => int&
    // then calls goo(n) as inputing lvaluue refernce
    fforward2(goo, n);  
    fforward2(hoo, 10); // (int&&)(&&) => int&&
    std::cout << n << std::endl;  // now it updates to 20
}