/*
- Problem: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/solution/
- Solution:
  - modulo feature.
  - (a+b)%60 = 0 -> (a%60 + b%60) = 60 or 0
*/
#include <iostream>
#include <vector>
using namespace std;

int getPair(vector<int>& time)
{
    vector<int> remain(60,0);
    int cnt = 0;    

    for (auto t : time) {
        if (t % 60 == 0) {
            cnt += remain[0];
        } else {
            cnt += remain[60 - t % 60];
        }
        remain[t % 60]++;
    }
    return cnt;    
}

int main(void)
{
    {
        vector<int> arr = {30,20,150,100,40};
        cout << getPair(arr) << endl;
    }
    {
        vector<int> arr = {60,60,60};
        cout << getPair(arr) << endl;
    }
}
