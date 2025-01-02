#include <iostream>
#include <type_traits>
#include <cstring> // For memcpy

// A simple struct with trivial copy constructor
struct Point {
    int x = 0;
    int y = 0;
};

// A helper template function to check for triviality and copy objects
template <typename T>
void copy_type(T* dst, T* src, std::size_t sz) {
    if constexpr (std::is_trivially_copy_constructible_v<T>) {
        std::cout << "Using memcpy (trivial copy constructor)" << std::endl;
        std::memcpy(dst, src, sizeof(T) * sz);
    } else {
        std::cout << "Using copy constructor (non-trivial copy constructor)" << std::endl;
        while (sz--) {
            new (dst) T(*src); // Placement new to call copy constructor
            ++dst;
            ++src;
        }
    }
}

// A class with a non-trivial copy constructor
struct ComplexPoint {
    int x;
    int y;
    std::string label; // A non-trivial member makes the copy constructor non-trivial

    ComplexPoint(int a = 0, int b = 0, const std::string& lbl = "")
        : x(a), y(b), label(lbl) {}

    // Explicitly define a copy constructor
    ComplexPoint(const ComplexPoint& other)
        : x(other.x), y(other.y), label(other.label) {
        std::cout << "ComplexPoint copy constructor called" << std::endl;
    }
};

int main() {
    // Example with trivial copy constructor
    Point arr1[5] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
    Point arr2[5];
    copy_type(arr2, arr1, 5); // Uses memcpy

    // Example with non-trivial copy constructor
    ComplexPoint c_arr1[2] = {ComplexPoint(1, 2, "A"), ComplexPoint(3, 4, "B")};
    ComplexPoint c_arr2[2];
    copy_type(c_arr2, c_arr1, 2); // Uses the copy constructor

    return 0;
}
