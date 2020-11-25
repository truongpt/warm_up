/*
- Problem: https://leetcode.com/problems/smallest-integer-divisible-by-k/

- Solution:
  - K = 3
  - 111
  - 111 = 11 * 10 + 1 We only need to store remainders modulo K.
*/

#include <iostream>
#include <unordered_set>
using namespace std;

int smallestIntDivByK(int K)
{
    if (!(K % 2) || !(K % 5)) {
        return -1;
    }
    int cnt = 1;
    int num = 1;
    int remain = num % K;
    if (0 == remain) return num;

    unordered_set<int> s;
    while (s.find(remain) == s.end()) {
        s.insert(remain);
        cnt++;

        num = remain*10 + 1;
        remain = num % K;

        if (remain == 0) return cnt;
    }

    return -1;

}

int main(void)
{
    cout << smallestIntDivByK(1) << endl;
    cout << smallestIntDivByK(3) << endl;
    cout << smallestIntDivByK(7) << endl;

}
