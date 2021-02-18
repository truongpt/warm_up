/*
- Problem: https://leetcode.com/problems/arithmetic-slices
- Solution:
  - Find serial arithmetic -> n -> arithmetic slices = (n-2)*(n-1)
  - Time and space complexity.
    - TC: O(n)
    - SC: O(1)
*/
#include <iostream>
#include <vector>
using namespace std;

int numberOfArithmeticSlices(vector<int>& A) {
    if (A.size() < 3) {
        return 0;
    }

    int cnt = 0;
    int serial = 1;
    int offset = A[1] - A[0];
        
    for (int i = 1; i < A.size(); i++) {   
        if (A[i] - A[i-1] == offset) {
            serial++;
            if (i == A.size()-1)  {
                cnt += (serial - 2)*(serial -1)/2;
            }
        } else {
            offset = A[i] - A[i-1];
            cnt += (serial - 2)*(serial -1)/2;
            serial = 2;
        }
    }
        
    return cnt;
}

int main(void)
{
    vector<int> arr = {1, 3, 5, 7, 9};
    cout << numberOfArithmeticSlices(arr) << endl;
}
