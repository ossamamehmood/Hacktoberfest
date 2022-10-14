import matplotlib.pyplot as plt 
import numpy as np 
import pandas as pd
import csv
def calmin(myarr):
    mini=myarr[0]
    for x in myarr:
        if(mini>x):
            mini=x
    
    return mini
def calmax(myarr):
    maxi=myarr[0]
    for x in myarr:
        if(maxi<x):
            maxi=x
    
    return maxi
def calmedian(l,r,myarr):
    n=l+r
    if(n%2==0):
         median=myarr[n//2]
        # print(myarr[n//2])
        
    else:
        first=myarr[n//2]
        second=myarr[(n//2)+1]
        median=(first+second)/2
    
    return median

df=pd.read_csv('plot.csv')
data=df.values.tolist()
myarr=np.array(data)
m=len(myarr)
q2=calmedian(0,m-1,myarr)
if(m%2==0):
    q1=calmedian(0,(m//2)-1,myarr)
    q3=calmedian(m//2,m-1,myarr)
else:
    q1=calmedian(0,(m//2)-1,myarr)
    q3=calmedian((m+1)//2,m-1,myarr)

interquartile=q3-q1
print('Interquartile is',interquartile)
lower_whisker=q1-(1.5*interquartile)
upper_whisker=q3+(1.5*interquartile)
print('lower whisker is',lower_whisker)
print('upper whisker is',upper_whisker)
set=[]
maxi=calmax(myarr)
mini=calmin(myarr)
print('5 nos are:')
set.append(maxi)
set.append(mini)
set.append(q1)
set.append(q2)
set.append(q3)
print(set)
file = open('output.csv', 'w', newline ='')
 
with file:
    # identifying header 
    header = ['Max_Value', 'Min_Value', 'Q1','Q2','Q3','Interquartile','Lower_whisker','Upper_whisker']
    writer = csv.DictWriter(file, fieldnames = header)
     
    # writing data row-wise into the csv file
    writer.writeheader()
    writer.writerow({'Max_Value' : str(maxi),
                     'Min_Value': str(mini),
                     'Q1': str(q1),
                     'Q2':str(q1),
                     'Q3':str(q3),
                     'Interquartile':str(interquartile),
                     'Lower_whisker':str(lower_whisker),
                     'Upper_whisker':str(upper_whisker)})


