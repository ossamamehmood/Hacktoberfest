#include <iostream>
#include <stack>
using namespace std;

class queue {
public:
    stack<int> s1;
    stack<int> s2;

    // insert
    void enqueue(int value) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(value);

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // delete
    void dequeue() {
        if (s1.empty()) {
            cout << -1 << endl;
        } else {
            cout << s1.top() << endl;
            s1.pop();
        }
    }

    void display() {
        while (!s1.empty()) {
            cout << s1.top() << " ";
            s1.pop();
        }
    }
};

int main() {
    queue q;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        q.enqueue(i);
    }

    q.display();
}
