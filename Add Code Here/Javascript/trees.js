class node{
    constructor(value,x){
        this.value=value;
        this.childs=[];
        for(let i=0;i<x;i++){
            this.childs[i]=null;
        }
    }
}

class tree{
    constructor(x){
        this.child=Math.pow(2,x);
        this.arr=[];
        this.root=null;
        this.index=0;
        this.arrindex=0;
    }
    insert(val){
        if(this.arr.length==0){
            this.arr[0]=new node(val,this.child);
            this.root=this.arr[0];
        }
        else{
            if(this.index==this.child-1){
                this.arrindex++;
                this.index=0;
                this.root==this.arr[this.arrindex];
            }
            let temp=new node(val,this.child);
            this.arr[this.arrindex].childs[this.index]=temp;
            this.arr[this.arr.length]=temp;
            this.index++;
        }
    }
}

const x=new tree(2);
x.insert(2);
x.insert(3);
x.insert(4);
console.log(x.arr)