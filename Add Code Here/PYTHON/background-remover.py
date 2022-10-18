#!/usr/bin/env python
# coding: utf-8

# In[145]:


from rembg import remove
from PIL import Image
input_path = 'assets/travelkoba-python.jpg'
output_path = 'assets/travelkoba-python-rembg.png'
input = Image.open(input_path)
output = remove(input)
output.save(output_path)


# In[146]:


from IPython.display import Image
from IPython.display import display
x = Image(filename='assets/travelkoba-python.jpg', width=200) 
y = Image(filename='assets/travelkoba-python-rembg.png', width=200) 
display(x, y)

