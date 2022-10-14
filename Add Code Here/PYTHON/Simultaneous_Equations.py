import numpy as np

class Simultaneous_Equations:
  
  def __init__(ref, s,s1):
    ref.s1 = s
    ref.s2 = s1
  
  def det(ref):
    ref.d = np.linalg.det(ref.s1)
    return ref.d
  
  def inverse_of_matrix(ref):
    ref.s3 = np.linalg.inv(ref.s1)
    return ref.s3

  def Equations(ref):
      Simultaneous_Equations.inverse_of_matrix(ref)
      a = list(ref.s3)
      b = list(ref.s2)
      ref.c = [[sum(i*j for i,j in zip(X_row,Y_col)) for Y_col in zip(*b)] for X_row in a]
      return ref.c


obj1 = Simultaneous_Equations([[1,2,3],[3,2,1],[2,3,1]],[[1],[2],[1]])
obj2 = Simultaneous_Equations([[1,2],[2,1]],[[0],[2]])
print(obj1.Equations())
print(obj2.Equations())
