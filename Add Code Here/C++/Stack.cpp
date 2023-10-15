#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> myStack;

    if (myStack.empty()) {
        cout << "The stack is empty." << endl;
    }

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Size of the stack: " << myStack.size() << endl;

    cout << "Top element of the stack: " << myStack.top() << endl;

    myStack.pop();

    cout << "Popped an element from the stack." << endl;

    cout << "Top element of the stack: " << myStack.top() << endl;

    if (!myStack.empty()) {
        cout << "The stack is not empty." << endl;
    }

    myStack.push(40);
    myStack.push(50);

    cout << "Size of the stack: " << myStack.size() << endl;

    cout << "Stack elements: ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    if (myStack.empty()) {
        cout << "The stack is empty again." << endl;
    }

    return 0;
}
