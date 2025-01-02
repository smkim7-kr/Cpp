#include <iostream>
#include <cstring>

class Robot {
    char* name;
    int number;
    public:
        Robot(const char* n, int num) : number(num) {
            name = new char[strlen(n)+1];
            strcpy(name, n);
        }
        ~Robot() { delete[] name; }
};

class DeepRobot {
    char* name;
    int number;
    public:
        DeepRobot(const char* n, int num) : number(num) {
            name = new char[strlen(n)+1];
            strcpy(name, n);
        }
        ~DeepRobot() { delete[] name; }
        // added copy constructor for deep copy
        DeepRobot(const DeepRobot& r) : number(r.number) {
            name = new char[strlen(r.name) + 1];
            strcpy(name, r.name);
        }
};

class MoveRobot {
    char* name;
    int number;
    public:
        MoveRobot(const char* n, int num) : number(num) {
            name = new char[strlen(n)+1];
            strcpy(name, n);
        }
        ~MoveRobot() { delete[] name; }
        MoveRobot(const MoveRobot& r) : number(r.number) {
            name = new char[strlen(r.name) + 1];
            strcpy(name, r.name);
        }
        // added move constructor
        MoveRobot(MoveRobot&& r) : name(r.name), number(r.number) {
            r.name = nullptr;
        }
};

// this function returns temporary object i.e. rvalue
DeepRobot foo() {
    DeepRobot ldr{"LocalRobot", 10};
    return ldr;
}

int main() {
    Robot r1{"R2D2", 10};
    // shallow copy: change in either varaible affect both
    // Robot r2 = r1; 
    
    DeepRobot dr1{"R3D3", 20};
    // deep copy: object with deep constructor defined
    // change in either object don't affect the other
    DeepRobot dr2 = dr1;

    DeepRobot copyrobot = foo();
    // More effective approach: copyrobot points to foo() returned object directly
    // use move constructor!!
    // temporary object (rvalue) is copied directly - memory efficient
    MoveRobot mr2 = MoveRobot{"R4D4", 20};
    
}