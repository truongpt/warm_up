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
- Solution 2
  - windows slide

*/

#include <iostream>
#include <string>
#include <vector>
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


int longestSubStringSW(string s, int k)
{
    int freq[26] = {0};
    int unique = 0;
    for (auto c : s) {
        if (freq[c - 'a'] == 0) {
            freq[c - 'a'] = 1;
            unique++;
        }
    }

    int max_len = 0;
    for (int num = 1; num <= unique; num++) {
        /*
        - check each substring with num uniqued charactor
        - update max_len when
          - frequency of all character >= k

        s = "ababbc", k = 2
             ^^
        */
        int j = 0;
        int num_unique = 0, cnt_atleast_k = 0;
        int w_start = 0, w_end = 0;
        fill_n(freq, 26, 0);

        while (w_end < s.length()) {
            if (num_unique <= num) {
                int idx = s[w_end] - 'a';
                if (0 == freq[idx]) {
                    num_unique++;
                }

                freq[idx]++;
                if (k == freq[idx]) {
                    cnt_atleast_k++;
                }
                w_end++;
            } else {
                int idx = s[w_start] - 'a';
                if (k == freq[idx]) {
                    cnt_atleast_k--;
                }
                
                freq[idx]--;
                if (0 == freq[idx]) {
                    num_unique--;
                }
                w_start++;
            }

            if (num_unique == num && cnt_atleast_k == num) {
                max_len = max(max_len, w_end-w_start);
            }
        }
    }

    return max_len;
}

int main(void)
{
    cout << longestSubString("ababbc", 2) << endl;
    cout << longestSubString("aaabb", 3) << endl;    
    cout << longestSubStringSW("ababbc", 2) << endl;
    cout << longestSubStringSW("aaabb", 3) << endl;    
}
