/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        // if(!head)
        //     return NULL;
        // Node * temp=head;
        // while(temp)
        // {
        //     Node * newnode =new Node (temp->val);
        //     newnode->next=temp->next;
        //     temp->next=newnode;
        //     temp=newnode->next; 
        // }
        // temp=head;
        // while(temp)
        // {
        //     if(temp->random)
        //         temp->next->random=temp->random->next;
        //     else
        //         temp->next->random=NULL;
        //     temp=temp->next->next;
        // }
        // temp=head;
        // Node * clone =temp->next;
        // Node * ans=clone;
        // while(temp && clone)
        // {
        //     temp->next= temp->next->next;
        //     clone->next = clone->next ? clone ->next->next : NULL;
            
        //     temp=temp->next;
        //     clone=clone->next;
        // }
        // return ans;

        ///------16-09-2023

        if(!head)
         return NULL;

        Node* temp =head;
        while(temp)
        {
            Node* newnode = new Node(temp->val);
            newnode->next = temp->next;
            temp->next =newnode;
            temp = newnode->next;
        } 
        temp=head;
        while(temp)
        {
            if(temp->random)
            {
                temp->next->random = temp->random->next;
            }
            else 
             temp->next->random =NULL;

            temp = temp->next->next; 
        }
        temp = head;
        Node * clone = temp->next;
        Node * ans = clone;

        while( temp && clone )
        {
            temp->next= temp->next->next;
            clone->next= clone->next ?clone->next->next : NULL;

            temp= temp->next;
            clone=clone->next;
        }
        return ans;
    }
};