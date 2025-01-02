#include <iostream>

class Base{
    int m_x{0}, m_y{0};
    public:
        void Setxy(int x, int y) {
            m_x = x;
            m_y = y;
        }

        // compiler automatically include this parameter
        // therefore, although member functions share memory, compiler can distinguish
        /*
        void Setxy(Base* this, int x, int y) {
            this->m_x = x;
            this->m_y = y;
        }
        */

       // this call doesn't apply for static member functions
       static void foo(int x){}
};


int main(){
    // b1 and b2 have separate memory space for member VARIABLES (x, y)
    Base b1;
    Base b2;

    // however, different objects share single memory spave for member FUNCTIONS
    b1.Setxy(10, 20);
    b2.Setxy(30, 40);

    // static member functions doesn't need this keyword
    // same as b2.foo(20)
    Base::foo(20);
}