#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum_l = 0;
        int sum_r = 0;
        for (auto it : nums) sum_r += it;
        int pivot = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum_r -= nums[i];
            sum_l += (i > 0 ? nums[i-1] : 0);
            if (sum_l == sum_r) return i;
        }
        return -1;
    }

    int pivotIndex_1(vector<int>& nums) {
        int n = nums.size();
        vector<int> p;
        for (auto it : nums) {
            p.push_back((p.empty ? it : (p.back() + it)));
        }

        for (int i = 0; i < n; i++) {
            int l = (i > 0 ? p[i-1] : 0);
            int r = p[n-1] - p[i];
            if (l == r) return i;
        }
        return -1;
    }
};

int main(void)
{
    string nums_str;
    getline(cin, nums_str);
    stringstream in(nums_str);
    vector<int> nums;
    string elem;
    while (in >> elem) {
        nums.push_back(stoi(elem));
    }
    Solution sol;
    cout << sol.pivotIndex(nums) << endl;
}


