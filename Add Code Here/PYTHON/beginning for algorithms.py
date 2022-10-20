#!/usr/bin/env python
# coding: utf-8

# In[1]:


#file imports
import pandas as pd
from apyori import apriori


# In[2]:


#data file reading
store_data = pd.read_csv("store_data.csv", header=None)

#get values of firstfive rows in datafile
display(store_data.head())


# In[3]:


#read total data size byrows and colums
store_data.shape


# In[5]:


#create a list and add data to list
records = []
for i in range(1, 7501):
 records.append([str(store_data.values[i, j]) for j in range(0, 20)])


# In[6]:


records


# In[7]:


#priori method
association_rules = apriori(records, min_support=0.0045, min_confidence=0.2, 
 min_lift=3, min_length=2)


# In[8]:


association_results = list(association_rules)


# In[9]:


association_results


# In[ ]:




