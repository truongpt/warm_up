/*
- Problem: https://leetcode.com/problems/count-sorted-vowel-strings/
- Solution:
  - Dynamic programming with top down (memoization)
    res = sum of result of (n-1,5-i) i = 0~4
  - Time and space complexity
    - TC: O(n*5) => O(n)
    - SC: O(n)
*/

#include<iostream>
#include <vector>
using namespace std;

int count(vector<vector<int>>& d, int n, int v) {
    if (n == 1) {
        return v;
    }
    if (v == 1) {
        return 1;
    }
        
    if (d[n][v]) {
        return d[n][v];
    }
        
    int sum = 0;
    for (int i = 0; i < v; i++) {
        sum += count(d, n-1,v-i);
    }

    d[n][v] = sum;
    return sum;
}
    
int countVowelStrings(int n) {
    vector<vector<int>> d(n+1, vector<int>(6,0));
        
    return count(d, n, 5);
}

int main(void)
{
    cout << countVowelStrings(33) << endl;
}
