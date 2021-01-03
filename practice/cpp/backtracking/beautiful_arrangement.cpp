/*
- Problem: https://leetcode.com/problems/beautiful-arrangement/
- Solution:
  - Straightforward with backtracking.
  - For each position (idx) check all element from 1 -> n is suitabte or not
  - Time & space complexity
    - TC: O(n!) (number of permutation)
    - SC: O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

void calculate(vector<bool>& aval, int order, int& cnt)
{
    if (order > aval.size()) {
        cnt++;
        return;
    }

    for (int i = 1; i <= aval.size(); i++) {
        if (aval[i-1] && (0 == i % order || 0 == order % i)) {
            aval[i-1] = false;
            calculate(aval, order+1, cnt);
            aval[i-1] = true;
        }
    }
}

int countArrangement(int n)
{
    int cnt = 0;
    vector<bool> aval(n, true);
    calculate(aval, 1, cnt);
    return cnt;
}

int main(void)
{
    cout << countArrangement(2) << endl;
    cout << countArrangement(3) << endl;
    cout << countArrangement(10) << endl;

}
