/*
- Problem: https://leetcode.com/problems/validate-stack-sequences
- Solution: Using stack to simulate push/pop.
  - when stack top == popped[i] -> pop until
  - after that push more 1 elem to stack
  - Time and space complexity.
    - TC: O(n)
    - SC: O(n) 
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
{
    int N = pushed.size();
    int i = 0, j = 0;
    stack<int> st;
        
    while (i < N || j < N) {
        while (!st.empty()) {
            if (j < N && st.top() == popped[j]) {
                j++;
                st.pop();
            } else {
                break;
            }
        }
            
        if (i < N) {
            st.push(pushed[i]);
            i++;
        } else {
            return st.empty();
        }
     }
 
    return st.empty();
 }

int main(void)
{
    vector<int> pushed = {1,2,3,4,5};
    vector<int> popped = {4,5,3,2,1};
    cout << validateStackSequences(pushed, popped) << endl;
}
