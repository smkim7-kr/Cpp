#include <iostream>

class Double64 {
    public:
        double value;
        // Constructor
        Double64() : value(1.0) {}

        // conversion operator
        operator double() { return value*2.0; }

        // conversion constructor
        Double64(double d) : value(d) {}

        // copy constructor
        Double64(const Double64&) = delete; 

        // default assignment operator
        Double64& operator=(const Double64&) = delete;
};

int main(){
    double d;
    Double64 d2; // Constructor initializes value = 1.0
    
    d = d2; // d = 2.0
    std::cout << d << std::endl;

    // if operator= assignment operator doesn't exists
    // use conversion constructor like Double64(double)
    // d3 = d; // this causes error, assignment operator is called
    Double64 d3 = d; // create new instance d3 to call conversion opeator

    // Different ways of initialization
    Double64 dd1(2.0); // 1) Direct initialization

    // Compiler converts Double64 dd2 = Double64(2.0), copy constructor called before C++11
    Double64 dd2 = 2.0; // 2) Copy initialization
    Double64 dd3{2.0}; // 3) C++11 direct initialization
    
    // From C++11 move semantics prevents temporary object Double64(2.0) to be created, no copy contructor called
    Double64 dd4 = {2.0}; // 4) C++11 Copy initialization

    // Compiler converts dd1 = Double64(4.0)
    // Temporary object Double64(4.0) created -> Default assignment opeator called to save dd1
    // Thus this causes error without default assignment operator
    // dd1 = 4.0;
}