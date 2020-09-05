#include <iostream>
#include <vector>

using namespace std;

void heap_sort(vector<int>& arr)
{
    // create heap
    // by inserting each elem.
#if 0
    for (int i = 0; i < arr.size()-1; i++) {
        int j = j+1;
        while (j > 0) {
            int p = (j-1)/2;
            if (arr[p] >= arr[j]) break;
            swap(arr[p], arr[j]);
            j = p;
        }
    }
#endif

    // heapify
    int num = arr.size()-1;
    for (int i = arr.size()-1; i > 0; i--) {
        int p = i;
        while (p*2+1 <= num) {
            int l = 2*p+1, r = 2*p+2;
            if (r > num) l = r;
            int next = arr[l] > arr[r] ? l : r;
            if (arr[p] >= arr[next]) break;
            swap(arr[p], arr[next]);
            p = next;
        }
    }


    for (int i = arr.size()-1; i > 0; i--) {

        swap(arr[0], arr[i]);
        int cur = 0;
        int last = i-1;

        while (2*cur+1 <= last) {
            int l = cur*2 + 1, r = cur*2 + 2;

            if (r > last) r = l;

            int next = (arr[l] > arr[r] ? l : r);

            if (arr[cur] >= arr[next]) break;
            swap(arr[cur], arr[next]);
            cur = next;
        }
    }
}

int main(void)
{
    vector<int> v = {12, 10, 11, 8, 9, 4, 5, 1};
    heap_sort(v);
    for (auto it : v) {
        cout << it << ",";
    }
    cout << endl;

}
