#include <iostream>

class Counter {
public:
    Counter() : count(0) {} // Initialize count to 0

    // Overload the operator() to increment and return the count
    int operator()() {
        return ++count; // Increment and return the current count
    }

private:
    int count; // State: the current count
};

int main() {
    Counter counter; // Create a Counter object

    // Call the counter multiple times
    std::cout << "Count: " << counter() << std::endl; // Output: Count: 1
    std::cout << "Count: " << counter() << std::endl; // Output: Count: 2
    std::cout << "Count: " << counter() << std::endl; // Output: Count: 3

    return 0;
}
