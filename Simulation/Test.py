from Thrusters_Vector import Vectors
X= 89
Y= 50
Moment=0

ThrustersForces =[1500] * 4

testV=Vectors
testV.__init__(testV)
forces=Vectors.process(X,Y,Moment,Vectors)

print(f" For Forces given : X :{X} , Y: {Y} , Moment: {Moment}") 
print("-------------------Final forces -------------------") 
print(f"Upper left: {forces[2]} Upper right: {forces[0]}")      
print(f"Back left:  {forces[3]}  Back right: {forces[1]}")    
