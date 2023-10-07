class Queque{
    constructor(){
        this.item=[]
    }
    enque(element){
      this.item.push(element)
    }
    deque(){
      this.item.shift()

    }
    isEmpty(){
   return this.item.length===0
    }
    peak(){
return this.item[0]
    }
    print(){
        console.log(this.item)
    }
}
const queq=new Queque();
queq.enque(1);
queq.enque(12);
queq.enque(13);
queq.enque(14);
queq.print();
queq.deque();
queq.print();
