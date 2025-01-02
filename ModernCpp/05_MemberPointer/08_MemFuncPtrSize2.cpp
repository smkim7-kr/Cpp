#include <iostream>

struct A { 
    int x;
    void fA() { std::cout << this << std::endl; };
};

struct B { 
    int y;
    void fB() { std::cout << this << std::endl; };
};

struct C : public A, public B {
    int z;
    void fC() { std::cout << this << std::endl; };
    void fC2() { std::cout << this << std::endl; };
};

int main() {
    C cc;
    cc.fC();
    cc.fB(); // different memory address as second inherited Base class
    cc.fA();

    // This pointer points to the member function fC() of class C, 
    // which takes no arguments and returns void.
    void (C::*f)();
    // void (C::*f)() = &C::fC; // to specify which member function this points to
    
    f = &C::fA;
    (cc.*f)();

    f = &C::fB;
    (cc.*f)(); // different address (this offset stored)
}   