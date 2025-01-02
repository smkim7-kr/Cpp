#include <iostream>

template <typename T>
void foo(T&& arg) { }

int main() {
    int n = 3;

    int& refl = n;
    int&& refr = 10;

    // It is not possible to explcitily reference a reference
    // int& &refofref = lref;

    // reference collapsing is possible when using typedef, using, decltype, template
    typedef int& lref;
    lref&& r1 = n; // int& && => int&

    using rref = int&&;
    // (&&)&& only collapse to &&, otherwise, collapse to &
    rref&& r2 = 10; // int&& && => int&&

    decltype(r2)&& r3 = 10; // int&& && => int&&

    foo<int&>(n); // foo(int& && arg) => foo(int& arg)
}
