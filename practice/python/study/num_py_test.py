import numpy as np

# 1.array
arr = np.array([1,2,-1], dtype = np.float32)
print(repr(arr))

arr_1 = np.array([[1, 2, -1], [2, "3", 4]], dtype = np.float32)
print(repr(arr_1))

# 2.copy
arr_2 = np.array([0,1])
arr_3 = np.array([8,9])

print(arr_2)
c = arr_2
c[0] = 10
print(arr_2)

print(arr_3)
d = arr_3.copy()
d[0] = 10
print(arr_3)

# 3.casting
a = np.array([1,2,3])
print(a.dtype)
a = a.astype(np.float32)
print(a.dtype)

# 4.nan
a4 = np.array([np.nan, 1,2,3]) 
print(repr(a4))
print(a4)

# 5. inf
a5 = np.array([np.inf, 4])
print(a5)
print(repr(a5))

# 6. range
a6 = np.arange(5)
print(repr(a6))
print(a6)

a61 = np.arange(5.1)
print(repr(a61))
print(a61)

