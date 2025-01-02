#include <iostream>

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

class Counter{
    public:
        int count = 0; 

        // return-by-reference
        Counter& inc() { 
            ++count;
            return *this;
        }

};

// return-by-value
Pos func1(const Pos& p) {
    return p;
}

// return-by-reference
Pos& func2(Pos& p){ 
    return p;
}

Pos& func3(){
    Pos localp(10, 20);
    // localp is destroyed at the end of this function
    return localp; // Error : Never return-by-reference local object
}

int main(){
    Pos p(20, 30);
    // func1(p).m_x = 10; // Error - return-by-value is rvalue
    func2(p).m_x = 10; // return-by-reference is okay

    Counter c;
    c.inc().inc().inc().inc().inc().inc().inc();
    std::cout << c.count << std::endl;
    
}