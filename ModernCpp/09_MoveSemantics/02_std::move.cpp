#include <iostream>

class Obj {
    public:
        Obj() = default;
        Obj(const Obj& obj) { std::cout << "Copy" << std::endl; }
        Obj(Obj&& obj) { std::cout << "Move" << std::endl; }
};

Obj foo() {
    Obj o;
    return o;
}

int main() {
    Obj o1;
    Obj o2 = o1; // (deep) copy
    Obj o3 = foo(); // move
    Obj o4 = static_cast<Obj&&>(o1); // move
    // By using std::move, can easily convert lvalue to rvalue
    Obj o5 = std::move(o1); // move
}
