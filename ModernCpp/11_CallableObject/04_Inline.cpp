// inline funcions converts into machine language at compile time   
#include <iostream>
#include <utility>

// Comparator function pointers
inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

// Comparator struct for ascending order
struct Less {
    inline bool operator()(int a, int b) const { return a < b; }
};

// Comparator struct for descending order
struct Greater {
    inline bool operator()(int a, int b) const { return a > b; }
};

// Template sorting function
template <class T>
void sort(int* x, int sz, T cmp) {
    for (int i = 0; i < sz - 1; i++) {
        for (int j = i + 1; j < sz; j++) {
            if (cmp(x[i], x[j])) {
                std::swap(x[i], x[j]);
            }
        }
    }
}

int main() {
    int x[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

    Less f1;
    Greater f2;

    // Sorting using function pointers
    // Function cmp1 and cmp2 are same signature, thus have no type itself
    // Pro: Same signature, thus no increase in code memory
    // Con: inline function cannot be worked property
    sort(x, 10, &cmp1); // Ascending order
    sort(x, 10, &cmp2); // Descending order

    // Sorting using callable objects
    // Function object f1 and f2 have its own type
    // Pro: inline function works properly
    // Con: Code memory increase
    sort(x, 10, f1); // Ascending order
    sort(x, 10, f2); // Descending order

    // Print sorted array
    for (int i = 0; i < 10; i++) {
        std::cout << x[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
