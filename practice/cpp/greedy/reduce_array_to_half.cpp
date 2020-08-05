// problem: https://leetcode.com/problems/reduce-array-size-to-the-half/
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

//TODO: time optimize
int minSetSize(vector<int>& arr)
{
    unordered_map<int,int> m;
    for (auto a : arr) {
        m[a]++;
    }

    vector<int> f;
    for (auto it : m) {
        f.push_back(it.second);
    }

    sort(f.begin(), f.end(), [](auto a, auto b){return a > b;});
    int h = 0, t = arr.size()/2 + arr.size()%2;
    
    for (int i = 0; i < f.size(); i++) {
        h += f[i];
        if (h >= t) {
            return i+1;
        }
    }
    return -1;
}

int main(void)
{
    string s, o;
    stringstream ss;
    vector<int> arr;
    getline(cin, s);
    ss << s;
    while (ss >> o) {
        arr.push_back(stoi(o));
    }
    cout << minSetSize(arr) << endl;
}
