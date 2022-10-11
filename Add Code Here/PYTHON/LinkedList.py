#creation and printing

class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

class LinkedList:
    def __init__(self):
         self.head=None

    def printing(self):
        temp=self.head
        while (temp.next):
            print(temp.data)
            temp=temp.next

# Code execution starts here
if __name__=='__main__':

    lst=LinkedList() #empty list with head = none

    lst.head=Node(1)    #create 1st node with data 1 and prop next none
    second=Node(2)
    third=Node(3)

    #we created three nodes but havent linked yet

    #lets link them together
    lst.head.next=second
    second.next=third

    #for printing lets create a printing function in linkedList
    lst.printing()




