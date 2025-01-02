#include <iostream>
#include <string>
using namespace std;

// Base class that depends on some resource
class Resource {
public:
    explicit Resource(const string& resourceName) {
        cout << "Resource initialized with name: " << resourceName << endl;
    }
};

// Base class that depends on a member
class Base {
private:
    Resource& resource;

public:
    explicit Base(Resource& res) : resource(res) {
        cout << "Base initialized using the Resource" << endl;
    }
};

// Derived class with multiple inheritance
class Derived : private Base {
private:
    Resource resource; // Member that Base depends on

public:
    // Multiple inheritance 
    // Inherit either of them lead to wrong order of contructions
    // e.g. member data resource is called after calling Base class constructor
    Derived(const string& resourceName)
        : resource(resourceName), // Initialize Resource first
          Base(resource)          // Pass Resource to Base
    {
        cout << "Derived class fully initialized" << endl;
    }
};

int main() {
    Derived derived("MyResource");

    return 0;
}
