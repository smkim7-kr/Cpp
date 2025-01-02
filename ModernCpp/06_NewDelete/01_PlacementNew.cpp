#include <iostream>
#include <memory>

class Point {
    int x, y;
public:
    Point(int a, int b) : x{a}, y{b} { std::cout << "Point(int, int)" << std::endl; }
    ~Point() { std::cout << "~Point()" << std::endl; }
};

int main() {
    // memory allocation + call constructor
    Point* p1 = new Point(1, 2); 
    // call destructor + memory deallocation
    delete p1;

    // seperate memory allocation and calling constructor
    void* p = operator new(sizeof(Point)); // memory allocation
    // new operator here is called "placement new"
    Point* p2 = new(p) Point(1,2); // calling constructor, no extra memory alloc

    // seperate calling destructor and memory deallocation
    p2->~Point(); // calling destructor
    operator delete(p2); // memory deallocation

    // c-like malloc-free (no calling constructor)
    void* mp = operator new(sizeof(Point));
    operator delete(mp);

    // From c++20: construct_at
    Point* p3 = static_cast<Point*>(operator new(sizeof(Point)));
    std::construct_at(p3, 1, 2); // call constructor
    std::destroy_at(p3); // calling destructor
    operator delete(p3); // memory deallocation


    // Case study: why seperating allocation & constructor step is great
    Point* p4 = static_cast<Point*>(operator new(sizeof(Point)*10));
    for (int i=0; i<10; i++){
        // new(&p2[i]) Point(0,0); // before C++20
        std::construct_at(&p4[i], 0,0);
    }

    for (int i=0; i<10; i++){   
        // p2[i].~Point(); // before C++@0
        std::destroy_at(&p4[i]); 
    }
}
