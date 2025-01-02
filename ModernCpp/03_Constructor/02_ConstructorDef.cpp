#include <iostream>

struct s1 {
    s1() { std::cout << "Created s1" << std::endl; }
    ~s1() { std::cout << "Destroyed s1" << std::endl;}
};

struct s2 {
    // s2() { std::cout << "Created s2" << std::endl; }
    s2(int a) { std::cout << "Created s2(int)" << std::endl; }
    ~s2() { std::cout << "Destroyed s2" << std::endl;}
};

struct Base {
    s1 m_s1;
    // Base() { std::cout << "Created Base" << std::endl; }
    Base(int a) { std::cout << "Created Base(int)" << std::endl; }
    ~Base() { std::cout << "Destroyed Base" << std::endl;}
};

// If there is no default constructor defined on base class or member variable,
// it will cause error
struct Derived : public Base {
    s2 m_s2; // will cause error - s2 struct doesn't have default constructor
    // will cause error - Base struct doesn't have default constructor
    Derived() { std::cout << "Created Derived" << std::endl; } 
    Derived(int a) { std::cout << "Created Derived(int)" << std::endl; }
    ~Derived() { std::cout << "Destroyed Derived" << std::endl;}
};

int main(){
    // Both will cause an error due to abscence of default constructor
    // Derived d1;
    // Derived d2(10);
}