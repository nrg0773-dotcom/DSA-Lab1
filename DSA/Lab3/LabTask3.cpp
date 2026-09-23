#include <iostream>

using namespace std;










class Node
{
public:
    int data;
    Node *next;

    Node(int value);
};




class TaskNode
{
private:
    Node *head;

    void deleteList();

public:
    TaskNode();
    ~TaskNode();
    void insertAtHead(int value);
    void insertAtThird(int value);
    void displayList() const;
    void deleteLast();
    int countNodes() const;
    void reverseList();
    void searchValue(int value) const;
};








Node::Node(int value) : data(value), next(nullptr) {}

TaskNode::TaskNode() : head(nullptr) {}

TaskNode::~TaskNode()
{
    deleteList();
}

void TaskNode::deleteList()
{
    while (head != nullptr)
    {
        Node *nextNode = head->next;
        delete head;
        head = nextNode;
    }
}

void TaskNode::insertAtHead(int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void TaskNode::insertAtThird(int value)
{
    if (head == nullptr || head->next == nullptr)
    {
        cout << "At least two nodes are required.\n";
        return;
    }

    Node *newNode = new Node(value);
    newNode->next = head->next->next;
    head->next->next = newNode;
}










void TaskNode::displayList() const
{
    const Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL\n";
}

void TaskNode::deleteLast()
{
    if (head == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node *current = head;
    while (current->next->next != nullptr)
        current = current->next;

    delete current->next;
    current->next = nullptr;
}

int TaskNode::countNodes() const
{
    int count = 0;
    const Node *current = head;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}








void TaskNode::reverseList()
{
    Node *previous = nullptr;
    Node *current = head;

    while (current != nullptr)
    {
        Node *nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    head = previous;
}

void TaskNode::searchValue(int value) const
{
    int index = 0;
    const Node *current = head;
    while (current != nullptr)
    {
        if (current->data == value)
        {
            cout << "Value found at index " << index << ".\n";
            return;
        }

        current = current->next;
        index++;
    }

    cout << "Value not found.\n";
}




















void displayMenu()
{
    cout << "\n1. Insert at head\n"
         << "2. Insert at 3rd position\n"
         << "3. Display list\n"
         << "4. Delete last node\n"
         << "5. Count nodes\n"
         << "6. Reverse list\n"
         << "7. Search value\n"
         << "0. Exit\n"
         << "Choice: ";
}



























int main()
{
    TaskNode taskList;
    int choice;

    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int value;
            cout << "Enter value: ";
            cin >> value;
            taskList.insertAtHead(value);
            break;
        }
        case 2:
        {
            int value;
            cout << "Enter value: ";
            cin >> value;
            taskList.insertAtThird(value);
            break;
        }
        
        



        case 3:
            taskList.displayList();
            break;
        case 4:
            taskList.deleteLast();
            taskList.displayList();
            break;
        case 5:
            cout << "Number of nodes: " << taskList.countNodes() << '\n';
            break;
        case 6:
            taskList.reverseList();
            taskList.displayList();
            break;
        case 7:
        {
            int value;
            cout << "Enter value to search: ";
            cin >> value;
            taskList.searchValue(value);
            break;
        }
        case 0:
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
