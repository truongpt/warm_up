/*
- Problem: https://leetcode.com/explore/learn/card/fun-with-arrays/525/inserting-items-into-an-array/3245/
- Solution:
  - 1,0,2,3,0,4,5,0
      ^ ^
  - 1,0,0,2,3,0,5,4
  - How to solve with time complexity O(n)
    - count num of zero.
    - preparing end of array = number of zero -> set = 0.
    - 2 pointers?
      
*/

vector<int> duplicateZero(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 0) {
            int j = arr.size()-1;
            while (j >= i+1) {
                arr[j] = arr[j-1];
                j--;
            }
        }
    }
    return arr;
}


int main(void)
{
    
    vector<int> arr = {1,0,2,3,0,4,5,0};
    vector<int> res = duplicateZero(arr);

    for (auto it : res) {
        cout << it << ",";
    }
    cout << endl;
}
