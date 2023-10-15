#include <iostream>
using namespace std;
class StackOverflow: exception{};
class StackUnderflow: exception{};
class Stack{
int *stk;
int top = -1;
int size;
public:
Stack(int sz){
    size = sz;
    stk = new int[sz];
}
void push(int x){
    if (top == size-1){
        throw StackOverflow();
    }
    else{
        top++;
        stk[top] = x;
    }
}
int pop(){
    if(top == -1){
        throw StackUnderflow();
    }
    else{
        return stk[top--];
    }
}

};
int main(){
    Stack s(5);
    s.push(1);
    s.push(5);
    s.push(65);
    s.push(45);
    
    
    s.push(55);
    s.push(5);
    cout << s.pop();
    return 0;
}