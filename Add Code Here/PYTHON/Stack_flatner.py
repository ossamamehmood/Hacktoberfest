class Node: 
    def __init__(self, data): 
        self.data = data 
        self.next = None
        self.child = None

def flatenStack(head):
    ptr = head
    stack = []
    stack.append(head)
    previous = None

    while(len(stack) != 0):
        temp = stack[-1]
        stack.pop()

        if (temp.next):
            stack.append(temp.next)
        if (temp.down):
            stack.append(temp.down)

        if (previous != None):
            previous.next = temp

        previous = temp

    return ptr





#First non-repeating character in a stream of characters

from queue import Queue 
def firstnonrepeating(Str): 
    global MAX_CHAR 
    q = Queue() 
    charCount = [0] * MAX_CHAR  
      
    # traverse whole Stream 
    for i in range(len(Str)): 
  
        # push each character in queue  
        q.put(Str[i])  
  
        # increment the frequency count  
        charCount[ord(Str[i]) - 
                  ord('a')] += 1
  
        # check for the non pepeating 
        # character  
        while (not q.empty()):  
            if (charCount[ord(q.queue[0]) - 
                          ord('a')] > 1):  
                q.get()  
            else: 
                print(q.queue[0], end = " ")  
                break
  
        if (q.empty()):  
            print(-1, end = " ") 
    print() 
  
# Driver Code 
MAX_CHAR = 26
Str = "aabcbdde"
firstnonrepeating(Str) 