class Multistack:
    def __init__(self,stacksize):
        self.numberstacks=3
        self.cust=[0]*(stacksize*self.numberstacks)
        self.sizes=[0]*self.numberstacks
        self.stacksize=stacksize
    def __str__(self):
        values=[str(i) for i in self.cust]
        return " ".join(values)
    def isfull(self,stacknum):
        if self.sizes[stacknum]==self.stacksize:
            return True
        else:
            return False
    def isempty(self,stacknum):
        if self.sizes[stacknum]==0:
            return True
        else:
            return False
    def indexoftop(self,stacknum):
        oo=stacknum*self.stacksize
        return oo+self.sizes[stacknum]-1
    def push(self,item,stacknum):
        if self.isfull(stacknum):
            return "the stack is full"
        else:
            self.sizes[stacknum]+=1
            self.cust[self.indexoftop(stacknum)]=item
    def pop(self,stacknum):
        if self.isempty(stacknum):
            return "the stack is empty"
        else:
            value=self.cust[self.indexoftop(stacknum)]
            self.cust[self.indexoftop(stacknum)]=0
            self.sizes[stacknum]-=1
            return value
mp=Multistack(3)
mp.push(3,0)
mp.push(8,1)
mp.push(11,2)
mp.push(4,0)
mp.push(9,1)
mp.push(10,2)
print(mp)
mp.pop(1)
mp.pop(1)
print(mp.pop(1))
print(mp)


            
    
