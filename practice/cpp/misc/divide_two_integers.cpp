/*
- Problem: https://leetcode.com/problems/divide-two-integers
- Solution:
  - Intuition: dividend = divisor + divisor + divisor + divisor ...
  - Using while and reduce dividend -> performance O(n)
  - Optimize performance by double divisor -> O(log n)
  - Care about sign of dividend and divisor with consider MIN, MAX of Integer.
  - Time and space complexity.
    - TC: O(log n)
    - SC: O(1) 
*/

#include <iostream>
#include <climits>

using namespace std;

#define HAFT_MIN (INT_MIN/2)

int divide(int dividend, int divisor) {
    bool plus = true;
    if ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0)) {
        plus = true;
    } else {
        plus = false;
    }
        
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
        
    if (divisor == 1) {
        return dividend;
    }

    dividend = dividend > 0 ? -dividend : dividend;
    divisor = divisor > 0 ? -divisor : divisor;
        
    int res = 0;
        
    while (dividend <= divisor) {
        int single = 1;
        int value = divisor;
            
        while (value > HAFT_MIN && value + value > dividend) {
            value += value;
            single += single;
        }
        dividend -= value;
        res += single;
    }
        
    return (plus ? res : -res);
    
}

int main(void)
{
    cout << divide(10, 3) << endl;
}
