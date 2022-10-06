available=[]
max_demand=[]
allocated=[]
need=[]
n=int(input("enter number of resources:"))
for i in range(n):
    temp=int(input("\nEnter no of available instances of R{:d}:".format(i)))
    available.append(temp)
proc_no=int(input("\nenter total number of processes:"))
finish=[1]*proc_no
for i in range(proc_no):
    temp=[]
    for j in range(n):
        temp.append(int(input("\nEnter the max no of instances of R{:d} for P{:d}:".format(j,i))))
    max_demand.append(temp)
for i in range(proc_no):
    temp=[]
    for j in range(n):
        temp.append(int(input("\nEnter the no of instances of R{:d} allocated for P{:d}:".format(j,i))))
        available[j]-=temp[j]
    allocated.append(temp)
for i in range(proc_no):
    temp=[]
    for j in range(n):
        temp.append(max_demand[i][j]-allocated[i][j])
    need.append(temp)

def printmatr(name):
    for i in name:
        for j in i:
            print(j,end=' ')
        print()
work=available.copy()  #length is n

counter = proc_no
safe_sequence=[]
while counter != 0:
        safe = False
        for i in range(proc_no):
            if finish[i]:
                executing = True
                for j in range(n):
                    if need[i][j] > available[j]:
                        executing = False
                        break
                if executing:
                    safe_sequence.append(i)
                    finish[i] = False
                    counter -= 1
                    safe = True
                    for j in range(n):
                        available[j] += allocated[i][j]
                    
                    
        if not safe:
            print("the processes are in an unsafe state.")
            break

print("need:\n") 
printmatr(need)
print("max_dem:\n")  
printmatr(max_demand)
print("Allocated:\n")
printmatr(allocated)
print("safe sequence:\n")       
for i in safe_sequence:
    print(f"P{i+1}",end="->")

