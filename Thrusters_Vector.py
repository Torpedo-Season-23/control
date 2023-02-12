import numpy as np
import math as m
from Controller import myController
from numpy.linalg import eigh, norm,inv
class Vectors:
    A=np.array([[-0.707 , -0.707, 0.707,0.707],# -45  45  225 135
    [-0.707 , 0.707,  -0.707, 0.707],# -45  45  225 135
    [-0.966 , 0.966,  0.966 , -0.966]]) # -255  -105  255 105
    ##Values of third row to be adjust by current design
    S_Astred =  [[0] * 3] * 3
    V_transpose =  [[0] * 4] * 4
    U =  [[0] * 3] * 3

    def __init__(self):
        self.U, S_Array, self.V_transpose = np.linalg.svd(self.A)
        self.U=np.round(self.U,decimals=5)
        S_matrix=np.diag(S_Array)
        self.S_Astred=inv(S_matrix.T)
        zeros =np.array(np.zeros(3))
        self.S_Astred=np.vstack((self.S_Astred,zeros))
        
    def process(x,y,m,self):
        td=np.array([x ,y, m])# Values to be adjusted by controller
        f= np.round(Vectors.V_transpose.T@Vectors.S_Astred@Vectors.U.T@td)

        print(f)
        print(self.V_transpose.T@self.S_Astred@self.U.T)
        print(Vectors.V_transpose.T)
        print(Vectors.S_Astred)
        print(Vectors.U.T)
        print(td)
        for i in range (4):
            f[i]=np.round(np.interp(f[i],[-45,45],[1100,1900]),decimals=2)
        return f