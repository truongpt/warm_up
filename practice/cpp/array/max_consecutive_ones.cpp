/*
- Problem: https://leetcode.com/explore/learn/card/fun-with-arrays/521/introduction/3238/
- Solution.
  - scan all elements
  - if elem == 1 -> cnt++
  - if elem == 0 -> if cnt > max -> store; cnt = 0

*/

#include <iostream>
#include <vector>
using namespace std;

int getMaxConsecutiveOnes(vector<int>& nums)
{
    int cnt = 0, res = 0;
    for (auto it : nums) {
        if (it == 1) {
            cnt++;
        } else {
            res = cnt > res ? cnt : res;
            cnt = 0;
        }
    }
    return cnt > res ? cnt : res;
}

int main(void)
{

}
