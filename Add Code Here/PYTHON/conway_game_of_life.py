import tkinter
import random
def cycle(arr):                                      #code to find out next generation 
    l=len(arr[0])
    h=len(arr)
    new_arr=[[' ' for _ in range(l)] for _ in range(h)]
    for j in range(h):
        for i in range(l):
            neighbours_alive=0
            for y in [-1,0,1]:
                for x in [-1,0,1]:
                    if (j+y>=0 and j+y<h) and (i+x>=0 and i+x<l):
                        if arr[j+y][x+i]=='.':
                            neighbours_alive+=1                                        
            if arr[j][i]=='.':
                neighbours_alive-=1                                          #removing 1 exrta neighbour included due to x=0 and y=0(original cell) 
                if neighbours_alive>3:
                    new_arr[j][i]=' '
                elif neighbours_alive<2:
                    new_arr[j][i]=' '
                else:
                    new_arr[j][i]='.'
            else:
                if neighbours_alive==3:
                    new_arr[j][i]='.'
                else:
                    new_arr[j][i]=' '
    return new_arr                
def randomarr(l,h):                      #code to generate a random_array(equal odds of generating live or dead cell)
    x=[' ','.']
    rarr=[]
    for j in range(h):
        lst=[]
        for i in range(l):
            lst.append(random.choice(x))
        rarr.append(lst)
    return(rarr)        
def ret_exp(arr,i):
    exp="Generation:"+str(i)+"\n"                   #code to return the grid in the form of a string
    for j in range(len(arr)):
        for i in range(len(arr[0])):
            exp+=arr[j][i]+' '
        exp+="\n"    
    return exp      
def func(grid):
    global i
    global new_arr
    new_arr=cycle(new_arr)
    grid.set(ret_exp(new_arr,i))
    i+=1
def main():
    global i
    global new_arr
    i=1
    window=tkinter.Tk()
    window.title('Conway"s game of life')
    window.geometry("600x920")
    new_arr=randomarr(50,50)
    grid=tkinter.StringVar()
    grid.set(ret_exp(new_arr,i))
    i+=1
    w_label=tkinter.Label(window,textvariable=grid)
    btn=tkinter.Button(window, text = "Next generation", command = lambda:func(grid))        
    w_label.pack()
    btn.pack()
    window.mainloop()        
if __name__=="__main__":
    main()


