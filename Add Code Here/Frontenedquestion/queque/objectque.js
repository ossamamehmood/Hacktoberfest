class Queque{
    constructor(){
        this.item={};
        this.rear=0;
        this.front=0
    }
    enque(element){
        this.item[this.rear]=element;
        this.rear++;
    }
    deque(element){
      const first=this.item[this.front];
      delete this.item[this.front];
      this.front++;
      return first
    }
    print(){
        console.log(this.item,this.rear)
    }
}
const que=new Queque();
que.enque(2);
que.enque(56);
que.enque(6);
console.log(que.deque());
que.print()