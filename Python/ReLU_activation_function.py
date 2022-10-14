import numpy as np


def ReLU(x):
  data = [max(0,value) for value in x]
  return np.array(data, dtype=float)
