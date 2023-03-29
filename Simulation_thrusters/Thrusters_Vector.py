import numpy as np
import math as m
from Controller import myController
from numpy.linalg import eigh, norm,inv
class Vectors:
    A=np.array([[-0.5,0.5,0.5,-0.5],# -45  45  225 135
    [0.866 ,0.866, 0.866,0.866],# -45  45  225 135
    [-0.21012 , -0.21012,  0.21012 , 0.21012]]) # -255  -105  255 105
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
        # print(self.V_transpose.T@self.S_Astred@self.U.T)
        # print(Vectors.V_transpose.T)
        # print(Vectors.S_Astred)
        # print(Vectors.U.T)
        # print(td)
        if(x!=0 and (y==0 and m==0)):
             self.ma=64
        elif(y!=0 and(x==0 and m==0 )):
             self.ma=37
        elif(m!=0 and (x==0 and y==0)):
             self.ma=152
        elif(x!=0 and y!=0 and m==0):
             self.ma=50
        elif(x!=0 and m!=0 and y==0):
             self.ma=108
        elif(y!=0 and m!=0 and x==0):
             self.ma=95
        elif(x!=0 and y!=0 and m!=0):
             self.ma=84
        else:
             self.ma=0
        # self.ma=max(f)
        print(self.ma)
        for i in range (4):
                if self.ma>0:
                    f[i]=np.round(np.interp(f[i],[-self.ma,self.ma],[1100,1900]),decimals=2)
        return f