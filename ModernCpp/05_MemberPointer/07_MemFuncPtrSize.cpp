#include <iostream>

struct A { int x; };
struct B { int y; };
struct C : public A, public B {
    int z;
};

int main() {
    C cc;
    std::cout << &cc << std::endl;

    // Creating a pointer to A / B
    // and assigning it the address of cc
    A* Aptr = &cc;
    B* Bptr = &cc;
    std::cout << Aptr << std::endl;
    // Bptr stores a different address because of the way multiple inheritance is implemented in C++.
    // B class is second in the inheritance order, so it skips the 4 bytes occupied by A class's member variable.
    std::cout << Bptr << std::endl; 
    std::cout << static_cast<B*>(&cc) << std::endl; // same output
    // This reinterpret_cast converts the address of cc to a B pointer
    // resulting in the same address as Aptr.
    std::cout << reinterpret_cast<B*>(&cc) << std::endl; 
}