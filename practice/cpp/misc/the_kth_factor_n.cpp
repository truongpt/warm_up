/*
- Problem: https://leetcode.com/problems/the-kth-factor-of-n/
- Solution 1.
  - Brute force -> check all factor from 1 to n
*/


#include <iostream>
#include <queue>
using namespace std;

int kthFactor1(int n, int k)
{
    for (int i = 1; i <= n; i++) {
        if (!(n%i)) {
            k--;
            if (k == 0) return i; 
        }        
    }
    return -1;
}

int kthFactor2(int n, int k)
{
    priority_queue<int> q;
    for (int i = 1; i*i <= n; i++) {
        if (!(n%i)) {
            q.push(i);
            if (i != n/i) q.push(n/i);
            while (q.size() > k) {
                q.pop();
            }
        }        
    }
    return q.size() == k ? q.top() : -1;    
}

int main(void)
{
    cout << kthFactor1(12,3) << endl;
    cout << kthFactor2(12,3) << endl;
    cout << kthFactor2(4,4) << endl;
}
