#include <iostream>
#include <string>

/*
Task 4 – String Pattern Matching (Naive Algorithm) 

Write a function that finds the first occurrence of a substring (pattern) in a given text. If not found, the function will return -1. 

Test cases: 

Pattern at the beginning. 

Pattern at the end. 

Pattern not present. 

Empty pattern. 
*/

// method to find the first occurrence of a pattern in text
// method automatically handles the empty pattern
int patternMatch(std::string text, std::string pattern) {

    // empty pattern is considered to be found at index 0
    if (pattern.size() == 0) {
        return 0;
    }

    // pattern cannot fit inside the text
    if (pattern.size() > text.size()) {
        return -1;
    }

    // check every possible starting position
    for (int i = 0; i <= text.size() - pattern.size(); i++) {

        // this variable checks if the complete pattern matches
        bool match = true;

        // compare pattern characters with text characters
        for (int j = 0; j < pattern.size(); j++) {

            if (text[i + j] != pattern[j]) {
                match = false;
                break;
            }
        }

        // first complete match found
        if (match) {
            return i;
        }
    }

    // pattern was not found
    return -1;
}


// print the result
void Print(std::string text, std::string pattern, int index) {

    std::cout << "Text : " << text << std::endl;
    std::cout << "Pattern : " << pattern << std::endl;
    std::cout << "Index : " << index << std::endl;
    std::cout << std::endl;
}


int main() {

    // demo run samples

    std::string TextSamples[4] = {
        "Hello World",
        "This is my World",
        "Hello World",
        "Hello World"
    };

    std::string PatternSamples[4] = {
        "Hello",
        "World",
        "Python",
        ""
    };

    // number of test cases are 4
    for (int i = 0; i < 4; i++) {

        std::cout << "case " << i + 1 << " : " << std::endl;

        int index = patternMatch(TextSamples[i], PatternSamples[i]);

        Print(TextSamples[i], PatternSamples[i], index);
    }

    return 0;
}
