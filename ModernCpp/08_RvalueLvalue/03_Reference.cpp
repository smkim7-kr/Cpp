#include <iostream>

class X {};

// Takes lvalue reference to non-const X
void foo(X& x) {
    std::cout << "X& (lvalue)" << std::endl;
}

// Takes lvalue reference to const x
void foo(const X& x) {
    std::cout << "const X& (const lvalue)" << std::endl;
}

// Takes rvalue reference to non-const x
void foo(X&& x) {
    std::cout << "X&& (rvalue)" << std::endl;
}

int main() {
    int n = 10;

    int& r1 = n;
    // int& r2 = 10; // temporary value ralue cannot be referenced
    const int& r3 = n;
    const int& r4 = 10; // const can be referenced

    // int&& r5 = n; // error - cannot bind rvalue reference to lvalue
    int&& r6 = 10; // rvalue reference, used for move semantics and perfect forwarding

    X x;

    // Calling foo with an lvalue
    foo(x); // foo(X& x), if not exist foo(const X& x)

    // Calling foo with an rvalue
    foo(X()); // foo(X&& x), if not exist foo(const X& x), since rvalues can bind to const lvalue references

    X&& rx = X();
    foo(rx); // rx is detected as lvalue (as it has name), so foo(X& x) is called
    foo(static_cast<X&&>(rx)); // foo(X&& x) is called 

    return 0;
}
