#include <iostream>

// Class to represent a position with x and y coordinates
class Pos {
public:
    int m_x, m_y; // Member variables to store x and y coordinates

    // Constructor to initialize the position
    Pos(int x, int y) : m_x(x), m_y(y) {
        std::cout << "Point init" << std::endl;
    }
    // Destructor to handle object destruction
    ~Pos() {
        std::cout << "Point destruct" << std::endl;
    }

    // Member function to set new x and y coordinates
    void Set(int x, int y) {
        m_x = x; 
        m_y = y;
    }
};

int main(){
    // Creating a named object of Pos
    Pos r1(10, 20); 
    // Creating a temporary object of Pos - rvalue
    Pos (10, 20);

    // Modifying the member variable of the named object
    r1.m_x = -10; // Note: Normally member variable should be private

    // Attempting to modify the member variable of a temporary object - Error
    // Pos(10, 20).m_x = -10; // Error: Temporary Object cannot access member variable

    // Calling a member function on a temporary object
    Pos(10, 20).Set(-10, -20); // Temporary Object can call member functions

    // Creating a pointer to the named object
    Pos* pr1 = &r1;

    // Attempting to create a pointer to a temporary object - Error
    // Pos* pr2 = &Pos(10, 20); // Error: Temporary Object cannot be referenced by pointer

    // Creating a reference to the named object
    Pos& rr1 = r1;

    // Attempting to create a reference to a temporary object - Error
    // Pos& rr2 = Pos(10, 20); // Error: Temporary Object cannot be referenced

    // Creating an rvalue reference to a temporary object
    Pos&& rr3 = Pos(10, 20); // rvalue reference, can interact with temporary objects through rr3
    std::cout << rr3.m_x << std::endl;

    // Exception: Temporary objects can be referenced with const reference
    const Pos& rr4 = Pos(10, 20); // rr4 has lifetime as regular object
    std::cout << rr4.m_x << std::endl;
}