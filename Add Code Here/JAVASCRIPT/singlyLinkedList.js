class Node{
    constructor(value, next=null){
        this.value = value;
        this.next = next;
    }
}

class SinglyLL{
    constructor(){
        this.head = null;
        this.size = 0;
    }

    // Insert functionality
    insertFirst(value){
        let node = new Node(value);
        if(this.head === null){
            this.head = node;
        } else {
            node.next = this.head;
            this.head = node;
        }
        this.size +=1;
    }

    lastInsert(value){
        let node = new Node(value);
        if(this.head === null){
            this.insertFirst(value);
            return;
        }
        let temp = this.head;
        while(temp.next !== null){
            temp = temp.next;
        }
        temp.next = node;
        this.size +=1;
    }

    insert(index,value){
        if(index === this.size){
            this.lastInsert(value);
            return;
        }
        if(index ===0){
            this.insertFirst(value);
            return;
        }
        let temp = this.head;
        for(let i =1; i<index; i++){
            temp = temp.next;
        }
        let node = new Node(value, temp.next);
        temp.next = node;;

        this.size +=1;
    }

    // Delete Functionality;
    firstDelete(){
        if(this.head === null){
            console.log("Empty LL");
            return;
        }
        if(this.head.next === null){
            this.head = null;
            return;
        }
        this.head = this.head.next;
        this.size -=1;
    }
    
    lastDelete(){
        if(this.head === null){
            console.log('Empty LL');
            return;
        }
        if(this.head.next === null){
            this.head = null;
            return;
        }

        let temp = this.head;
        while(temp.next.next !== null){
            temp = temp.next;
        }
        temp.next = null;
        this.size -=1;
    }

    delete(index){
        if(index === 0){
            this.firstDelete();
            return;
        }
        if(index === this.size -1){
            this.lastDelete();
            return;
        }
        let temp = this.head;
        for(let i=1; i<index; i++){
            temp = temp.next;
        }
        temp.next = temp.next.next;
        this.size -=1;
    }
    //Display
    display(){
        let temp = this.head;
        let answer = "";
        while(temp !== null){
            answer += `${temp.value} ->`
            temp = temp.next;
        }
        answer += 'END';
        console.log(answer);
    }
}

let s = new SinglyLL();
s.insertFirst(30);
s.insertFirst(25);
s.insertFirst(22);
s.insertFirst(15);

s.lastInsert(35);
s.lastInsert(40);
s.lastInsert(50);
s.lastInsert(55);

s.insert(2,32);
s.insert(1,27);


s.firstDelete();
s.firstDelete();

s.lastDelete();
s.lastDelete();

s.delete(1);
s.delete(2);

s.display()
console.log(s.size);
