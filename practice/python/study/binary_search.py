def linear_search(data, target):
    for it in data:
        if it == target:
            return True
    return False

def binary_search(data, target):
    l = 0
    r = len(data) -1
    while l <= r:
        m = l + (r-l)//2
        if data[m] == target:
            return True
        elif data[m] < target:
            l = m+1
        else:
            r = m-1
    return False


        
def binary_search_recursive(data, target):
    return help(data, target, 0, len(data)-1)

def help(data, target, l,r):
    if l > r:
        return False
    m = l + (r-l)//2
    if data[m] == target:
        return True
    elif data[m] < target:
        return help(data, target, m+1, r)
    else:
        return help(data, target, l, m-1)

data = [2,3,4,4,5,6,7,9]
print(linear_search(data, 3))
print(linear_search(data, 8))

print(binary_search(data, 3))
print(binary_search(data, 8))
print(binary_search_recursive(data, 3))
print(binary_search_recursive(data, 8))

