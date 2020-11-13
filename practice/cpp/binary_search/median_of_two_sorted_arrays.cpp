/*
- problem: https://leetcode.com/problems/median-of-two-sorted-arrays/


*/

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{

    vector<int> arr = {1,2,3,4,7,9,10,11};

    int l = 0, r = arr.size()-1;
    while (l < r) {
        int sum = arr[l] + arr[r];
        if (sum > 9) {
            r--;
        } else if (sum < 9) {
            l++;
        } else {
            break;
        }
    }

    cout << arr[l] << "," << arr[r] << endl;

}
