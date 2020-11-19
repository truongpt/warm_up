/*
- Problem: Array Quadruplet
    Given an unsorted array of integers arr and a number s, write a function findArrayQuadruplet that finds 
    four numbers (quadruplet) in arr that sum up to s. Your function should return an array of these numbers 
    in an ascending order. If such a quadruplet doesnft exist, return an empty array.
     
    Note that there may be more than one quadruplet in arr whose sum is s. 
    Youfre asked to return the first one you encounter (considering the results are sorted).
     
    Explain and code the most efficient solution possible, and analyze its time and space complexities.

    - input:  arr = [2, 7, 4, 0, 9, 5, 1, 3], s = 20
    - output: [0, 4, 7, 9] 

- Solution 1.
  - Brute force -> 4 for loop
  - Time & Space.
    - TC: O(n^4)
    - SC: O(1)

- Solution 2.
  - Start from sum 2 elements problem. -> https://www.youtube.com/watch?v=XKu_SEDAykw
    - Time complexity: O(n)
    - Space complexity: 
      - O(n) for unsorted array
      - O(1) for sorted array
  - For sum 3 elements -> O(n^2)
    ```
    For i = 0 -> n-3
    {
      sum2( s - arr[i])
    }
    ```
    - Time complexity: O(n^2)

  - For sum 3 elements
    ```
    For i = 0 -> n-4
    {
      sum3( s - arr[i])
    }
    ```
    - Time complexity: O(n^3)
    - Space complexity: O(log n) <- memory for sorting array, assume sort algorithms is quick sort.

- Comparing performance.
  - Use case at main function.
  - Result
    - Solution 1:  5.10503  (second)
    - Solution 2:  0.030944 (second)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include "../utility/perf.h"

using namespace std;

vector<int> find4SumBF (vector<int>& arr, int s)
{
    if (arr.size() < 4) return {};
    int n = arr.size();
    vector<int> res = {};
    for (int i = 0; i < n-3; i++) {
        for (int j = i+1; j < n-2; j++) {
            for (int k = j+1; k < n-1; k++) {
                for (int h = k+1; h < n; h++) {
                    if (s == arr[i] + arr[j] + arr[k] + arr[h]) {
                        res.push_back(arr[i]);
                        res.push_back(arr[j]);
                        res.push_back(arr[k]);
                        res.push_back(arr[h]);
                        sort(res.begin(), res.end());
                        return res;
                    }
                }
            }

        }
    }

    return {};
    
}

vector<int> find4SumO (vector<int>& arr, int s)
{
    if (arr.size() < 4) return {};
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<int> res = {};
    for (int i = 0; i < n-3; i++) {
        for (int j = i+1; j < n-2; j++) {
            int l = j+1, r = n-1;
            int sum2 = s - arr[i] - arr[j];
            while (l < r) {
                if (arr[l] + arr[r] < sum2) {
                    l++;
                } else if (arr[l] + arr[r] > sum2) {
                    r--;
                } else {
                    return {arr[i], arr[j], arr[l], arr[r]};
                }
            }
        }
    }

    return {};
}

int main(void)
{

    vector<int> arr1 = {}, arr2 = {};
    int num = 1000;
    int s = 100*rand();

    for (int i = 0; i < num; i++) {
        int temp = rand();
        arr1.push_back(temp);
        arr2.push_back(temp);
    }

    vector<int> res;
    {
        TIME_SCOPE("find4SumBF");
        res = find4SumBF(arr1, s);
    }

    // verify
    int sum = 0;
    for (auto it : res) {
        sum += it;
    }

    if (sum != s) {
        cout << "S1 Error" << endl;
    }

    {
        TIME_SCOPE("find4SumO");
        res = find4SumO(arr2, s);
    }

    sum = 0;
    for (auto it : res) {
        sum += it;
    }

    if (sum != s) {
        cout << "S1 Error" << endl;
    }
}
