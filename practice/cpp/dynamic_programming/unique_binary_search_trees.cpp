/*
- Problem: https://leetcode.com/problems/unique-binary-search-trees/
- Solution:
  - Dynamic programming bottom up
    - d[i] = 2*d[i-1] + sum of (d[j]*d[i-j-1]) with all j = 1 ~ i-1
  - Time and space complexity
    - TC: O(n^2)
    - SC: O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

int numTrees(int n) {
    vector<int> d(n+1,0);
    d[1] = 1;
    for (int i = 2; i <= n; i++) {
        d[i] = 2*d[i-1];
            
        int temp = 0;
        for (int j = 1; j < i-1; j++) {
            temp += d[j]*d[i-1-j];
        }
        d[i] += temp;
    }
        
    return d.back();
}

int main()
{
    cout << numTrees(3) << endl;
    cout << numTrees(19) << endl;
}
