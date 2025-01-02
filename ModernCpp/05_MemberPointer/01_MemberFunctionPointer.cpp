#include <iostream>
#include <memory>

class Base {
    public:
        void foo2(int x) {}
        static void foo3(int x) {}
};

void foo1(int x) {}

int main() {
    // Using function pointer
    // 1) function pointer to a typical function
    void(*f1)(int) = &foo1; // can use w/o & i.e. foo1


    // 2) function pointer to a member function of a class
    // Error because member function has this input by compiler, parameter mismatch
    // void(*f2)(int) = &b.foo2; 
    // void(*f2)(int) = &Base::foo2;

    // 3) function pointer to a static member function of a class
    void(*f3)(int) = &Base::foo3;

    // Handling Case 2)
    void(Base::*f2)(int) = &Base::foo2;

    // Calling member function pointer
    f1(20);

    Base b;
    // b.f2(10); // wrong syntax
    (b.*f2)(10); // pointer to member operator
    
    Base* bptr = new Base();
    (bptr->*f2)(20);

    std::unique_ptr<Base> bsptr = std::make_unique<Base>(); 
    (bsptr.get()->*f2)(30);
}   

