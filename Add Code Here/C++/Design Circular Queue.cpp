class MyCircularQueue {
    vector<int> v;
    int s=-1,r=-1;
    int k=0;
public:
    MyCircularQueue(int k) {
        v.resize(k);
        this->k=k;
        s=-1; r=-1;
        
    }
    
    bool enQueue(int value) {
        
        if(s==-1 && r==-1)
        {
            s=0;
            r=0;
            v[0]=value;
            return 1;
        }
        
        if( (r+1)%k==s )
            return 0;
        
        r= r+1;
        r%=k;
        
        v[r]=value;
        return 1;
        
        
        
    }
    
    bool deQueue() {
        
        if(s==-1 && r==-1)
            return 0;
        
        if(r==s)
        {
            r=-1;
            s=-1;
            return 1;
        }
        
       s++;
        s%=k;
        return 1;
        
        
    }
    
    int Front() {
        if(s==-1)
            return -1;
        
        return v[s];
        
    }
    
    int Rear() {
        
        if(r==-1)
            return -1;
        return v[r];
        
    }
    
    bool isEmpty() {
        
        if(s==-1)
            return 1;
        return 0;
        
    }
    
    bool isFull() {
        if((r+1)%k==s)
            return 1;
        return 0;
    }
};
