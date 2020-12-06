/*
- Problem: https://leetcode.com/explore/learn/card/fun-with-arrays/523/conclusion/3228/
- Solution
  - Sort array -> check with original
- Intuition.
  - above is stupid solution -> need find better solution.

*/

#include <iostream>
#include <vector>
#include <algrithm>
using namespace std;

int heighChecker(vector<int>& heights)
{
    vector<int> org = heights;
    sort(heights.begin(), heights.end());

    int n  = 0;
    for (int i = 0; i < heights.size(); i++) {
        if (org[i] != heights[i]) {
            n++;
        }
    }
    return n;
}

int main(void)
{

}
