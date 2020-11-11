#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> sortKMessedArray( const vector<int>& a, int k )
{
    vector<int> arr = a;
    for (int i = 1; i < arr.size(); i++) {
        int temp = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    return arr;
}

vector<int> sortKMessedArray1( const vector<int>& arr, int k ) 
{ 
    priority_queue<int, vector<int>, greater<int>> q;
    vector<int> arr_sort(arr.begin(), arr.end());
  
    for (int i = 0; i <= k; i++) {
        q.push(arr_sort[i]);
    }
  
    for (int i = 0; i < arr_sort.size(); i++) {
        arr_sort[i] = q.top();
        q.pop();
        if (i+k+1 < arr_sort.size()) q.push(arr_sort[i+k+1]);
    }
    return arr_sort;  
}

int main() {
    vector<int> arr = {1, 4, 5, 2, 3, 7, 8, 6, 10, 9};
    vector<int> res = sortKMessedArray(arr,2);
  
    for (auto it : res) {
        cout << it << ",";
    }
    cout << endl;
    return 0;
}
