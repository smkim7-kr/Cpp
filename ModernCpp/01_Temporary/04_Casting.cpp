#include <iostream>

struct Base {
    int val = 10;

    Base() = default;
    // Copy constructor
    Base(const Base&b) : val(b.val) {}
};

struct Child : public Base {
    int val = 20;
};

int main(){
    Child c;

    std::cout << c.val << std::endl;

    // casts c to reference of Base. Not create new Base Object
    std::cout << static_cast<Base&>(c).val << std::endl;
    // New Base object is created, less efficient
    std::cout << static_cast<Base>(c).val << std::endl;

    static_cast<Base&>(c).val = -10;
    std::cout << c.val << std::endl; // still 20. Accessing val member of Child struct
    std::cout << static_cast<Base&>(c).val << std::endl; // Member variable shadowing - val member of Base struct
    // Cast by reference if possible
    //static_cast<Base>(c).val = -20; // Error - rvalue
}