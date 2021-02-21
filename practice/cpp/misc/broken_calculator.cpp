/*
- Problem: https://leetcode.com/problems/broken-calculator
- Solution: https://leetcode.com/problems/broken-calculator/discuss/234484/JavaC%2B%2BPython-Change-Y-to-X-in-1-Line
  - Time and space complexity.
    - TC: O(log Y)
    - SC: O(1)
*/

#include <iostream>
using namespace std;

int brokenCalc(int X, int Y) {        
    int step = 0;
    while (X < Y) {
        step += Y % 2;
        Y = (Y+1)/2;
        step++;
    }
        
    return step + X - Y;
        
}

int main(void)
{
    cout << brokenCalc(2,10) << endl;
}
