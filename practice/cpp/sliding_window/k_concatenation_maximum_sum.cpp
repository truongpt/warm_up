// problem: https://leetcode.com/problems/k-concatenation-maximum-sum/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define L 1000000007

class Solution {
public:
    int kConcatenationMaxSum(vector<int> arr, int k) {
        long sum = 0, f_max = 0, s_max = 0;
        for (auto a : arr) {
            sum = (sum+a)%L;
        }

        long cur = 0;
        for (auto a : arr) {
            cur += a;
            f_max = max(f_max, cur)%L;
        }

        cur = 0;
        for (int i = arr.size()-1; i >= 0; i--) {
            cur += arr[i];
            s_max = max(s_max, cur)%L;
        }

        long res = 0;
        if (k < 2) {
            res = max(s_max, f_max)%L;
        } else if (sum <= 0) {
            res = (s_max+f_max)%L;
        } else if (sum > 0) {
            res = (sum*(k-2)%L + s_max + f_max)%L;
        }

        long max_one = 0;
        long cur_one = 0;
        int s = 0, e = 0;

        for (int e = 0; e < arr.size(); e++) {
            cur_one += arr[e];
            while (cur_one < 0 && s <= e) {
                cur_one -= arr[s];
                s++;
            }
            max_one = max(max_one, cur_one);
        }        

        return (int)max(res, max_one);
    }
};

int main(void)
{
    Solution sol;
    cout << sol.kConcatenationMaxSum({-5,4,-4,-3,5,-3},3) << endl;
    return 0;
}
