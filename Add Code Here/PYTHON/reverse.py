#Python program to reverse an array
def list_reverse(arr,size):

	#if only one element present, then return the array
	if(size==1):
		return arr
	
	#if only two elements present, then swap both the numbers.
	elif(size==2):
		arr[0],arr[1],=arr[1],arr[0]
		return arr
	
	#if more than two elements presents, then swap first and last numbers.
	else:
		i=0
		while(i<size//2):

	#swap present and preceding numbers at time and jump to second element after swap
			arr[i],arr[size-i-1]=arr[size-i-1],arr[i]
	
	#skip if present and preceding numbers indexes are same
			if((i!=i+1 and size-i-1 != size-i-2) and (i!=size-i-2 and size-i-1!=i+1)):
				arr[i+1],arr[size-i-2]=arr[size-i-2],arr[i+1]
			i+=2
		return arr

arr=[1,2,3,4,5]
size=5
print('Original list: ',arr)
print("Reversed list: ",list_reverse(arr,size))
