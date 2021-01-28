/*
- Problem: https://leetcode.com/problems/smallest-string-with-a-given-numeric-value
- Solution:
  - Greedy, scan output string from RIGHT to LEFT and try get the biggest number as much as possible.
  - Time and space complexity.
    - TC: O(n)
    - SC: O(1)
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string getSmallestString(int n, int k)
{
    string res = string(n,'a');
    k -= n;
    while (k > 0) {
        res[--n] += min(25,k);
        k -= min(25,k);
    }
    return res;
}


int main(void)
{
    cout << getSmallestString(24, 552) << endl;
}
