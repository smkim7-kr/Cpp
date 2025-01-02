// lvalue: expression that can come be left of =
// rvalue: expression that cannot be left of =
// NOTE: lvalue/rvalue are attributes given to expression, not object/variable

#include <iostream>

class Point {
public:
    int x, y;

    Point(int x, int y) : x(x), y(y) {}

    // Member function that modifies the object
    void set(int newX, int newY) {
        x = newX;
        y = newY;
    }
};


int f1() { return 10; }
int& f2(int& x) { 
    return x;
}

int main(){
    int v1 = 0;
    int v2 = 0;

    v1 = 10; // v1 is lvalue, 10 is rvalue
    // 10 = v1; // error
    v2 = v1; // v1 is considered as rvalue

    int* ptrv1 = &v1; 
    // int* ptrv2 = &10 // rvalue literal 10 doesn't have address
    
    // f1() = 10; // funciton returning value is rvalue
    f2(v1) = 10; // function returning reference is lvalue

    const int c1 = 10; // Constants also have the characteristics of lvalues (name, address)
    // string literals are const char[] type
    // "aa"[0] = 'x';  // error - const type is not mutable

    // Not all rvalues are constants
    // Point(1, 2) is rvalue, but temporary object without memory address
    // but still can call member function
    Point(1, 2).set(10, 20);

    std::cout << "---------------" << std::endl;
    int n = 10;
    // n+2 = 40; // error - n+2 is rvalue
    (n=20) = 10; // assignment expression results lvalue

    ++n = 10; // ++n is lvalue
    // n++ = 10; // error - n++ is rvalue  
}