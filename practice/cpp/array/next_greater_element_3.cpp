/*
- Problem: https://leetcode.com/problems/next-greater-element-iii/
- Solution:
  - 1234657
       ^ ^
  - find last pair increased element, with smallest second -> (4,5)
  - swap(4,5)
  - sort increase from element 6.
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int nextGreaterElement(int n) {
    vector<int> num = {};
    while (n > 0) {
        num.push_back(n%10);
        n = n/10;
    }
    reverse(num.begin(), num.end());

    int idx1 = -1;
    int first = -1, second = -1;
    for (int i = num.size()-1; i >= 0; i--) {
        if (num[i] < first) {
            idx1 = i;
            second = first; 
            first = num[i];
            break;
        }
        first = max(first, num[i]);
    }
        
    if (idx1 == -1) return -1;
        
    int idx2 = -1;
    for (int i = num.size()-1; i > idx1; i--) {
        if (num[i] > first && num[i] <= second) {
            idx2 = i;
            second = num[i];
        }
    }
        
    swap(num[idx1], num[idx2]);        
    sort(num.begin()+idx1+1, num.end());
        
    long res = 0;
    for (auto it : num) {
        res = res*10 + it;
    }
        
    if (res > INT_MAX) return -1;
    return (int)res;
}

int main(void)
{
    cout << nextGreaterElement(123) << endl;
}
