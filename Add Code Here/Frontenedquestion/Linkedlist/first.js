


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
       console.log(this.size)
    }
    incremant(value){
        const node=new Node(value);
     
        node.next=this.head;
        this.head=node;
        this.size++

    }
    print(){
        console.log(this.head)
    }
    
}
const linked=new Linkedlist();
linked.incremant(3);
linked.incremant(4);
linked.print()
linked.size()
