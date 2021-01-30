/*
- Problem: https://leetcode.com/problems/counting-bits/
- Solution:
  - Dynamic programming
    - Call d[i] is number of 1's in i
    - if i is odd -> d[i] = d[i-1]+1;
    - if i is even -> d[i] = d[i/2]
  - Time and space complexity.
    - TC: O(n)
    - SC: O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int num)
{
    vector<int> d(num+1,0);
    for (int i = 1; i <= num; i++) {
        d[i] = i%2 ? (d[i-1]+1) : d[i/2]; 
    }

    return d;
}

int main(void)
{
    vector<int> res = countBits(5);
    for (auto it : res) {
        cout << it << ",";
    }
    cout << endl;
}
