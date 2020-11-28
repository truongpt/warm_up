/*
- Problem: https://leetcode.com/explore/featured/card/fun-with-arrays/525/inserting-items-into-an-array/3253/
```
nums1 = [1,2,7,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

```

- Intuition
  - Get each elem nums2 -> insert to nums1
    1,2,2,7,8,9,3,5,6
          ^     ^
*/

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    for (int i = m; i < m+n; i++) {
        nums1[i] = nums2[i-m];
    }
    int i = 0, j = m;
        
    while (i != j && j < m+n) {
        if (nums1[i] <= nums1[j]) {
            i++;
        } else {
            int temp = nums1[j];
            int k = j;
            while (k > i) {
                nums1[k] = nums1[k-1];
                k--;
            }
            nums1[i] = temp;
            i++;
            j++;
        }
    }
}

int main(void)
{


}
    
