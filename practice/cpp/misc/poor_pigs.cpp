/*
- Problem: https://leetcode.com/problems/poor-pigs/
- Reference:
  - https://leetcode.com/problems/poor-pigs/discuss/94266/Another-explanation-and-solution

*/

#include <iostream>
using namespace std;

int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    int test_num = minutesToTest/minutesToDie;
    int pig_cnt = 0;
    int cnt = 1;
    while (cnt < buckets) {
        cnt *= (test_num+1);
        pig_cnt++;
    }
    return pig_cnt;
}

int main(void)
{
    cout << poorPigs(1000, 15, 60) << endl;
}
