#include <iostream>

class Double64 {
    public:
        double value;
        // Constructor
        Double64() : value(1.0) {}

        // conversion operator
        operator double() { return value*2.0; }

        // conversion operator for const object
        operator double() const { return value*3.; }
};

int main(){
    double d;
    Double64 d2; // Constructor initializes value = 1.0

    d = d2; // d2's conversion opeator called here
    std::cout << d << std::endl; // 2.0

    const Double64 d3;
    d = d3;
    std::cout << d << std::endl; // 3.0
}