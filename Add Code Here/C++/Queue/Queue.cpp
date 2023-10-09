#include<iostream>
#include<queue>
using namespace std;

class Queue {
    int *arr;
    int qfront;
    int size;
    int rear;
    
public:
    
    
    Queue() {
       size=100001;
        arr=new int[size];
        qfront=0;
        rear=0;
        
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(rear == qfront){
            return true;
        }
        else{
            return false;
        }
    }
    

    void enqueue(int data) {
        // Implement the enqueue() function
        if (rear==size){
         return;
        }
        else{
            arr[rear]=data;         
            rear++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(rear==qfront){
            return -1;
        }
        int ele=arr[qfront];
        arr[qfront] = -1;
        qfront++;
        if(qfront==rear){
        qfront=0;
        rear=0;
        }
        
        return ele;
    }

    int front() {
        // Implement the front() function
        if(rear==qfront){
            return -1;
        }
        return arr[qfront];
    }
};