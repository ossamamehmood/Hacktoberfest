import pandas as pd
import matplotlib.pyplot as plt
import numpy as np


birddata = pd.read_csv("bird_tracking.csv")
bird_names = pd.unique(birddata.bird_name)

# storing the indices of the bird Eric
ix = birddata.bird_name == "Eric"
x,y = birddata.longitude[ix], birddata.latitude[ix]
plt.figure(figsize = (7,7))
plt.plot(x,y,"b.")

''' To look at all the birds trajectories,
	we plot each bird in the same plot '''
plt.figure(figsize = (7,7))
for bird_name in bird_names:

	# storing the indices of the bird Eric
	ix = birddata.bird_name == bird_name
	x,y = birddata.longitude[ix], birddata.latitude[ix]
	plt.plot(x,y,".", label=bird_name)
plt.xlabel("Longitude")
plt.ylabel("Latitude")
plt.legend(loc="lower right")
plt.show()
