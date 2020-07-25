// problem: https://leetcode.com/problems/fruit-into-baskets/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int TotalFruit(vector<int>& tree)
{
    int begin = 0, end = 0;
    unordered_map<int,int> cnt = {};
    
    for (; end < tree.size(); end++) {
        cnt[tree[end]]++;
        if (cnt.size() > 2) {
            if (--cnt[tree[begin]] == 0) cnt.erase(tree[begin]);
            begin++;
        }
        
    }

    return end-begin;
}
int main(void)
{
    vector<int> tree = {3,3,3,1,2,1,1,2,3,3,4};
    cout << TotalFruit(tree);
}
