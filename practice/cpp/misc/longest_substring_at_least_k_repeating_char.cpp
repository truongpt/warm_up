/*
- Problem:

- Solution
  - Checking all character with frequency < k
  - recursive ...

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

    int max_len = 0;
    int j = start;
    bool is_divide = false;
    for (int i = start; i <= end; i++) {
        if ( freq[s[i]] < k) {
            is_divide = true;
            max_len = max(max_len, longestSection(s, k, j, i-1));
            j = i+1;
        }
    }

    if (j < end && is_divide) {
        max_len = max(max_len, longestSection(s, k, j, end));
    }
        
    return (is_divide ?  max_len : end-start+1);
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
