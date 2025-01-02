// tl;dr Template deducts type by functiona argument
#include <iostream>

// function that only deducts type name
// when argument is pass-by-copy, all attributes are ignored
template<class T> void foo(T arg){
    std::cout << typeid(T).name() << std::endl;
}

template<class U> void goo(U arg){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

// pass-by-reference
template<class V> void hoo(V& arg){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int main() {
    int n = 10;
    const int cn = 20;

    // auto only deducts type name
    // auto cannot deduct attributes like const, volatile, reference information
    auto a1 = n; // auto deducts int
    auto a2 = cn; // auto still deducts int

    foo(a1); // int
    foo(a2); // int
    foo(n); // int
    foo<const int&>(n); // int

    std::cout << "----------------" << std::endl;
    const char* const s = "hello";

    // Pointer s const property is removed when passed to goo
    // But, "hello" itself const property is reserved
    goo(s); // const char* arg = "hello"

    std::cout << "----------------" << std::endl;   
    int n1 = 10;
    int& ptrn1 = n1;
    const int c1 = 20;
    const int& ptrc1 = c1;

    // const property preserved, reference property removed
    hoo(n1); // int
    hoo(ptrn1); // int
    hoo(c1); // const int
    hoo(ptrc1); // const int

    std::cout << "----------------" << std::endl;  
    
    // Array case
    int x[3] = {1, 2, 3};
    goo(x); // int*
    hoo(x); // int[3], arg is int()[3] type

    // this will cause error since type is not poitner
    // hoo("hello", "world!"); 
}