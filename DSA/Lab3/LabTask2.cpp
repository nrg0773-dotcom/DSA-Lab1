#include <iostream>

using namespace std;

// class layout
class StringPool
{
public:
    StringPool(int size = 5);
    ~StringPool();

    void addString(string str);
    void removeString();
    void fixMemoryLeak();
    void Print();

private:
    int currentSize = 0;
    int maxSize;
    string *stringPool;
};

// Methood Implemetation

StringPool::StringPool(int size) : maxSize(size)
{
    stringPool = new string[maxSize];
}

StringPool::~StringPool()
{
    delete[] stringPool;
}

void StringPool::addString(string str)
{
    if (currentSize >= maxSize)
        return;
    stringPool[currentSize] = str;
    currentSize++;
}

void StringPool::removeString()
{
    if (currentSize <= 0)
        return;
    currentSize--;
    cout << "Removed. Size changed from " << currentSize + 1 << " to " << currentSize << endl;
    cout << "Data still lingering in memory at index " << currentSize
         << ": " << stringPool[currentSize] << endl;
}

void StringPool::fixMemoryLeak()
{
    cout << "\n[Fixing Leak] Clearing unmanaged memory..." << endl;
    for (int i = currentSize; i < maxSize; i++)
    {
        stringPool[i] = "";
    }
    cout << "Memory cleared. Active size: " << currentSize << ", Max size: " << maxSize << endl;
}

void StringPool::Print()
{
    cout << "Pool Size -> Active: " << currentSize << " | Max: " << maxSize << endl;
    for (int i = 0; i < maxSize; i++)
    {
        cout << "[" << i << "]: " << (stringPool[i].empty() ? "EMPTY" : stringPool[i]) << " ";
    }
    cout << "\n"
         << endl;
}

// taskcases

int main()
{
    StringPool pool(5);

    pool.addString("Alpha");
    pool.addString("Beta");
    pool.addString("Gamma");

    cout << "--- Initial State ---" << endl;
    pool.Print();

    cout << "--- Removing String Without Freeing ---" << endl;
    pool.removeString();
    pool.Print();

    cout << "--- Fixing Memory Leak ---" << endl;
    pool.fixMemoryLeak();
    pool.Print();

    return 0;
}