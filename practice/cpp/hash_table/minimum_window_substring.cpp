/*
- Problem: https://leetcode.com/problems/minimum-window-substring
*/
#include <iostream>
#include <unordered_map>
#include <string>
#include <climits>

typedef std::unordered_map<char, int> uci;

bool checkSub(uci& m_s, uci& m_t) {
  for (auto [c, num] : m_t) {
    if (m_s[c] < num) {
      return false;
    }
  }        
  return true;
}

std::string minWindow(std::string s, std::string t) {
  if (t.length() > s.length()) {
    return "";
  }
  uci m_t{}, m_s{};
  for (auto c : t) {
    m_t[c]++;
  }
        
  std::string res {};
  int count = INT_MAX;
  int pivot = 0;
  bool found = false;
  int l = 0, r = 0;
  while (r < s.length()) {
    m_s[s[r]]++;
    while (checkSub(m_s, m_t)) {
      if (r - l + 1 < count) {
        count = r - l + 1;
        pivot = l; 
      }
      m_s[s[l]]--;
      l++;
    }
    r++;
  }
        
        
  return count == INT_MAX ? "" : s.substr(pivot, count);;
}

int main(void) {
  std::cout << minWindow("ADOBECODEBANC", "ABC") << std::endl;
}
