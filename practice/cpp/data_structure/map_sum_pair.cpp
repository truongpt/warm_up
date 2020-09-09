// problem: https://leetcode.com/problems/map-sum-pairs/
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct Trie {
    int val;
    unordered_map<char, Trie*> next;
    Trie(int v) : val(v) {};
    Trie() {val = 0;};
};

class MapSum {
public:
    Trie* t;
    MapSum()
        {
            t = new Trie();
        }
  
    void insert(string key, int val)
        {
            Trie* temp = t;
            for (auto c : key) {
                if (temp->next.find(c) == temp->next.end()) {
                    temp->next[c] = new Trie();
                }
                temp = temp->next[c];
            }
            temp->val = val;
        }
  
    int sum(string prefix)
        {
            Trie* temp = t;
            for (auto c : prefix) {
                if (temp->next.find(c) != temp->next.end()) {
                    temp = temp->next[c];
                } else {
                    return 0;
                }
            }
            return sumAll(temp);
        }

    int sumAll(Trie* t)
        {
            int cur = t->val;
            for (auto it : t->next) {
                cur += sumAll(it.second);
            }
            return cur;
        }
};

int main()
{
    MapSum ms;
    ms.insert("apple",10);
    ms.insert("applex",1);
    ms.insert("appley",2);
    ms.insert("applez",3);
    cout << ms.sum("ap") << endl;

}
