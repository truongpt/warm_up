/*
- Problem: https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

```
s = "abaaacccc", k = 2
       ^
```

- Solution -  divide conquer
  - Calculate frequency of all character.
  - Divice at the point, which frequency is smaller than K.
  - Recursive ...
  - Time & space complexity.
    - TC : O(n^2)
    - SC: O(n)

*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int longestSection(string s, int k, int start, int end)
{
    if (end - start + 1 < k) {
        return 0;
    }

    unordered_map<char,int> freq = {};
    for (int i = start; i <= end; i++) {
        freq[s[i]]++;
    }

    bool is_divide = false;
    for (int i = start; i <= end; i++) {
        if ( freq[s[i]] < k) {
            int mid = i+1;
            while (mid <= end && freq[s[mid]] < k) {
                mid++;
            }
            return max(longestSection(s, k, mid, end), longestSection(s, k, start, i-1));
        }
    }

    return end-start+1;
}

int longestSubString(string s, int k)
{
    return longestSection(s, k, 0, s.length()-1);
}

int main(void)
{
    cout << longestSubString("ababbc", 2) << endl;
    cout << longestSubString("aaabb", 3) << endl;    
}
