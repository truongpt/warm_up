// problem: https://leetcode.com/problems/word-break/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Trie
{
public:
    bool is_end;
    unordered_map<char, Trie*> next;
    Trie() {
        is_end = false;
        // next.clear();
    }
    Trie(char c) {
        is_end = false;
        next[c] = new Trie();
    }
};

class Solution {
public:
    Trie* t;
    unordered_map<int, unordered_map<Trie*, bool>> result;
    unordered_map<int, unordered_map<Trie*, bool>> done;
    
    bool wordBreak(string s, vector<string>& wordDict) {
        t = new Trie();
        int n = s.length();
        
        for (auto word : wordDict) {
            Trie* temp = t;
            for (auto c : word) {
                if (nullptr == temp->next[c]) {
                    temp->next[c] = new Trie();
                }
                temp = temp->next[c];
            }
            temp->is_end = true;
        }      

        return isBreak(t, s, 0);
    }

    bool isBreak(Trie* cur_t, string s, int index) {
        
        if (done[index][cur_t]) {
            return result[index][cur_t];
        }
        
        if (index == s.length()-1 && 
            nullptr != cur_t->next[s[index]] && 
            true == cur_t->next[s[index]]->is_end) {
            return true;
        } else if (index >= s.length()-1 ||
                   nullptr == cur_t->next[s[index]]){
            return false;
        }
    
        bool c = false;
        if (true == cur_t->next[s[index]]->is_end) {
            c = isBreak(t, s, index+1);
        }

        bool c2 = isBreak(cur_t->next[s[index]], s, index+1);

        done[index][cur_t] = true;
        result[index][cur_t] = c || c2;

        return result[index][cur_t];
    }
};

int main() {
    {
        string s = "leetcode";
        vector<string> wordDict = {"leet", "code"};
        Solution sol;
        cout << sol.wordBreak(s, wordDict) << endl;
    }
    {
        string s = "catsandog";
        vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
        Solution sol;
        cout << sol.wordBreak(s, wordDict) << endl;
    }

    {
        string s = "applepenapple";
        vector<string> wordDict = {"apple", "pen"};
        Solution sol;
        cout << sol.wordBreak(s, wordDict) << endl;
    }

}

