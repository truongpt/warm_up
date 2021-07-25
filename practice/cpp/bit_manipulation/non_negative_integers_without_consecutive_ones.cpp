/*
- Problem: https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/
*/
#include <iostream>

int countValidInts(int cur, int n) {
  if (cur > n) {
    return 0;
  }
        
  if (cur & 1) {
    return 1 + countValidInts(cur << 1, n);
  } else {
    return 1 + countValidInts(cur << 1, n) + countValidInts(cur << 1 | 1, n);
  }
}

int findIntegers(int n) {
  return 1 + countValidInts(1,n);
}

int main(void) {

  std::cout << findIntegers(7) << std::endl;
  return 0;
}
