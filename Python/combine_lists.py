# Python3 code to demonstrate list
# concatenation using list.extend()
  
# Initializing lists
test_list3 = [1, 4, 5, 6, 5]
test_list4 = [3, 5, 7, 2, 5]
  
# using list.extend() to concat
test_list3.extend(test_list4)
  
# Printing concatenated list
print ("Concatenated list using list.extend() : "
                               + str(test_list3))
