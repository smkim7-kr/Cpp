#include <iostream>

// T& argument are always lvalue reference
// (T& int&) => int& and (T& int&&) => int&
template<typename T> void f1(T& arg) {}

// T&& argument can distinguish lvalue and rvalue reference
// (T&& int&) => int& and (T&& int&&) => int&&
template<typename U> void f2(U&& arg) {}

int main() {
    int n = 10;
    // f1(10); // error 
    f1(n); // derive <int>
    f1<int>(n); // derive <int&> lvalue reference
    f1<int&>(n); // derive <int&> lvalue reference
    f1<int&&>(n); // derive <int&> lvalue reference

    f2(10); // rvalue reference
    f2(n); // derive <int>
    f2<int>(n); // int&& rvalue reference
    f2<int&>(n); // int& && => int& lvalue reference
    f2<int&&>(n); // int&& && => int&& rvalue reference
}
