// stack is a absrtact data structure which follow lifo(last in first out)


class Stack{
    constructor(){
        this.item=[]
    }
    push(element){
      this.item.push(element)
    }
    pop(){
      this.item.pop()

    }
    isEmpty(){
   return this.item.length===0
    }
    peak(){
return this.item[this.item.length-1]
    }
    print(){
        console.log(this.item)
    }
}
const stack=new Stack();
stack.push(1);
stack.push(12);
stack.push(13);
stack.push(14);
stack.print();
stack.pop();
stack.print();