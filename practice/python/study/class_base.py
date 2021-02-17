# basic
class MachineLearning:
    version = [] # class variable
    def __init__(self, s = "con cho con", u = "con meo", t = 1):
        self.suppervisor = s   # instance variable
        self.unsuppervisor = u
        self.type = 2
    
# Inheritane
class Vehicle:
    def __init__(self):
        print("init Vehicle")
    def display(self):
        print("I am Vehicle")
    def setTopSpeed(self, speed):
        self.top_speed = speed
        print("Top speed: ", self.top_speed)

class Car(Vehicle):
    def display(self):
        super().display()
        print("I am from Car")
    def openTrunk(self):
        print("Open Trunk")

class Hybrid(Car):
    def turnOnHybrid(self):
        print("Turn On Hybrid")

class Account:
    def __init__(self, title, balance):
        self.title = title
        self.balance = balance
class SavingsAccount(Account):
    def __init__(self, title, balance, interest_rate):
        super().__init__(title, balance)
        self.interest_rate = interest_rate
    def printDetail(self):
        print("Detail infor: ", self.title, self.balance, self.interest_rate)

# Polymophism

