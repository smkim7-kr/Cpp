#include <iostream>
#include <string>

class Obj {
    std::string name;
    public:
        Obj() = default;
        Obj(const Obj& other) : name(other.name) {} // 1) copy constructor
                Obj& operator=(const Obj& other) { name = other.name; } // 2) copy assignment operator
        Obj(Obj&& other) : name(std::move(other.name)) {} // 3) move constructor
        Obj& operator=(Obj&& other) { name = std::move(other.name); } // 4) move assignment operator 
};

class DefineMove {
    std::string name;

public:
    DefineMove() = default;
    // to let compiler define default move semantics
    // request default version of below three lines
    DefineMove(const DefineMove& other) = default;
    DefineMove(DefineMove&& obj) = default;
    DefineMove& operator=(DefineMove&& obj) = default;
};


int main() {
    // If 1), 2), 3), 4) is not defined by user, compiler provides their default version
    // If 1) is defined by user, compiler provides default version of 2) (and vice versa)
    // If 3) (or 4)) is defined by user, compiler deletes 1) and 2)
}