// problem: https://www.pramp.com/challenge/gKQ5zA52mySBOA5GALj9

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*

  [2, 7, 4, 0, 9, 5, 1, 3], s = 20
  0,4,7,9 = 20.

  - solution 1:
  -  using backtracking to select all 4 elements.
  - TC : O(n^4)
  - SC: O(0)
  - solution 2:
  - 2 sum -> O(n)
  - 3 sum -> O(n^2)
  - 4 sum -> O(n^3)
  
  
*/

vector<int> find2Sum(const vector<int>& arr, int index, int s)
{
    unordered_set<int> comp = {};
    for (int i = index; i < arr.size(); i++) {
        if (comp.find(arr[i]) != comp.end()) {
            return vector<int> {arr[i], s-arr[i]};
        }
        comp.insert(s-arr[i]);
    }
    return {};
}

vector<int> find3Sum(const vector<int>& arr, int index, int s) {
    for (int i = index; i < arr.size(); i++) {
        vector<int> sum2 = find2Sum(arr, i+1, s-arr[i]);
        if (!sum2.empty()) {
            sum2.push_back(arr[i]);
            return sum2;
        }

    }
    return {};
}

vector<int> findArrayQuadruplet(const vector<int> &a, int s) 
{
    vector<int> arr = a;
    int n = arr.size();

    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
        vector<int> sum3 = find3Sum(arr, i+1, s-arr[i]);
        if (!sum3.empty()) {
            sum3.push_back(arr[i]);
            sort(sum3.begin(), sum3.end());
            return sum3;
        }
    }
    return {};
}

vector<int> findArrayQuadruplet1(const vector<int> &a, int s) 
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
    vector<int> res = findArrayQuadruplet1(arr,s);
    for (auto it : res) {
        cout << it << ",";
    }
    cout << "the end" << endl;
    return 0;
}
