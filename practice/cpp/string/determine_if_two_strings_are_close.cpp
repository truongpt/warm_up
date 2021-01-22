/*
- Problem: https://leetcode.com/problems/determine-if-two-strings-are-close
- Solution:
  - Greedy?
  - String close to each other if.
    - character is same.
    - frequency is same.
  - Time and space complexity
    - TC: O(n), having sort but size of vector  <= 27
    - SC: O(n)
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool closeStrings(string word1, string word2)
{
    unordered_map<char, int> s1, s2;

    if (word1.length() != word2.length()) {
        return false;
    }
        
    for (auto c :  word1) {
        s1[c]++;
    }
        
    for (auto c : word2) {
        s2[c]++;
        if (s1.find(c) == s1.end()) {
            return false;
        }
    }
        
    vector<int> v1,v2;
        
    for (auto it : s1) {
        v1.push_back(it.second);
    }
        
    for (auto it : s2) {
        v2.push_back(it.second);
    }
        
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
        
    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }
        
    return true;
        
}

int main(void)
{
    cout << closeStrings("abc", "acb") << endl;
}
