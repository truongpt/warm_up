from abc import ABC, abstractmethod
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

# Operator Overloading
class Complex:
    def __init__(self, real, img):
        self.real = real
        self.img = img
    def __add__(self, other):
        temp = Complex(self.real + other.real, self.img + other.img)
        return temp
    def __sub__(self, other):
        temp = Complex(self.real - other.real, self.img - other.img)
        return temp
    def printDetail(self):
        print("real : ", self.real)
        print("img : ", self.img)

# astract class
class Shape(ABC):
    @abstractmethod
    def area(self):
        pass

class Square(Shape):
    def __init__(self, width, length):
        self.width = width
        self.length = length
    def area(self):
        return self.width * self.length
