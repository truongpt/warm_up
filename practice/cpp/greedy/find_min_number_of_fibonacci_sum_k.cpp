// problem: https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/
#include <iostream>
#include <vector>

using namespace std;

int minFibonacci(int k)
{
    vector<int> f;
    f.push_back(1);
    f.push_back(1);
    while(f.back() < k) {
        int n = f.size()-1;
        f.push_back(f[n]+f[n-1]);
    }

    int num = 0;
    while (k != 0 && !f.empty()) {
        if (f.back() > k) {
            f.pop_back();
        } else {
            k -= f.back();
            num++;
        }
    }
    return num;
}

int main(void)
{
    cout << minFibonacci(1) << endl;
    cout << minFibonacci(19) << endl;
    return 0;
}
