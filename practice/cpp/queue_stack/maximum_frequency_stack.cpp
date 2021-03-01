/*
- Problem: https://leetcode.com/problems/maximum-frequency-stack
- Solution:
  - Frequency of element status is managed by hashtable.
  - Using priority queue to keep the most frequency elem on the top.
  - Time and space complexity.
    - TC: O(log n) for push/pop
    - SC: O(n)

- Solution2:
  - Using 2 hashtable:
    - One map value -> frequency
    - One maping frequency -> stack of values, which same frequency.
  - Time and space complexity.
    - TC: O(1) for push/pop
    - SC: O(n)

*/

#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Compare
{
public:
    bool operator() (vector<int> a, vector<int> b)
    {
        if (a[1] == b[1]) {
           return a[2] < b[2]; 
        } 
        return a[1] < b[1];
    }
};


class FreqStack {
public:
    unordered_map<int,int> freq;
    priority_queue<vector<int>, vector<vector<int>>, Compare> q;
    int cnt;
    FreqStack() {
        freq.clear();
        while (!q.empty()) {
            q.pop();
        }
        cnt = 0;
    }
    
    void push(int x) {
        freq[x]++;
        vector<int> elem_x = {x, freq[x], cnt};
        q.push(elem_x);
        cnt++;
    }
    
    int pop() {
       auto elem = q.top();
        q.pop();
        freq[elem[0]]--;
        // cnt--;
        return elem[0];
    }
};

// Solution 2
class FreqStack2 {
public:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> group;
    int max_freq;
    
    FreqStack2() {
        max_freq = 0;
        freq.clear();
        group.clear();
    }
    
    void push(int x) {
        freq[x]++;
        if (freq[x] > max_freq) {
            max_freq = freq[x];
        }
        group[freq[x]].push(x);
    }
    
    int pop() {
        int res = group[max_freq].top();
        group[max_freq].pop();
        freq[res]--;
        while (max_freq > 0 && group[max_freq].empty()) {
            max_freq--;
        }
        
        return res;
    }
};

int main(void)
{
    FreqStack* obj = new FreqStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(3);
    obj->push(4);
    for (int i = 0; i < 5; i++) {
        cout << obj->pop() << ",";
    }

    cout << endl;
}
