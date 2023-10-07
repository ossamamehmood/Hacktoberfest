#include <iostream>
#include <queue>
using namespace std;

class Queue {

public:
  int *arr;
  int front;
  int rear;
  int size;

  Queue(int s) {
    this->size = s;
    arr = new int[size];
    front = 0;
    rear = 0;
  }
  void push(int data) {
    if (front == size) {
      cout << "Queue is full" << endl;
    } else {
      arr[rear] = data;
      rear++;
    }
  }

  void pop() {
    if (front == rear) {
      cout << "Queue is empty" << endl;
    } else {
      arr[front] = -1;
      front++;

      if (front == rear) {
        front = 0;
        rear = 0;
      }
    }
  }

  int getFront() {
    if (front == rear) {
      cout << "Queue is empty" << endl;
      return -1;
    } else {
      return arr[front];
    }
  }

  bool isEmpty() {
    if (front == rear) {
      return true;
    } else {
      return false;
    }
  }

  int getSize() { return rear - front; }
};
int main() {

  Queue q(5);
  q.push(5);
  q.push(10);
  q.push(20);
  q.push(1);

  //   cout << q.getSize() << endl;
  q.pop();
  cout << q.getFront() << endl;

  return 0;
}
