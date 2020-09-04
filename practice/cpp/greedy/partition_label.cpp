// problem: problem: https://leetcode.com/problems/partition-labels/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> partitionLabels(string S) {
    vector<int> res;
    vector<int> m(26,0);
    for (int i = 0; i < S.length(); i++) {
      int c = S[i] - 'a';
      m[c] = i;
    }

    int pos = 0, pre = 0;
    for (int i = 0; i < S.length(); i++) {
      int c = S[i] - 'a';
      pos = max(pos, m[c]);
      if (pos == i) {
        res.push_back(i+1 - pre);
        pre = pos+1;
      }
    }
    return res;
  }
};

int main(void)
{
    Solution sol;
    {
        vector<int> res = sol.partitionLabels("ababcbacadefegdehijhklij");
        for (auto it : res) {
            cout << it << ",";
        }
        cout << endl;
    }
    {
        vector<int> res = sol.partitionLabels("abcdefkg");
        for (auto it : res) {
            cout << it << ",";
        }
        cout << endl;
    }
}
