"""
- Problem: https://leetcode.com/problems/complex-number-multiplication
"""
def complexNumberMultiply(num1, num2):
    idx1 = num1.index("+")
    idx2 = num2.index("+")
    x1, y1 = int(num1[:idx1]), int(num1[idx1+1:-1])
    x2, y2 = int(num2[:idx2]), int(num2[idx2+1:-1])
    
    return "{}+{}i".format(x1*x2 - y1*y2, x1*y2 + x2*y1)


if __name__ == "__main__":
    print(complexNumberMultiply("1+1i","2+2i"))
