class Node{
    public:
    int key,value,count;
    Node* next;
    Node* prev;
    Node(int key,int value){
        this->key=key;
        this->value=value;
        count=1;
    }
};
class List{
    public:
    int size;
    Node* head;
    Node* tail;
    List(){
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void addfront(Node *node){
    Node* temp=head->next;
    node->next=temp;
    node->prev=head;
    head->next=node;
    temp->prev=node;
    size++;
}
void removenode(Node* delnode){
    Node* delprev=delnode->prev;
    Node* delnext=delnode->next;
    delprev->next=delnext;
    delnext->prev=delprev;
    size--;
}
};
class LFUCache {
    map<int,Node*>keynode;
    map<int,List*>freqlistmap;
    int maxcache;
    int minfreq;
    int cursz;
public:
    LFUCache(int capacity) {
        maxcache=capacity;
        minfreq=0;
        cursz=0;

        
    }
    void updatefreqlist(Node* node){
        keynode.erase(node->key);
        freqlistmap[node->count]->removenode(node);
        if(node->count==minfreq and freqlistmap[node->count]->size==0){
            minfreq++;
        }
        List* nexthigherfreqlist=new List();
        if(freqlistmap.find(node->count+1)!=freqlistmap.end()){
            nexthigherfreqlist=freqlistmap[node->count+1];
        }
        node->count+=1;
        nexthigherfreqlist->addfront(node);
        freqlistmap[node->count]=nexthigherfreqlist;
        keynode[node->key]=node;
    }
    
    int get(int key) {
        if(keynode.find(key)!=keynode.end()){
            Node* node=keynode[key];
            int val=node->value;
            updatefreqlist(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxcache==0)return;
        if(keynode.find(key)!=keynode.end()){
            Node* node=keynode[key];
            node->value=value;
            updatefreqlist(node);
        }
        else{
            if(cursz==maxcache){
                List* list=freqlistmap[minfreq];
                keynode.erase(list->tail->prev->key);
                freqlistmap[minfreq]->removenode(list->tail->prev);
                cursz--;
            }
            cursz++;
            minfreq=1;
            List* listfreq=new List();
            if(freqlistmap.find(minfreq)!=freqlistmap.end()){
                listfreq=freqlistmap[minfreq];
            }
            Node *node=new Node(key,value);
            listfreq->addfront(node);
            keynode[key]=node;
            freqlistmap[minfreq]=listfreq;
            
        }
    }
};
