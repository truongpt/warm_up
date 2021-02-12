class MachineLearning:
    version = [] # class variable
    def __init__(self, s = "con cho con", u = "con meo", t = 1):
        self.suppervisor = s   # instance variable
        self.unsuppervisor = u
        self.type = 2
    
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

