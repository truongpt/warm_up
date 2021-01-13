/*
- Problem: https://leetcode.com/problems/boats-to-save-people/
- Solution
  - Greedy, pair heaviest person with lightest person
    - If weight of them is not larger than limit -> go to boats
    - Otherwise only heaviest persion go to boats
  - Using 2 pointer
  - Time and space complexity
    - TC: O(n)
    - SC: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int cnt = 0;
    int i = 0, j = people.size()-1;
    while (i <= j) {            
        if (people[i] + people[j] <= limit) {
            i++,j--;
        } else {
            j--;
        }
        cnt++;
    }
        
    return cnt;
}

int main()
{
    vector<int> people = {1,2,5,4,3};
    cout << numRescueBoats(people, 5) << endl;
}
