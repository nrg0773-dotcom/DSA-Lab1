#include <iostream>
#include <vector>


/*
Task 6 – Histogram Analysis (Mode of Array) 

Write a function that returns the mode (most frequent element) in an array. 

Test cases: 

Array with unique mode. 

Array with multiple modes. 

Empty array. 
*/


// method to find the mode (most frequent element)
// method automatically handles the empty array
std::vector<int> mode(int arr[], int size) {

    std::vector<int> Modes;

    // this variable handles the highest number of occurences
    int highestCount = 0;

    // check every number in the array
    for (int i = 0; i < size; i++) {

        int count = 0;

        // count how many times the current number occurs
        for (int j = 0; j < size; j++) {

            if (arr[i] == arr[j]) {
                count++;
            }
        }

        // new highest occurence found
        if (count > highestCount) {
            highestCount = count;
        }
    }

    // empty array case
    if (highestCount == 0) {
        return Modes;
    }

    // find all numbers having the highest occurence
    for (int i = 0; i < size; i++) {

        int count = 0;

        for (int j = 0; j < size; j++) {

            if (arr[i] == arr[j]) {
                count++;
            }
        }

        // add number if it is a mode
        if (count == highestCount) {

            // this variable checks if the mode is already present
            bool alreadyPresent = false;

            for (int k = 0; k < Modes.size(); k++) {

                if (Modes[k] == arr[i]) {
                    alreadyPresent = true;
                }
            }

            if (!alreadyPresent) {
                Modes.push_back(arr[i]);
            }
        }
    }

    return Modes;
}


// print the mode array
void Print(std::vector<int> dataSample) {

    if (dataSample.size() == 0) {
        std::cout << " No mode found ";
    }

    for (int i : dataSample) {
        std::cout << i << " ";
    }

    std::cout << std::endl << std::endl;
}


// print the original array
void Print(int arr[], int size) {

    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}


int main() {

    // demo run samples

    int Samples[3][5] = {
        {
            1, 4, 2, 3, 4
        },
        {
            1, 1, 2, 2, 3
        },
        {
            1, 2, 3, 4, 5
        }
    };

    // number of test cases are 3 + 1
    for (int i = 0; i < 3; i++) {

        std::cout << "case " << i + 1 << " : ";

        // to find the length of the sample instead of hardcoding
        int size = sizeof(Samples[i]) / sizeof(Samples[0][0]);

        std::vector<int> Modes = mode(Samples[i], size);

        // print the original data
        Print(Samples[i], size);

        // print the mode
        std::cout << "Mode : ";
        Print(Modes);
    }


    // to check an extra empty array case
    int case4[1];

    int size = 0;

    std::vector<int> Modes = mode(case4, size);

    std::cout << "case 4 : ";

    // print the original data
    Print(case4, size);

    // print the mode
    std::cout << "Mode : ";
    Print(Modes);


    return 0;
}
