// problem: https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/

#include <iostream>
#include <vector>
using namespace std;

vector<int> maxDepthAfterSplit(string s)
{
    vector<int> res(s.length(),0);
    int a = 0, b = 0;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if ('(' == c) {
            if (b > a) {
                a++,res[i] = 0;
            } else {
                b++,res[i] = 1;
            }
        } else {
            if (b <= a) {
                a--,res[i] = 0;
            } else {
                b--,res[i] = 1;   
            }
        }
    }
    return res;
}

int main(void)
{
    string s;
    cin >> s;
    cout << s << endl;
    vector<int> d = maxDepthAfterSplit(s);
    for (auto it : d) { cout << it << ",";}
    cout << endl;
}
