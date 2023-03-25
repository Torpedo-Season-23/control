from Controller import myController
from Thrusters_Vector import Vectors

ThrustersForces =[1500] * 4

testV=Vectors
testV.__init__(testV)
forces=Vectors.process(myController.X,myController.Y,myController.Moment,Vectors)
for i in range (4):
    if forces[i]<1500:
        ThrustersForces[i]=1500-(1500-forces[i])
    else:
        ThrustersForces[i]=1500+(forces[i]-1500)
print(f" For Forces given : X :{myController.X} , Y: {myController.Y} , Moment: {myController.Moment}") 
print("-------------------Final forces -------------------") 
print(f"Upper right: {forces[1]}")      
print(f"Back right: {forces[0]}")    
print(f"Upper left: {forces[3]}")    
print(f"Back left: {forces[2]}")   