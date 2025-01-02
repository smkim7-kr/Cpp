#include <iostream>
#include <vector>

class Obj {
    public:
        Obj() = default;
        Obj(const Obj& obj) { std::cout << "Copy" << std::endl; }
        Obj(Obj&& obj) { std::cout << "Move" << std::endl; }
};

class NoEObj {
    public:
        NoEObj() = default;
        NoEObj(const Obj& obj) { std::cout << "Copy" << std::endl; }

        // alert compiler there is no exception in move operation
        NoEObj(Obj&& obj) noexcept { std::cout << "Move" << std::endl; }
        
};

int main() {
    std::vector<Obj> v(3);
    std::cout << "-------------" << std::endl;
    // existing 3 element are COPIED to new memory space    
    v.resize(5);
    std::cout << "-------------" << std::endl;

    std::vector<NoEObj> v2(3);
    std::cout << "-------------" << std::endl;
    // existing 3 element are MOVED to new memory space    
    v2.resize(5);
    std::cout << "-------------" << std::endl;

    Obj o1;
    NoEObj neo1;
    Obj o2 = std::move(o1);
    Obj o3 = std::move_if_noexcept(o1);
    NoEObj neo2 = std::move(neo1);
    NoEObj neo3 = std::move_if_noexcept(neo1);
}