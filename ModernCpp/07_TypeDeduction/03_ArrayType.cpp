#include <iostream>

// although the input is int[] type, it is converted to int* type automatically
void foo(int arr[4]) {
    printf("%d\n", sizeof(arr)); // thus 8 bytes printed here
}

void goo(int (*arr)[3]) {}

int main() {
    int x[4] = {1, 2, 3, 4};

    // Error because assigning address of array x to array of pointers
    // p0[3], then *(p0[3])
    // int *p0[3] = &x;

    // pointer of array
    int (*p1)[4] = &x; 

    // pointer of first element of array 
    int *p2 = x; // same as int *p2 = &x[0]

    printf("%p %p\n", p1, p1+1); // +1 is 16 bytes
    printf("%p %p\n", p2, p2+1); // +1 is 4 bytes

    // Both converts first element to 10
    (*p1)[0] = 10;
    *p2 = 10;

    foo(x);
    
    std::cout << "--------------" << std::endl;
    
    // Handling multi-dim arrays
    int y[4][3] = {0};

    // pointer of array
    int (*p3)[4][3] = &y;

    // pointer of first row of array
    int (*p4)[3] = y; // or &y[0]
    
    goo(y);

}