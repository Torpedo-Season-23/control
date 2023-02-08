import numpy as np
import math as m
from numpy.linalg import eigh, norm,inv


A=np.array([[m.cos(-45) , m.cos(45),  m.cos(-45), m.cos(45)],
[m.sin(-45) , m.sin(45),  m.sin(-45), m.sin(45)],
[m.sin(-45-30) , m.sin(45-30),  m.sin(-45-30), m.sin(45-30)]]) ##Values of third row to be adjust by current design

U, S_Array, V_transpose = np.linalg.svd(A)
U=np.round(U,decimals=5)

S_matrix=np.diag(S_Array)
S_Astred=inv(S_matrix.T)
zeros =np.array(np.zeros(3))
S_Astred=np.vstack((S_Astred,zeros))


td=np.array([300 ,-50, 10])# Values to be adjusted by controller

f= V_transpose.T@S_Astred@U.T@td

print(f)
