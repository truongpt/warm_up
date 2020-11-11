// problem: https://leetcode.com/problems/kth-largest-element-in-an-array/
/*
// - sort -> O(n*log(n)).
- priority queue
+ create priority queue with size K. that is max queue.
+ scan all  n element. check with top -> if smaller than top -> remove top -> push the value to queue.
+ return top queue.
-> O(n*log(n)).
- quick select.
+ the stategy base on idea of quick sort.
+ select pivo -> find correct position of pivot -> check left size.
+ if (left size == k-1) return.
+ if (left size > k-1) continue with left.
+ if (left size < k-1) continue with writh -> k = k - left size.

      

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthArray(vector<int>& nums, int k) {
        if (k > nums.size()) return -1;
        return quick_sellect(nums, 0, nums.size()-1, nums.size()-k);
    }

    int quick_sellect(vector<int>& nums, int b, int e, int k) {
        int l = b, r = e;
        int pivot = nums[b];
        while (true) {
            while(l < (nums.size()-1) && nums[l] <= pivot) {
                l++;
            }

            while(r > 0 && nums[r] > pivot) {
                r--;
            }

            if (l < r) {
                swap(nums[l], nums[r]);
            } else {
                break;
            }
        }
        swap(nums[b], nums[r]);

        if (k == r) {
            return pivot;
        } else if (k < r) {
            return quick_sellect(nums, b, r-1, k);
        }
        return quick_sellect(nums, r+1, e, k);
    }
};

int main(void)
{
    {
        Solution sol;
        vector<int> nums = {3,2,1,5,6,4};
        cout << sol.findKthArray(nums,1) << endl;
    }
    {
        Solution sol;
        vector<int> nums = {3,2,1,5,6,4};
        cout << sol.findKthArray(nums,2) << endl;
    }
    {
        Solution sol;
        vector<int> nums = {3,2,1,5,6,4};
        cout << sol.findKthArray(nums,3) << endl;
    }
    {
        Solution sol;
        vector<int> nums = {3,2,1,5,6,4};
        cout << sol.findKthArray(nums,4) << endl;
    }
    {
        Solution sol;
        vector<int> nums = {3,2,1,5,6,4};
        cout << sol.findKthArray(nums,5) << endl;
    }
    {
        Solution sol;
        vector<int> nums = {3,2,1,5,6,4};
        cout << sol.findKthArray(nums,6) << endl;
    }
}
