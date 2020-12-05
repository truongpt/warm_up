/*
- Problem: https://leetcode.com/explore/featured/card/december-leetcoding-challenge/569/week-1-december-1st-december-7th/3555/
- Solution:
  - Greedy
  - Check all of empty position, if it is OK -> fill flower
  - Time & Space complexity
    - TC : O(n)
    - SC: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

bool canPlaceFlowers(vector<int>& arr, int n)
{
    if (n == 0) {
        return true;
    }
    for (int i = 0; i < arr.size(); i++) {
        if (!arr[i] &&
            (i == 0 || arr[i-1] == 0) &&
            (i == arr.size()-1 || arr[i+1] == 0)) {
            arr[i] = 1;
            n--;
            if (n == 0) return true;
        }
    }
    return n == 0;
}

int main(void)
{
    vector<int> arr = {1,0,0,0,1};
    cout << canPlaceFlowers(arr, 2) << endl;
}
