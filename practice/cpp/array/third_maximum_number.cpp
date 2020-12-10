/*
- Problem: https://leetcode.com/explore/learn/card/fun-with-arrays/523/conclusion/3231/
- Solution:
  - Use heap with size = 3.
  - Time complexity -> O(n * log 3) -> O(n) 

*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int thirdMax(vector<int>& arr)
{
    priority_queue<int, vector<int>, greater<int>> q;
    unordered_set<int> s;
    for (auto it : nums) {
        if (s.find(it) == s.end()) {
            if (q.size() < 3) {
                q.push(it);
                s.insert(it);
            } else {
                if (q.top() < it ) {
                    s.erase(q.top());
                    s.insert(it);

                    q.pop();
                    q.push(it);
                }
            }

        }
    }

    if (q.size() < 3) {
        while (q.size() != 1) {
            q.pop();
        }
    }
    return q.top();
}

int main(void)
{
    {
        vector<int> arr = {2, 2, 3, 1};
        cout << thirdMax(arr) << endl;
    }
    {
        vector<int> arr = {2, 2 , 1};
        cout << thirdMax(arr) << endl;
    }
    {
        vector<int> arr = {2, 2, 3, 2};
        cout << thirdMax(arr) << endl;
    }
}
