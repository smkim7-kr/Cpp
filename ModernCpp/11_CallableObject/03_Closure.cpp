#include <iostream>
#include <functional>

void exampleClosure() {
    int x = 10; // Local variable

    // Using a closure to capture x
    auto closure = [x]() {
        std::cout << "Captured value: " << x << std::endl; // Print the captured value
    };

    closure(); // Call the closure

    // Typical function that cannot capture local variable
    auto typicalFunction = [](int value) {
        std::cout << "Value: " << value << std::endl; // Print the passed value
    };

    typicalFunction(x); // Pass x to the typical function
}

int main() {
    exampleClosure(); // Execute the example function
    return 0;
}
