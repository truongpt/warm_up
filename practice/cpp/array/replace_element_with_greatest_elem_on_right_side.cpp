/*
- Problem: https://leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3259/
- Solution.
```
input : 17,18,5,4,6,1
                    ^
output: 17,18,5,4,6,-1
                  ^

```
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> replaceElements(vector<int> & arr)
{
    int cur = arr.back();
    arr.back() = -1;

    for (int i = arr.size()-2; i >= 0; i--) {
        int temp = arr[i];
        arr[i] = max(cur, arr[i+1]);
        cur = temp;
    }
    return arr;
}

int main(void)
{
    vector<int> arr = {17,18,5,4,6,1};
    vector<int> res = replaceElements(arr);
    for (auto it : res) {
        cout << it << ",";
    }
    cout << endl;
}
