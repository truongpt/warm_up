#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1,5,4,3,2,
// 5,1,4,3,2
// 2,3,4,1,5
// 4,3,2,1,5

void flip(vector<int>& arr, int k)
{
    for (int i = 0; i <= k/2; i++) {
        swap(arr[i], arr[k-i]);
    }
}

int getMaxIndex(vector<int>& arr, int index) 
{
    int max_index = 0;

    for (int i = 1; i <= index; i++) {
        if (arr[i] > arr[max_index]) {
            max_index = i;
        }
    }
    return max_index;
}

// O(n^2)
vector<int> pancakeSort(const vector<int>& arr ) 
{
    vector<int> arr_sort(arr.begin(), arr.end());
    for (int i = arr_sort.size()-1; i > 0; i--) { // O(n)
        int max_index = getMaxIndex(arr_sort, i); // O(n)
        if (max_index != i) {
            flip(arr_sort, max_index); // O(n)
            flip(arr_sort, i); // O(n)
        }
    }
    return arr_sort;
}

int main() {
    vector<int> arr = {1,5,4,3,2};
    vector<int> res = pancakeSort(arr);
    for (auto it : res) {
        cout << it << ",";
    }
    cout << endl;
}
