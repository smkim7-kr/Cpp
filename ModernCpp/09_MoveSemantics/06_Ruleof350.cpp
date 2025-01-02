#include <iostream>
#include <cstring>
#include <string>


// Rule of 3
// If there is pointer member variable that memory is dynamically addressed
// C++98 needs to define destructor, copy constructor, copy assignmnet oeprator
class RuleOf3 {
    char* name;
    int number;
    public:
        RuleOf3(const char* n, int num) : number(num) {
            name = new char[strlen(n)+1];
            strcpy(name, n);
        }
        ~RuleOf3() { delete[] name; }
        RuleOf3(const RuleOf3& r) : number(r.number) {
            name = new char[strlen(r.name) + 1];
            strcpy(name, r.name);
        }
        RuleOf3& operator=(const RuleOf3& r) {
            if (this != &r) {
                delete[] name;
                name = new char[strlen(r.name) + 1];
                strcpy(name, r.name);
                number = r.number;
            }
            return *this;
        }
};

// Rule of 5
// If there is pointer member variable that memory is dynamically addressed
// C+=11 needs to define destructor, copy constructor, copy assignmnet oeprator
// move constructor, and move assignment operator
class RuleOf5 {
    char* name;
    int number;
    public:
        RuleOf5(const char* n, int num) : number(num) {
            name = new char[strlen(n)+1];
            strcpy(name, n);
        }
        ~RuleOf5() { delete[] name; }
        RuleOf5(const RuleOf5& r) : number(r.number) {
            name = new char[strlen(r.name) + 1];
            strcpy(name, r.name);
        }
        RuleOf5& operator=(const RuleOf5& r) {
            if (this != &r) {
                delete[] name;
                name = new char[strlen(r.name) + 1];
                strcpy(name, r.name);
                number = r.number;
            }
            return *this;
        }
        RuleOf5(RuleOf5&& r) : name(r.name), number(r.number) {
            r.name = nullptr;
        }
        RuleOf5& operator=(RuleOf5&& r) {
            if (this != &r) {
                delete[] name;
                name = r.name;
                number = r.number;
                r.name = nullptr;
            }
            return *this;
        }
};

// Rule of 0
// Use STL class so that user do not explictly control memory 
class RuleOf0 {
    public:
        RuleOf0() = default;
        ~RuleOf0() = default;
        RuleOf0(const RuleOf0& other) = default;
        RuleOf0& operator=(const RuleOf0& other) = default;
        RuleOf0(RuleOf0&& other) = default;
        RuleOf0& operator=(RuleOf0&& other) = default;

        std::string name;
        int number;
};

