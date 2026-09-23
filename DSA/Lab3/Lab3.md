# Lab 3: Data Structures and C++ Programming Concepts

This lab covers three important programming concepts in C++:

- Memory management and memory leaks
- Linked list operations
- String-based algorithm design using palindrome checking

## Files included

- [LabTask1.cpp](./LabTask1.cpp)
- [LabTask2.cpp](./LabTask2.cpp)
- [LabTask3.cpp](./LabTask3.cpp)

## Task 1: String Pool Memory Leak Demonstration

### Objective
To understand how unmanaged memory behaves when a string is removed from a fixed-size array without properly clearing the old data.

### Concepts covered
- Dynamic memory allocation using `new`
- Array of strings
- Destructor cleanup using `delete[]`
- Memory leak concept
- Fixing stale data by resetting unused positions

### Program behavior
The class `StringPool` stores a fixed number of strings in a dynamically allocated array.

Operations performed:
- Add strings to the pool
- Remove the last active string
- Display the remaining memory state
- Clear the leftover/unmanaged memory in the free slots

### Key idea
The `removeString()` function decrements the active size, but it does not actually erase the data in memory. The stale values still remain in the old index until overwritten. The `fixMemoryLeak()` function clears those unused slots by assigning empty strings.

### Example flow
1. Add three strings: Alpha, Beta, Gamma
2. Remove the last one
3. Observe the lingering value in the old slot
4. Clear memory and re-display the pool

---

## Task 2: Linked List Operations

### Objective
To implement and manipulate a singly linked list using dynamic nodes and custom class functions.

### Concepts covered
- Nodes and linked list structure
- Insertion at head
- Insertion at a specific position
- Deletion of the last node
- Counting nodes
- Reversing the list
- Searching for a value
- Destructor cleanup

### Structure used
```cpp
class Node {
public:
    int data;
    Node *next;
};
```

### Operations implemented
- `insertAtHead(int value)`
- `insertAtThird(int value)`
- `displayList() const`
- `deleteLast()`
- `countNodes() const`
- `reverseList()`
- `searchValue(int value) const`

### Important note
The destructor calls `deleteList()` to free all dynamically allocated nodes and avoid memory leaks.

---

## Task 3: Palindrome Checker

### Objective
To verify whether a user-entered string is a palindrome using a two-pointer comparison approach.

### Concepts covered
- String input and output
- Character indexing
- Two-pointer technique
- Loop-based validation

### Algorithm
The function `isPalindrome(string str)` compares the first character with the last character, then moves inward until the middle is reached.

```cpp
int left = 0;
int right = str.length() - 1;

while (left < right) {
    if (str[left] != str[right])
        return false;
    left++;
    right--;
}
return true;
```

### Example
Input:
```text
madam
```

Output:
```text
Result: The string IS a palindrome.
```

---

## Learning outcomes

By completing this lab, students should be able to:

- Understand dynamic memory management in C++
- Recognize memory leaks and stale data behavior
- Implement basic linked list operations
- Apply pointer-based logic to solve computational problems
- Write and debug simple string-processing algorithms

## How to run

Open a terminal in the Lab3 folder and compile each task separately:

```bash
g++ LabTask1.cpp -o LabTask1.exe
g++ LabTask2.cpp -o LabTask2.exe
g++ LabTask3.cpp -o LabTask3.exe
```

Then run:

```bash
./LabTask1.exe
./LabTask2.exe
./LabTask3.exe
```

On Windows PowerShell, you may run them as:

```powershell
.\LabTask1.exe
.\LabTask2.exe
.\LabTask3.exe
```

## Summary

This lab demonstrates three foundational topics in data structures and C++ programming: memory management, linked list logic, and expression of algorithmic thinking through palindrome detection.
