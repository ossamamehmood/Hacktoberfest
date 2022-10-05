class Node{
    int info;
    Node next,prev,start=null,ptr;
    Node(){
        this.start=null;
    }
    Node(int info){
        this.info=info;
        this.next=null;
        this.prev=null;
    }
    void add(int info){
        Node n=new Node(info);
        if(start==null){
            start=n;
        }
        else{
            ptr=start;
            while(ptr.next!=null){
                ptr=ptr.next;
            }
            n.prev=ptr;
            ptr.next=n;
        }
    }

    void add(int info,int index){
        Node n=new Node(info);
        if(start==null){
            start=n;
        }
        else if(index==0){
            push(info);
        }        
        else{            
            ptr=start;
            int count=1;
            while(count<index && ptr!=null){
                ptr=ptr.next;
                count++;
            }
            if(ptr==null || ptr.next==null){
                add(info);
            }
            else{
                Node x=ptr.next;
                n.next=x;
                n.prev=ptr;
                ptr.next=n;
                x.prev=n;
            }
        }
    }
    
    void push(int info){
        Node n=new Node(info);
        if(start==null){
            start=n;
        }
        else{
            n.next=start;
            start.prev=n;
            start=n;            
        }
    }
    Node pop(){
        Node temp=null;
        if(start==null){
            System.out.println("Underflow");
            return temp;
        }
        else if(start.next==null){
            start=null;
            return temp;
        }
        else{
            temp=start;
            start=temp.next;
            start.prev=null;
            temp.next=null;
        }
        return temp;
    }
    Node delete(){
        Node temp=null;
        if(start==null){
            System.out.println("Underflow");
            return temp;
        }
        else if(start.next==null){
            start=null;
            return temp;
        }
        else{
            ptr=start;
            while(ptr.next.next!=null){
                ptr=ptr.next;
            }
            temp=ptr.next;
            ptr.next=null;
            temp.prev=null;
        }
        return temp;
    }
    Node delete(int pos){ //first position is 1 not 0
        Node temp=null;
        if(start==null){
            System.out.println("Underflow");
            return temp;
        }
        else if(start.next==null){
            start=null;
            return temp;
        }
        else{
            if(pos==0){ //dont write if starting =0
                System.out.println("Invalid position");
                return temp;
            }
           else if(pos==1){ //pos==0 in case of starting=0
                return pop();
            }
            else{
                int count=1;
                ptr=start;
                while(count<pos-1 && ptr!=null){ //if starting=0 count<pos ,if starting=1 count<pos-1
                    ptr=ptr.next;
                    count++;
                }
                if(ptr==null || ptr.next==null){
                    System.out.println("Overflow");
                    return temp;
                }
                else{
                temp=ptr.next;
                if(temp.next==null){
                    ptr.next=null;
                    temp.prev=null;
                    return temp;
                }
                ptr.next=temp.next;
                temp.next.prev=ptr;
                temp.next=null;
                temp.prev=null;  
                }
            }
        }
        return temp;
    }

    int deleteInfo(int info){
        Node temp=null;
        if(start==null){
            System.out.println("Underflow");
            return -1;
        }
        else if(start.next==null){
            temp=start;
            start=null;
            return temp.info;
        }
        else{
            if(start.info==info){
                temp=pop();
                return temp.info;
            }
            ptr=start;
            while(ptr.next.info!=info && ptr!=null){
                ptr=ptr.next;
            }
            if(ptr!=null){
                temp=ptr.next;
                if(temp.next!=null){
                ptr.next=temp.next;
                temp.next.prev=ptr;
                temp.next=null;
                temp.prev=null;
                }
                else{
                    ptr.next=null;
                    temp.prev=null;
                }                
            }
            else{
                System.out.println("Overflow");
                return -1;
            }
        }
        return temp.info;
    }
    //add a swap function
    void print(){
        if(start==null){
            System.out.println("No element in list");
        }
        else{
            ptr=start;
            while(ptr!=null){
                System.out.print(ptr.info+" ");
                ptr=ptr.next;
            }
        }
        System.out.println();
    }
}
class DoubleLinkedList {
    public static void main(String[] args) {
        Node li=new Node();
        li.print();
        li.add(10);
        li.add(20);
        li.add(30);
        li.add(40);
        li.add(50);
        li.print();
        li.push(60);
        li.push(70);
        li.push(80);
        li.push(90);
        li.push(100);
        li.print();
        li.add(10,56);
        li.add(15,83);
        li.add(0,0);
        li.add(1,1);
        li.add(2,2);
        li.add(564,7); 
        li.print();
        li.pop();
        li.pop();
        li.print();
        li.delete();
        li.delete();
        li.print();
        li.delete(1);
        li.print();
        li.delete(2);
        li.print();
        li.delete(3);
        li.print();
        System.out.println(li.deleteInfo(50));
        // System.out.println(li.deleteInfo(678));
        li.print();
    }
}
