#include <iostream>
#include <functional>

class MyClass {
public:
    void memberFunction() {
        std::cout << "Member function called!" << std::endl;
    }

    int memberVariable = 42;
};

int main() {
    MyClass obj;

    // Pointer to a regular variable
    int value = 10;
    auto pointerToValue = &value;
    std::cout << "Value: " << std::invoke([](int* p) { return *p; }, pointerToValue) << std::endl;

    // Function
    auto function = [](int x) { return x * 2; };
    std::cout << "Function result: " << std::invoke(function, 5) << std::endl;

    // Member function pointer
    void (MyClass::*memberFuncPtr)() = &MyClass::memberFunction;
    std::invoke(memberFuncPtr, &obj); // Call member function

    // Member variable pointer
    int MyClass::*memberVarPtr = &MyClass::memberVariable;
    std::cout << "Member variable: " << std::invoke(memberVarPtr, &obj) << std::endl;

    // Lambda expression
    auto lambda = []() { std::cout << "Lambda called!" << std::endl; };
    std::invoke(lambda); // Call lambda
}