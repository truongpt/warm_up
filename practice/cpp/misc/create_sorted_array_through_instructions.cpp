/*
- Problem: https://leetcode.com/problems/create-sorted-array-through-instructions/
- Solution 1:
  - Brute force
  - Time and space complexity
    - TC: O(n^2)
    - SC: O(n)

- Solution 1:
  - Using segment tree to manage occurrence number of original array
    - https://en.wikipedia.org/wiki/Segment_tree
    - https://leetcode.com/articles/a-recursive-approach-to-segment-trees-range-sum-queries-lazy-propagation/
  - Time and space complexity
    - TC: O(n*log m) // m is maximum value of original array
    - SC: O(m)
*/

#include <iostream>
#include <vector>
using namespace std;

int createSortedArray1(vector<int>& instructions)
{
    int cost = 0;
    vector<int> nums;
    for (auto cur : instructions) {
        int l = 0, g = 0;
        for (auto it : nums) {
            if (it > cur) {
                g++;
            } else if (it < cur) {
                l++;
            }
        }
        cost += min(l,g);
        nums.push_back(cur);
    }
        
    return cost;
}

void update (int index, int value, vector<int>& tree, int m)
{
    index += m;
    tree[index] += value;
        
    for (index >>= 1; index > 0; index >>= 1) {
        tree[index] = tree[index << 1] + tree[(index << 1) + 1]; 
    }
}
    
int query(int left, int right, vector<int>& tree, int m)
{
    int result = 0;
    for (left += m, right += m;  left < right; left >>=1, right >>= 1) {
        if ((left &1) == 1) result += tree[left++];
        if ((right &1) == 1) result += tree[--right];
    }
    return result;
}

int createSortedArray(vector<int>& instructions)
{
    int m = 1e5+1;
    vector<int> tree(m*2);
    long cost = 0;
    long MOD = (int)1e9 + 7;
        
    for (int x : instructions) {
        cost += min(query(0,x,tree,m), query(x+1,m,tree,m));
        update(x,1,tree,m);
    }
        
    return (int)(cost % MOD);
}

int main(void)
{
    vector<int> instructions = {1,5,6,2};
    cout << createSortedArray1(instructions) << endl;
}
