#include <iostream>
#include <functional>

class Base {
    public:
        void foo2(int x) {}
        static void foo3(int x) {}
};

void foo1(int x) {}

int main() {
    Base b;

    void(*f1)(int) = foo1;
    void(Base::*f2)(int) = &Base::foo2;
    void(*f3)(int) = &Base::foo3;

    // uniform call syntax
    // f2(&b, 20); // this doesn't work

    // C++17 std::invoke
    std::invoke(f1, 10);
    std::invoke(f2, b, 10);
    std::invoke(f2, &b, 10);
    std::invoke(f3, 10);

    // C++11 std::mem_fn
    // take member function address and returns reference object containing the address
    auto f4 = std::mem_fn(&Base::foo2); // must use auto
    f4(b, 10);
    f4(&b, 10);
}
