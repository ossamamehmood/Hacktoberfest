#!/usr/bin/env python
# coding: utf-8

# # Practice Notebook: Reading and Writing Files

# In this exercise, we will test your knowledge of reading and writing files by playing around with some text files. 
# <br><br>
# Let's say we have a text file containing current visitors at a hotel.  We'll call it, *guests.txt*.  Run the following code to create the file.  The file will automatically populate with each initial guest's first name on its own line.

# In[2]:


guests = open("guests.txt", "w")
initial_guests = ["Bob", "Andrea", "Manuel", "Polly", "Khalid"]

for i in initial_guests:
    guests.write(i + "\n")
    
guests.close()


# No output is generated for the above code cell.  To check the contents of the newly created *guests.txt* file, run the following code.

# In[3]:


with open("guests.txt") as guests:
    for line in guests:
        print(line)


# The output shows that our *guests.txt* file is correctly populated with each initial guest's first name on its own line.  Cool!
# <br><br>
# Now suppose we want to update our file as guests check in and out.  Fill in the missing code in the following cell to add guests to the *guests.txt* file as they check in.

# In[5]:


new_guests = ["Sam", "Danielle", "Jacob"]

with open("guests.txt", 'a') as guests:
    for i in new_guests:
        guests.write(i + "\n")

guests.close()


# To check whether your code correctly added the new guests to the *guests.txt* file, run the following cell.

# In[6]:


with open("guests.txt") as guests:
    for line in guests:
        print(line)


# The current names in the *guests.txt* file should be:  Bob, Andrea, Manuel, Polly, Khalid, Sam, Danielle and Jacob.
# <br><br>
# Was the *guests.txt* file correctly appended with the new guests? If not, go back and edit your code making sure to fill in the gaps appropriately so that the new guests are correctly added to the *guests.txt* file.  Once the new guests are successfully added, you have filled in the missing code correctly.  Great!
# <br><br>
# Now let's remove the guests that have checked out already.  There are several ways to do this, however, the method we will choose for this exercise is outlined as follows:
# 1. Open the file in "read" mode.
# 2. Iterate over each line in the file and put each guest's name into a Python list.
# 3. Open the file once again in "write" mode.
# 4. Add each guest's name in the Python list to the file one by one.
# 
# <br>
# Ready? Fill in the missing code in the following cell to remove the guests that have checked out already.

# In[ ]:


checked_out=["Andrea", "Manuel", "Khalid"]
temp_list=[]

with open("guests.txt", 'r') as guests:
    for g in guests:
        temp_list.append(g.strip())




# To check whether your code correctly removed the checked out guests from the *guests.txt* file, run the following cell.

# In[ ]:


with open("guests.txt") as guests:
    for line in guests:
        print(line)


# The current names in the *guests.txt* file should be:  Bob, Polly, Sam, Danielle and Jacob.
# <br><br>
# Were the names of the checked out guests correctly removed from the *guests.txt* file? If not, go back and edit your code making sure to fill in the gaps appropriately so that the checked out guests are correctly removed from the *guests.txt* file. Once the checked out guests are successfully removed, you have filled in the missing code correctly. Awesome!
# <br><br>
# Now let's check whether Bob and Andrea are still checked in.  How could we do this? We'll just read through each line in the file to see if their name is in there.  Run the following code to check whether Bob and Andrea are still checked in.

# In[7]:


guests_to_check = ['Bob', 'Andrea']
checked_in = []

with open("guests.txt","r") as guests:
    for g in guests:
        checked_in.append(g.strip())
    for check in guests_to_check:
        if check in checked_in:
            print("{} is checked in".format(check))
        else:
            print("{} is not checked in".format(check))


# We can see that Bob is checked in while Andrea is not.  Nice work! You've learned the basics of reading and writing files in Python!
