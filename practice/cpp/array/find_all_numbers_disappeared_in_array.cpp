/*
- Problem: https://leetcode.com/explore/learn/card/fun-with-arrays/523/conclusion/3270/
- Intuition.
  - Move each element to suitable index with arr[i] = i+1;
  - TC: O(n)
  - SC: O(1)

*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> findDisappearedNumber(vector<int>& arr)
{
    vector<int> res = {};
    for (int i = 0; i < arr.size(); i++) {

        while (arr[i] && arr[i] != i+1 && arr[i] != arr[arr[i]-1]) {
            swap(arr[i], arr[arr[i]-1]);
        }
            
        if (arr[i] && arr[i] == arr[arr[i]-1] && i+1 != arr[i]) arr[i] = 0;
    }

    for (int i = 0; i < arr.size(); i++) {
        if (!arr[i]) {
            res.push_back(i+1);
        }
    }
}

int main(void)
{
    vector<int> arr = {4,3,2,7,8,2,3,1};
    vector<int> res = findDisappearedNumber(arr);
    for (auto it : res) {
        cout << it << ",";
    }
    cout << endl;
}

