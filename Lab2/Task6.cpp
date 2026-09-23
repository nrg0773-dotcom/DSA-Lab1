#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    do {
        cout << "Enter number of students and subjects: ";
        cin >> rows >> cols;
        if (rows <= 0 || cols <= 0) {
            cout << "Invalid input. Try again.\n";
        }
    } while (rows <= 0 || cols <= 0);

    int **marks = new int*[rows];
    int *total = new int[rows]{0};

    // read inputs and calculate totals
    for (int r = 0; r < rows; r++) {
        *(marks + r) = new int[cols];
        for (int c = 0; c < cols; c++) {
            cin >> *(*(marks + r) + c);
            *(total + r) += *(*(marks + r) + c);
        }
    }

    // display matrix
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << *(*(marks + r) + c) << " ";
        }
        cout << endl;
    }

    // find highest scorer
    int bestStudent = 1;
    int highestTotal = *total; 
    for (int r = 1; r < rows; r++) {
        if (*(total + r) > highestTotal) {
            highestTotal = *(total + r);
            bestStudent = r + 1;
        }
    }

    cout << "Top student: " << bestStudent << " with total " << highestTotal << endl;

    // cleanup memory
    for (int r = 0; r < rows; r++) {
        delete[] *(marks + r);
    }
    delete[] marks;
    marks = nullptr;
    delete[] total;

    return 0;
}