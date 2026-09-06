#include <iostream>
#include <vector>
/*
 Task 3 - Find All Indices of an Element 

Write a function that finds all indices of a given element in an array. 

Input: Array and a key. 

Output: Vector of indices. 

Test cases: 

Multiple occurrences. 

Key not present. 

Empty array. 
*/


//method to solve the multiple occurences 
//method autmatically handles the null array

std::vector<int> trace(int arr[], int size, int key) {
    std::vector<int> IArray;
    // this varable handles case key not present
    bool case2 = false;

    for (int i = 0; i < size; i++) {
        int anyNumber = arr[i];

        if (anyNumber == key) {
            IArray.push_back(i);
            case2 = true;
        }
    }

    if (!case2) {
        std::cout << " No match Fount ";
    }

    return IArray;
}

//print the original data
void Print(std::vector<int> dataSample) {
    for (int i : dataSample) {
        std::cout << i << " ";
    }

    std::cout << std::endl << std::endl;
}
// print the indices position array
void Print(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << " key : " << key << std::endl;
}

int main() {

    //demo run samples

    int Samples[4][4] = {
        {
            0, 1, 2, 3
        },
        {
            1, 1, 1, 4
        },
        {
            2, 3, 5, 3
        },
        {
            1, 3, 1, 5
        }
    };
    
    // number of test cases are 4 + 1 
    for (int i = 0; i < 4; i++) {

        std::cout << "case " << i << " : ";
        //to find the length of the easy sample instead hardcoding
        int size = sizeof(Samples[i]) / sizeof(Samples[0][0]);

        std::vector<int> IndicesArray = trace(Samples[i], size, i);

        Print(Samples[i], size, i);
        Print(IndicesArray);
    }

    // to check an extra case 
    int case2[1];

    int size = 0;
    std::vector<int> IndicesArray = trace(case2, size, 1);

    Print(case2, size, 1);
    Print(IndicesArray);

    return 0;
}