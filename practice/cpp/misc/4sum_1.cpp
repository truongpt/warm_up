

/*
function findArrayQuadruplet(arr, s):
    n = arr.length

    # if there are fewer than 4 items in arr, by
    # definition no quadruplet exists whose sum is s
    if (n < 4):
        return []

    # sort arr in an ascending order
    arr.sort()

    for i from 0 to n - 4:
        for j from i + 1 to n - 3:
            # r stores the complementing sum
            r = s - (arr[i] + arr[j])

            # check for sum r in subarray arr[j+1cn-1]
            low = j + 1, high = n - 1;

            while (low < high):
                if (arr[low] + arr[high] < r):
                    low++

                else if (arr[low] + arr[high] > r):
                    high--

                # quadruplet with given sum found
                else:
                    return [arr[i], arr[j], arr[low], arr[high]]

    return []

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findArrayQuadruplet(const vector<int> &a, int s) 
{
    vector<int> arr = a;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n-4; i++) {
        for (int j = i+1; j < n-3; j++) {
            int sum2 = s - (arr[i] + arr[j]);
            int low = j+1, high = n-1;
            while (low < high) {
                if (arr[low] + arr[high] == sum2) {
                    return {arr[i], arr[j], arr[low], arr[high]};
                } else if (arr[low] + arr[high] < sum2) {
                    low++;
                } else {
                    high--;
                }
            }
        }
    }

    return {};
}

int main() {
    vector<int> arr = {2, 7, 4, 0, 9, 5, 1, 3};
    int s = 20;
    vector<int> res = findArrayQuadruplet(arr,s);
    for (auto it : res) {
        cout << it << ",";
    }
    cout << "the end" << endl;
    return 0;
}
