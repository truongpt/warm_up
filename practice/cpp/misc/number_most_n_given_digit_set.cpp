/*
- Problem: https://leetcode.com/problems/numbers-at-most-n-given-digit-set/
- Solution 1.
  - Backtracking to combine all case -> Time Limit Exceeded

- Solution 2.
  - n -> number of digit in n. -> k
  - check all combined <= k-1.
    - num = digit.size().
    - total digit-1 = num^(k-1)
  - check all combined k.
    - check number elem < n[0]

  - sample.
    - ["1","2","3","4","5","6","7","8","9"]
    - 74546987
  - total 7 digit.
  - 8 digits.
    - (1 -> 6) * total 7 digit.

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int countK(vector<int>& ns, vector<int>& cnt_arr, vector<int>& d, int k)
{
    if (k > cnt_arr.size()) {
        return 0;
    }

    int num = 0;
    int cnt = 0;
    bool equal = false;
    for (auto it : d) {
        if (it < ns[k]) {
            num++;
        }
        if (it == ns[k]) {
            equal = true;
        }
    }

    if (k < cnt_arr.size()){
        cnt = num * cnt_arr[k];
    } else {
        cnt = num + (equal ? 1 : 0);
    }
    
    if (equal) {
        return cnt + countK(ns, cnt_arr, d, k+1);
    }
    return cnt;

}

int getNumberMostNGivenDigit(vector<string>& digit, int n)
{
    vector<int> d;
    for (auto it : digit) {
        d.push_back(it[0]-'0');
    }

    int k = to_string(n).size();
    int cnt = 0;
    int num = digit.size();


    sort(d.begin(), d.end());
    vector<int> cnt_arr;
    
    for (int i = k-1; i >= 1; i--) {
        int cnt_k = 1;
        for (int j = 0; j < i; j++) {
            cnt_k *= num;
        }
        cnt_arr.push_back(cnt_k);
        cnt += cnt_k;
    }

    vector<int> ns(k,0);
    int temp = n;
    for (int i = 0; i < k; i++) {
        int elem = n%10;
        ns[k-1-i] = elem;
        n = n/10;
    }

    int cnt1 = countK(ns, cnt_arr, d, 0);
    return cnt+cnt1;    
}

int main(void)
{
    {
        vector<string> d = {"1","3","5","7"};
        cout << getNumberMostNGivenDigit (d, 7375)<< endl;
    }

    {
        vector<string> d = {"1","2","3","4","5","6","7","8","9"};
        cout << getNumberMostNGivenDigit (d, 74546987)<< endl;
    }
    return 0;
}
