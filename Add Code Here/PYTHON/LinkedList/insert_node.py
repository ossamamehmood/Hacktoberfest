class node:
    def __init__(self,val,nxt=None):
        self.val=val
        self.nxt=nxt

class LL:
    def __init__(self,head=None):
        self.head=head

    def insert_node(self,x):
        """
        Code to add node at end
        """
        if not self.head:
            self.head=node(x)
            return
        h=self.head
        while h.nxt:
            h=h.nxt
        h.nxt=node(x)

        
    def Print(self):
        h=self.head
        while h:
            print(h.val,end=' -> ')
            h=h.nxt
        print('NULL')

a=[10,20,40,80,6]
ll=LL()
for i in a:
    ll.insert_node(i)
ll.Print()
