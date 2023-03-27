from Thrusters_Vector import Vectors
X= 0
Y= 0
Moment=128

ThrustersForces =[1500] * 4

testV=Vectors
testV.__init__(testV)
forces=Vectors.process(X,Y,Moment,Vectors)

print(f" For Forces given : X :{X} , Y: {Y} , Moment: {Moment}") 
print("-------------------Final forces -------------------") 
print(f"Upper left: {forces[2]} Upper right: {forces[0]}")      
print(f"Back left:  {forces[3]}  Back right: {forces[1]}")    
