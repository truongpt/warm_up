/*
- Problem: https://leetcode.com/problems/custom-sort-string
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>

std::string customSortString(std::string order, std::string str) {
  std::unordered_map<char, int> ordered_index{};
  for (int i = 0; i < order.length(); i++) {
    ordered_index[order[i]] = i;
  }

  std::sort(str.begin(), str.end(), [&] (auto arg1, auto arg2){
                                      return ordered_index[arg1] < ordered_index[arg2];
                                    });
  return str;
}

int main() {
  std::string orderStr = "cba";
  std::string inputStr = "abcd";
  auto outputStr = customSortString(orderStr, inputStr);

  std::cout << "output string: " << outputStr << std::endl;

  return 0;
}
