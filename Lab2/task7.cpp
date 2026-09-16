#include <iostream>
using namespace std;

int main() {
    int n;

    do {
        cout << "Enter n (1-10): ";
        cin >> n;
    } while (n < 1 || n > 10);

    int *marks = new int[n];

    cout << "Enter " << n << " marks: ";
    for (int i = 0; i < n; i++) {
        cin >> *(marks + i);
    }

    int newMark;
    cout << "Enter new mark: ";
    cin >> newMark;

    // allocate a larger block and copy old values
    int *newMarks = new int[n + 1];
    for (int i = 0; i < n; i++) {
        *(newMarks + i) = *(marks + i);
    }
    *(newMarks + n) = newMark;

    // cleanup old block and update pointer
    delete[] marks;
    marks = newMarks;
    n++;

    // display final array
    cout << "Updated marks: ";
    for (int i = 0; i < n; i++) {
        cout << *(marks + i) << " ";
    }
    cout << endl;

    delete[] marks;
    marks = nullptr;

    return 0;
}