#!/usr/bin/env python
# coding: utf-8

# In[37]:


import requests
from bs4 import BeautifulSoup
import pandas as pd
import matplotlib.pyplot as plt


# In[38]:


url = "https://www.flipkart.com/mobiles/mi~brand/pr?sid=tyy,4io&otracker=nmenu_sub_Electronics_0_Mi"


# In[39]:


req=requests.get(url)


# In[40]:


content=BeautifulSoup(req.content,'html.parser')


# In[41]:


print(content)


# In[42]:


name =  content.find_all('div', {"class":"_4rR01T"})
price = content.find_all('div',{"class":"_30jeq3 _1_WHN1"})
ratings = content.find_all('div',{"class": "_3LWZlK"})
Specs = content.find_all('div', {"class": "fMghEO" })


# In[43]:


print(name[1].text)
print(price[2].text)
print(ratings[3].text)
print(Specs[11].text)


# In[44]:


nm=[]
pr=[]
rt=[]
sp=[]


# In[45]:


for i in name:
    nm.append(i.text)
for i in price:
    pr.append(i.text)
for i in range(len(nm)):
    rt.append(ratings[i].text)
for i in range(len(nm)):
    sp.append(Specs[i].text) 


# In[46]:


data = {"Name":nm, "Price":pr, "Ratings":rt, "Specificatins":sp}
df=pd.DataFrame(data)


# In[47]:


print(df)


# In[48]:


df.to_csv("FlipkartData.csv")


# In[ ]:




