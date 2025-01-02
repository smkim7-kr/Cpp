#include <iostream>

struct s1 {
    s1() { std::cout << "Created s1" << std::endl; }
    ~s1() { std::cout << "Destroyed s1" << std::endl;}
};

struct s2 {
    s2() { std::cout << "Created s2" << std::endl; }
    ~s2() { std::cout << "Destroyed s2" << std::endl;}
};

struct Base {
    s1 m_s1;
    Base() { std::cout << "Created Base" << std::endl; }
    Base(int a) { std::cout << "Created Base(int)" << std::endl; }
    ~Base() { std::cout << "Destroyed Base" << std::endl;}
};

struct Derived : public Base {
    s2 m_s2;
    Derived() { std::cout << "Created Derived" << std::endl; }
    Derived(int a) { std::cout << "Created Derived(int)" << std::endl; }
    ~Derived() { std::cout << "Destroyed Derived" << std::endl;}
};

int main(){

    // Order of construction: s1 - Base - s2 - Derived
    // Order of destruction: Reverse order
    Derived d1;

    // Order of construction: s1 - Base - s2 - Derived(int)
    Derived d2(10);
}