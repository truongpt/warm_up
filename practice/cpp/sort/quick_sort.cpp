#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quick_sort(vector<int>& arr, int l, int h)
{
    if (l >= h) {return;};
    int pivot = arr[l];
    int i = l+1, j = h;

    while (i <= j) {
        while (i <=j && arr[i] <= pivot) {
            i++;
        }
        while (i <= j && arr[j] > pivot) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    quick_sort(arr, l, j-1);
    quick_sort(arr, j+1, h);
}

int main(void)
{
    vector<int> v = {3,2,9,8,7,6,5};
    quick_sort(v, 0 , v.size()-1);
    for (auto it : v) {
        cout << it << ",";
    }
    cout << endl;
}
