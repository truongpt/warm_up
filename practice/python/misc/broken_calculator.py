
def brokenCalc(X: int, Y: int) -> int:
    res = 0
    while X < Y:
        if Y % 2:
            Y += 1
        else:
            Y //= 2
        res += 1
    return res + X - Y

print(brokenCalc(2,10))
