#include <iostream>

int main() {
    // Define a lambda function f1 that takes two integers and returns their sum
    auto f1 = [](int a, int b) { return a + b; };

    // Define a function pointer f2 that points to a lambda function
    // This lambda also takes two integers and returns their sum
    
    // Lambda Function → Creates a Temporary Object 
    // → Calls the operator() of that object when invoked 
    // → If non-capturing, can be converted to a Function Pointer.
    int (*f2)(int, int) = [](int a, int b) { return a + b; };
}   