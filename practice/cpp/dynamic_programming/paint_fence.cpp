// problem: https://leetcode.com/problems/paint-fence/
#include <iostream>
#include <vector>

using namespace std;

int numWays(int n, int k)
{
    vector<int> num(n+1,0);
    num[1] = k;
    num[2] = k*k;
    for (int i = 3; i <= n; i++) {
        num[i] = (num[i-1] + num[i-2])*(k-1);
    }
    return num[n];
}

int main(void)
{
    cout << numWays(3,2) << endl;
}
