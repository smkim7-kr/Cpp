class BoolObj {
    bool state = true;
    int value = 0;
    public:
        // Default constructor
        BoolObj() {}

        // safe bool - explicit conversion operator
        explicit operator bool() { return state; }

        // C++20 - explciit(bool)
        explicit(false) BoolObj(int val) : value(val) {}
};

int main(){
    BoolObj bo;

    // Cause error since implicit conversion
    // bool b1 = bo;

    // Explicit conversion
    bool b2 = static_cast<bool>(bo);

    // error if explicit(true)
    BoolObj bo2 = 20;

}