/*
- Problem: https://leetcode.com/problems/short-encoding-of-words/
- Solution:
  - Using trie data structure to manage next word is included by previous words or not.
  - Preprocessing: sort words descent size of each word.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Trie {
    bool is_end;
    Trie* next[27];
    
    Trie() {
        is_end = false;
        memset(next, 0x00,sizeof(Trie*)*27);
    }
};

void addWord(Trie* t, string word) {    
    for (int i = word.length()-1; i >= 0; i--) {
        char c = word[i];
        if (t->next[c - 'a'] == nullptr) {
            t->next[c- 'a'] = new Trie();
        }
        t = t->next[c - 'a'];
    }
    t->is_end = true;
}
    
bool isInclude(Trie* t, string word) {
    for (int i = word.length()-1; i >= 0; i--) {
        char c = word[i];
        if (t->next[c - 'a'] == nullptr) {
            return false;
        }
        t = t->next[c - 'a'];
    }
    return true;
        
}
    
int minimumLengthEncoding(vector<string>& words) {
    sort(words.begin(), words.end(), [](auto a, auto b) {
                                         return a.length() > b.length();
                                     });
        
    int res = 0;
        
    Trie* t = new Trie();
        
    for (auto word : words) {
        if (!isInclude(t, word)) {
            addWord(t, word);
            res += word.length() + 1;
        }
            
    }
    return res;
}

int main(void)
{
    vector<string> words = {"time", "me", "bell"};
    cout << minimumLengthEncoding(words) << endl;
}
