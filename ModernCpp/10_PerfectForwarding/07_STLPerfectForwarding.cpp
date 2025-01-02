#include <iostream>
#include <functional>

class Point{
  int x,y;
  public:
    Point(int x, int y) :x(x), y(y) {
        std::cout << "Construct (int, int)" << std::endl;
    }
    Point(const Point& pt) :x(pt.x), y(pt.y) {
        std::cout << "Construct(Point&)" << std::endl;
    }
    ~Point() {
        std::cout << "Destroyed" << std::endl;
    }
};

int main() {
    std::vector<Point> v;

    // Case 1) inefficient
    Point p(10, 20); // Point(int x, int y) called
    v.push_back(p); // Point(const Point& pt) called

    std::cout << "-----------------" << std::endl;

    std::vector<Point> v2;
    // Case 2) inefficient
    // Point(int x, int y) called as temporary object, then
    // Point(const Point& pt) called
    // temporary object destroyed immediately
    v2.push_back(Point{10, 20});

    std::cout << "-----------------" << std::endl;

    std::vector<Point> v3;
    // Case 3) Efficient
    // emplace_back has perfect forwarding technique
    v3.emplace_back(10, 20); // call constructor once

    std::cout << "-----------------" << std::endl;
    /* 
    template<typename ... Ts>
    decltype(auto) emplace_back(Ts&& ... args) {
        Type* t = new Type(std::forward<Ts>(args) ...);
        return *t;
    }

    */
}