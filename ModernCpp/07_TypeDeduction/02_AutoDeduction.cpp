#include <iostream>
#include <typeinfo>
#include <vector>

int main() {
    int n = 10;
    int& r = n;

    const int c = 10;
    const int& cr = c;

    auto a1 = n;  // auto=int
    auto a2 = r;  // auto=int
    auto a3 = c;  // auto=int
    auto a4 = cr; // auto=int

    auto& a5 = n;  // auto=int. a5=int&
    auto& a6 = r;  // auto=int. a6=int&
    auto& a7 = c;  // auto=const int. a7=const int&
    auto& a8 = cr; // auto=const int. a8=const int&

    int x[3] = {1, 2, 3};
    auto a = x;  // auto=int*
    auto& b = x; // auto=int[3]. b=int(&)[3]

    std::cout << "--------------" << std::endl;

    auto b1 = 1;
    auto b2 = {1};
    auto b3{1};

    std::cout << typeid(b1).name() << std::endl; // auto=int
    std::cout << typeid(b2).name() << std::endl; // auto=std::initializer_list<int>
    std::cout << typeid(b3).name() << std::endl; // auto=int

    std::vector<int> v1(10, 0);
    std::vector<bool> v2(10, false);

    auto b4 = v1[0];
    auto b5 = v2[0];

    std::cout << typeid(b4).name() << std::endl; // auto=int
    // bool type is specialized during optimization process
    std::cout << typeid(b5).name() << std::endl; // auto=temporary proxy object
}
