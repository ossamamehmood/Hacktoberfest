#include <iostream>
using namespace std;

// Generic Class for Implementing Stack

template <typename T>
class Stack
{
private:
    T *stackArray;
    int index;
    int capacity;

    void changeSize()
    {
        T *newstackArray = new T[capacity * 2];
        for (int i = 0; i < capacity; i++)
        {
            newstackArray[i] = stackArray[i];
        }
        capacity *= 2;
        delete[] stackArray;
        stackArray = newstackArray;
    }

public:
    Stack()
    {
        capacity = 5;
        stackArray = new T[capacity];
        index = 0;
    }
    Stack(int totalSize)
    {
        capacity = totalSize;
        stackArray = new int[capacity];
        index = 0;
    }

    void push(T element)
    {
        if (index == capacity)
        {
            changeSize();
        }
        stackArray[index] = element;
        index++;
    }
    int size()
    {
        return index;
    }

    bool isEmpty()
    {
        if (size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "Empty stack" << endl;
            return 0;
        }
        else
        {
            int temp = stackArray[index - 1];
            index = index - 1;
            return temp;
        }
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "Empty stack" << endl;
            return 0;
        }
        else
        {
            return stackArray[index - 1];
        }
    }
};