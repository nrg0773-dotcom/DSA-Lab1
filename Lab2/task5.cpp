#include <iostream>
using namespace std;

void swapValues(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 5, b = 10;

    cout << "Before swap: a = " << a << ", b = " << b << endl;
    
    // passing the addresses of a and b
    swapValues(&a, &b);

    cout << "After swap: a = " << a << ", b = " << b << endl;

    return 0;
}