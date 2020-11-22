/*
- Problem: https://leetcode.com/explore/learn/card/fun-with-arrays/521/introduction/3240/
  - Input: [-4,-1,0,3,10]
  - Output: [0,1,9,16,100]

- Solution.
  -4,-1,0,3,10
   ^        ^
   l        r

  -4,-1,0,3,100
   ^      ^
   l      r

   3,-1,0,16,100
   ^    ^
   l    r

   0,-1,9,16,100
   ^  ^
   l  r

  - compare arr[l]^2 vs arr[r]^2
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> squareSortedArray(vector<int> arr)
{
    int l = 0, r = arr.size()-1;
    vector<int> res(arr.size());
    int i = arr.size()-1;
    while (l <= r) { 
        int first = arr[l]*arr[l], second = arr[r]*arr[r];
        if (first > second) {
            res[i--] = first;
            l++;
        } else {
            res[i--] = second;
            r--;
        }
    }

    return res;
}

int main(void)
{
    {
        vector<int> arr = {-4,-1};
        vector<int> res = squareSortedArray(arr);
        for (auto it : res) {
            cout << it << ",";
        }
        cout << endl;
    }

    {
        vector<int> arr = {-4,-3,-1,0,4,4,4,4,10};

        vector<int> res = squareSortedArray(arr);
        for (auto it : res) {
            cout << it << ",";
        }
        cout << endl;
    }
    return 0;
}

