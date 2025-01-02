#include <iostream>
#include <functional>

struct Vec2 {
    int x;
    int y;
};

int main() {
    int n1 = 10;
    int *ptr1 = &n1;

    // Pointer of member variable
    // int *ptr2 = Vec2::x; //error
    int Vec2::*ptr2 = &Vec2::y; // correct syntax
    
    // ptr2 stores the offset of y in Vec2 struct
    // *ptr2 = 10; // error
    Vec2 vec;
    vec.*ptr2 = 10; // *(&vec + ptr2) = 10, ptr2 is offset

    // using std::invoke
    std::invoke(ptr2, vec) = 20;
    int ret = std::invoke(ptr2, vec);
    std::cout << ret << std::endl;

}