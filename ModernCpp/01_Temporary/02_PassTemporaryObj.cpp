#include <iostream>
#include <string>

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

void func1(const Pos& p){
    std::cout << p.m_x << ", " << p.m_y << std::endl;
}

// const reference of string
// avoids copying of string, but requires string to be constructed before passed - overhead
void func2(const std::string& s) {
    std::cout << s << std::endl;
}

// point to string literals/contiguous character array
// no copy and string construction (mem allocation), more efficient than func2 when dealing temporary objects/literals
void func3(const std::string_view s) {
    std::cout << s << std::endl;
}

int main(){
    Pos p(10, 20);
    func1(p); // Pass-by-reference regular object p

    // Better approach: use temporary objects
    func1(Pos(20, 30));
    func1({40, 50}); // also possible

    // Pass rvalue strings to functions
    func2("Compiler converts this to string");
    func3("string_view does not create copy, it points to memory of this string literal");
}