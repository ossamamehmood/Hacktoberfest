

class Node{
    constructor(value){
        this.value=value
        this.next=null;
    }
}
class Linkedlist{
    constructor(){
        this.head=null;
        this.size=0;
    }
    isEmpty(){
        return this.size===0;
    }
    size(){
        return this.size
    }
    incremant(value){
        const node=new Node();
        node.value=value;
        node.next=this.head;
        this.head=node;

    }
    