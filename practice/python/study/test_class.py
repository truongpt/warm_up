from class_base import *

# test machine learning class
ml = MachineLearning()
ml1 = MachineLearning("con gau", "con bo", 2)

ml.version.append("1");
ml1.version.append("7");

print(ml.suppervisor)
print(ml.unsuppervisor)
print(ml.type)
print(ml.version)


print(ml1.suppervisor)
print(ml1.unsuppervisor)
print(ml1.type)
print(ml1.version)

# test car class
obj = Car()
obj.display()

mec = Car();
mec.setTopSpeed(100)
mec.openTrunk()

toyota = Hybrid()
toyota.setTopSpeed(200)
toyota.openTrunk()
toyota.turnOnHybrid()

acc = SavingsAccount("Mark",500,5)
acc.printDetail()

# test operator overloading
com1 = Complex(1,2)
com2 = Complex(3,4)
com = com1 + com2
com.printDetail()

# test abstract class
shp = Square(10,15)
print(shp.area())
