/*
- Problem: https://leetcode.com/problems/roman-to-integer
- Solution:
  - Directly apply rule to convert from roman to integer.
  - Pre character value is decided after know current character in roman string.
  - Time and space complexity.
    - TC: O(n)
    - SC: O(n)
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int romanToInt(string s)
{
    if (s.empty()) {
        return 0;
    }

    int res = 0;
    unordered_map<char, int> m = {{'I',1}, {'V',5}, {'X',10},{'L',50},{'C',100}, {'D',500}, {'M',1000}};
    char pre = 'x';
    for (int i = 0; i < s.length(); i++) {
        if (pre == 'x') {
            pre = s[i];
        } else if (m[s[i]] <= m[pre]) {
            res += m[pre];
            pre = s[i];
        } else {
            res += (m[s[i]] - m[pre]);
            pre = 'x';
        }
    }

    if (pre != 'x') {
        res += m[pre];
    }

    return res;
}

int main(void)
{
    cout << romanToInt("MCMXCIV") << endl;
}
