// Check if node is palindrome or not
// There are some steps to follow for the solving the problem

// 1. Find the middle node
// 2. Reverse the second part of the list 
// 3. Compare the second part with the first part if the data is not equl return false

boolean Palindrom(Node*head){
    if(head==NULL){
        cout<<"No node exist "<<endl;
        return true;
    }
    else {
        Node*mid=middle(head);
        Node* last = reverse(mid->next)// also check reverse(mid);
        Node*current=head;
        
        while(last!=NULL){
            if(last->data!=current->data)
            return false;
            
            last= last->next;
            current=current->next;
        }
        return true;
    }
}