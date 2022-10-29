#include<string>
#include<iostream>
using namespace std;
template<typename V>
//MapNode class for key-value pair
class MapNode{
    public:
    string key;
    V value;
    MapNode* next;
    MapNode(string key,V value){
        this->key=key;
        this->value=value;
        next=NULL;
    }
    ~MapNode(){
        delete next;
    }
};

//Map 
template<typename V>
class ourmap{
     MapNode<V>** buckets;
     int size;
     int numBuckets;
    int getBucketIndex(string key){
         int hashcode=0;
         int currentcoeff = 1;
         for(int i=key.length()-1;i>=0;i--){
             hashcode+=key[i]*currentcoeff;
             currentcoeff*=37;
             currentcoeff=currentcoeff % numBuckets;
         }
         return hashcode % numBuckets;
     }
     void rehash(){
        MapNode<V>** temp=buckets;
        buckets= new MapNode<V>* [2*numBuckets];
        for(int i=0;i<2*numBuckets;i++){
            buckets[i]=NULL;
        }
        int oldBucket=numBuckets;
        numBuckets*=2;
        size=0;

        for(int i=0;i<oldBucket;i++){
            MapNode<V>* head=temp[i];
            while(head!=NULL){
                string key=head->key;
                V value=head->value;
                insert(key,value);
                head=head->next;
            }
        }
        for(int i=0;i< oldBucket;i++){
            MapNode<V>* head=temp[i];
            delete head;
        }
        delete [] temp;
     }
     public:
     double Getloadfactor(){
        return (1.0*size)/numBuckets;
     }
     ourmap(){
         size=0;
         numBuckets=5;
         buckets=new MapNode<V>*[numBuckets];
         for(int i=0;i<numBuckets;i++){
             buckets[i]=NULL;
         }
     }
     ~ourmap(){
         for(int i=0;i<numBuckets;i++){
             delete buckets[i];
         }
         delete [] buckets;
     }
     int GetSize(){
         return size;
     }
     V getValue(string key){                           //search
        int bucketIndex=getBucketIndex(key);
           MapNode<V>* head=buckets[bucketIndex];
           while(head!=NULL){
               if(head->key==key){
                   return head->value;
               }
               head=head->next;
           }
           return 0;
     }

     void insert(string key,V value){             //insert
        int bucketIndex=getBucketIndex(key);
        MapNode<V>* head=buckets[bucketIndex];
        while(head!=NULL){
            if(head->key == key){
                head->value=value;
            }
            head=head->next;
        }
        head=buckets[bucketIndex];
        MapNode<V>* node=new MapNode<V>(key,value);
        node->next=head;
        buckets[bucketIndex] = node;
        size++;
        double loadFactor=(1.0*size)/numBuckets;
        if(loadFactor > 0.7){
            rehash();
        }
     }

     V remove(string key){               //remove
       int bucketIndex=getBucketIndex(key);
       MapNode<V>* head=buckets[bucketIndex];
       MapNode<V>* prev=NULL;
       while(head!=NULL){
           if(head->key==key){
               if(prev==NULL){
              buckets[bucketIndex]=head->next;
               }
               else{ 
               prev->next=head->next;
           }
           V value=head->value;
           head->next=NULL;
           delete head;
           size--;
           return value;
           }
           prev=head;
           head=head->next;
       }
       return 0;
     }

};
int main(){
    ourmap<int> m;
    for(int i=0;i<10;i++){
        char c='0' + i;
        string key="abc";
        key +=c;
        int value= i + 1;
        m.insert(key,value);
        cout << m.Getloadfactor() << endl;
    }
    for(int i=0;i<10;i++){
        char c='0' + i ;
        string key= "abc";
        key+=c;
        cout << key << " : " << m.getValue(key) << endl;
    }
    cout << m.GetSize() << endl;
    m.remove("abc2");
    m.remove("abc3");
     cout << m.GetSize() << endl;
    for(int i=0;i<10;i++){
        char c='0' + i ;
        string key= "abc";
        key+=c;
        cout << key << " : " << m.getValue(key) << endl;
    }
}
