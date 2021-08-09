"""
- Problem: https://leetcode.com/problems/add-strings
"""
def addStrings(num1: str, num2: str):
    num1, num2 = list(num1), list(num2)
    carry, res = 0, []

    while len(num1) > 0 or len(num2) > 0:
        n1 = ord(num1.pop()) - ord('0') if len(num1) > 0 else 0
        n2 = ord(num2.pop()) - ord('0') if len(num2) > 0 else 0        
        temp = (n1 + n2 + carry) % 10
        carry = (n1 + n2 + carry) // 10
        res.append(temp)

    if carry:
        res.append(carry)    

    return ''.join([str(i) for i in res])[::-1]


if __name__ == "__main__":
    print(addStrings("123","999"))
