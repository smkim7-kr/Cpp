#include <iostream>

class Base {
    public:
        Base() { virtualf(); }
        void foo() { virtualf(); }
        virtual void virtualf() { std::cout << "Base" << std::endl; }
};

class Derived: public Base {
    int data{20};
    public:
        virtual void virtualf() override { std::cout << "Derived" << std::endl; }
};

int main() {
    // Derived constructor includes member initialization : Base() data(20)
    // therefore, Base() calls constructor from Base class
    Derived d; // Base called here
    std::cout << "---------------" << std::endl;
    // foo(), although defined at Base class, gets overrided virtualf() function in Derived class
    d.foo(); // Derived called here
}