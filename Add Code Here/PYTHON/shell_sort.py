# Python3 program for implementation of Shell Sort
# Python3 program for implementation of Shell Sort

def shellSort(arr, n):

	gap=n//2
	
	
	while gap>0:
		j=gap
	
		while j<n:
			i=j-gap 
			
			while i>=0:
			
				if arr[i+gap]>arr[i]:

					break
				else:
					arr[i+gap],arr[i]=arr[i],arr[i+gap]

				i=i-gap 
			j+=1
		gap=gap//2





arr2 = [12, 34, 54, 2, 3]
print("input array:",arr2)

shellSort(arr2,len(arr2))
print("sorted array",arr2)

