"""
test stack module
"""
from stack import Stack

myStack = Stack()
print(myStack.is_empty())
myStack.push("A")
myStack.push("B")
print(myStack.is_empty())
print(myStack.get_stack())
myStack.push("C")
print(myStack.get_stack())
myStack.pop()
print(myStack.get_stack())
print("peek: ", myStack.peek())
