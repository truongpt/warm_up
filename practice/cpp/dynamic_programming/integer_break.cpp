/*
- Problem: https://leetcode.com/problems/integer-break
- Solution:
  - Dynamic programming.
    - d[i] is result when breaking i value integer.
    - d[i] = max(d[i],i)
    - d[n] = max(d[i]*d[n-i]) for i = 1 ~ n-1
  - Time and space complexity
    - TC: O(n^2)
    - SC : O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

int integerBreak(int n) {
    vector<int> d(n+1,1);
        
    for (int i = 0; i <= n; i++) {
        d[i] = i;
    }
    d[n] = 1;
        
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            d[i] = max(d[i], d[j]*d[i-j]);
        }
    }
        
    return d[n];
}

int main(void)
{
    cout << integerBreak(58) << endl;
}
