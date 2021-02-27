'''
'''


def divide(dividend: int, divisor: int) -> int:
    # Constants.
    MAX_INT = 2147483647        # 2**31 - 1
    MIN_INT = -2147483648       # -2**31
    HALF_MIN_INT = -1073741824  # MIN_INT // 2
    
    if (dividend == MIN_INT and divisor == -1):
        return MAX_INT
    plus = True
    if (dividend > 0 and divisor > 0) or (dividend < 0 and divisor < 0):
        plus = True
    else:
        plus = False
        
    if dividend > 0:
        dividend = -dividend
    if divisor > 0:
        divisor = -divisor
    
    res = 0
    while dividend <= divisor:
        single = 1
        value = divisor
        
        while value >= HALF_MIN_INT and value + value >= dividend:
            single += single
            value += value
        
        res += single
        dividend -= value
    
    if plus:
        return res
    else:
        return -res

if __name__ == "__main__":
    print(divide(10,3))
