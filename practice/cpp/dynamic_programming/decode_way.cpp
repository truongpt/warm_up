// problem: https://leetcode.com/problems/decode-ways/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int numDecodings(string s)
{
    if (s[0] == '0') return 0;
    vector<int> num(s.size(),0);
    num[0] = 1;
    for (int i = 1; i < s.size(); i++) {

        if (s[i] != '0') num[i] += num[i-1];

        string t = s.substr(i-1,2);
        int n = stoi(t);
        if (n <= 26 && n > 0 && s[i-1] != '0') num[i] += (i > 1 ? num[i-2] : 1);
    }
    return num[s.size()-1];
}

int main(void)
{
    cout << numDecodings("016") << endl;
    cout << numDecodings("1") << endl;
    cout << numDecodings("10") << endl;
    cout << numDecodings("101") << endl;
    cout << numDecodings("100") << endl;
    cout << numDecodings("226") << endl;
    cout << numDecodings("16") << endl;
    return 0;
}
