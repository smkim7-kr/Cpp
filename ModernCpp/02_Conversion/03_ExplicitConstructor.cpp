#include <iostream>

class Pos{
    public:
        int size;

        // explicit constructor
        explicit Pos(int s) : size(s) {}
};

void foo(Pos p) {}

int main(){
    Pos p{10}; // direct initialization
    Pos p2(10);

    // this causes error when constructor is expliciit
    // only direct initialization / not copy initialization
    // p = 10; 
    // Pos p2 = {30};
    // foo(70);
}