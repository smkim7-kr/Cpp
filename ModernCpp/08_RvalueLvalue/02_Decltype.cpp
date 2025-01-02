#include <iostream>


// can use macro to simply distinguish lvalue/rvalue
#define value_category(...) \
if (std::is_lvalue_reference_v<decltype((__VA_ARGS__))>) { \
    std::cout << "lvalue" << std::endl; \
} else if (std::is_rvalue_reference_v<decltype((__VA_ARGS__))>) { \
    std::cout << "rvalue(xvalue)" << std::endl; \
} else { \
    std::cout << "rvalue(prvalue)" << std::endl; \
}

int main() {
    int n = 10;

    // decltype to find out whether lvalue/rvalue
    if (std::is_lvalue_reference_v<decltype(n++)>)
        std::cout << "lvalue" << std::endl;
    else
        std::cout << "rvalue" << std::endl;

    // must encapsulate with () since it is evaluating expression
    if (std::is_lvalue_reference_v<decltype((n))>)
        std::cout << "lvalue" << std::endl;
    else
        std::cout << "rvalue" << std::endl;

    std::cout << "-------------------" << std::endl;
    value_category(n);
    value_category(n+2);
    value_category(n++);
    value_category(++n);
}