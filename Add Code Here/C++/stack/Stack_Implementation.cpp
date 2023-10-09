#include<iostream>
using namespace std;


class Stack{
    public:
    int top;
    int *arr; 
    int size;
    
    Stack(int size){
        this->size=size;
        arr =new int[size];
        top=-1;
    }

    void push(int data){
        if(size-top>1){
            top++;
            arr[top]=data;
        }
        else{
            cout<<"Stack OverFlow"<<endl;
        } 
    }
    void pop(){
        if(top>=1){
            top--;
        }
        else{
            cout<<"Stack UnderFlow"<<endl;
        }
    }
    int peek(){  
        if(top>=0 && top <size){
            return arr[top];
        }
        else{
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
    }   
    bool isempty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    void printStack(){
    for(int i=0 ; i<size && i<=top; i++){
            cout<<arr[i]<<" ";
    }
    cout<<endl;

}
};



int main()
{
    Stack stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.printStack();
    stack.pop();
    stack.printStack();
    cout<<stack.peek()<<" -> Top Element"<<endl;
    cout<<stack.isempty()<<" ->Stack Empty Check "<<endl;
    stack.push(88);
    stack.printStack();



    
    return 0;
}
 