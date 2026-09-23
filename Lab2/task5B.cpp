#include <iostream>
using namespace std;

void swapValues(int **ppa, int **ppb) {
    int temp = **ppa;
    **ppa = **ppb;
    **ppb = temp;
}

int main() {
    int a = 5, b = 10;
    int *pa = &a;
    int *pb = &b;
    
    int **ppa = &pa;
    int **ppb = &pb;

    cout << "Before swap: a = " << a << ", b = " << b << endl;
    
    swapValues(ppa, ppb);

    cout << "After swap: a = " << a << ", b = " << b << endl;

    return 0;
}