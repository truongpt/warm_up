// problem: https://leetcode.com/problems/find-all-duplicates-in-an-array/
// req: mem O(1), time O(n)

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct Solution{
    vector<int> findDuplicate(vector<int>& arr)
        {
            vector<int> res;
            for (int i = 0; i < arr.size(); i++) {
                arr[abs(arr[i])-1] *= -1;
            }

            for (int i = 0; i < arr.size(); i++) {
                if (arr[abs(arr[i]) - 1] > 0) {
                    res.push_back(abs(arr[i]));
                    arr[abs(arr[i]) - 1] *= -1;
                }
            }
            return res;
        }
};

int main(void)
{
    string s,o;
    getline(cin, s);

    stringstream ss;
    ss << s;
    vector<int> arr;

    while (ss >> o) {
        arr.push_back(stoi(o));
    }

    Solution sol;
    vector<int> res = sol.findDuplicate(arr);
    for (auto it : res) {
        cout << it << ",";
    }
    cout << endl;

    return 0;
}
