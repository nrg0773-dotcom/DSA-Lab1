#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str) {
    int left = 0;
    int right = str.length() - 1;
    
    cout << "String size: " << str.length() << " | Checking indices..." << endl;

    while (left < right) {
        cout << "Comparing index [" << left << "] ('" << str[left] << "') with index [" << right << "] ('" << str[right] << "')" << endl;
        
        if (str[left] != str[right]) {
            return false;
        }
        
        left++;
        right--;
    }
    return true;
}



















































int main() {
    string input;
    
    cout << "Enter a string: ";
    cin >> input;

    if (isPalindrome(input)) {
        cout << "Result: The string IS a palindrome." << endl;
    } else {
        cout << "Result: The string IS NOT a palindrome." << endl;
    }

    return 0;
}