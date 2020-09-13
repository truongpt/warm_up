// problem http://codeforces.com/contest/1328/problem/C

#include <iostream>
#include <string>
using namespace std;

void findTerXor (string x, int n)
{
    string ma = "", mi = "";

    for (auto c : x) {
        if ('0' == c) {
            ma = ma + '0';
            mi = mi + '0';
        } else if ('1' == c) {
            ma = ma + '0';
            mi = mi + '1';
            string c =  (ma > mi ?  ma : mi);
            mi = (ma <= mi ?  ma : mi);
            ma = c;
        } else {
            // (0,2) (1,1)
            string m1 = ma + '1';
            string m2 = mi + '2';
            if (m1 > m2) {
                mi =  mi + '2';
                ma = ma + '0';
                string c =  (ma > mi ?  ma : mi);
                mi = (ma <= mi ?  ma : mi);
                ma = c;
            } else {
                mi =  mi + '1';
                ma = ma + '1';
            }
        }
    }

    cout << ma << endl;
    cout << mi << endl;
}

int main(void)
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        string x;
        cin >> n;
        cin >> x;
        findTerXor(x,n);
    }
}
