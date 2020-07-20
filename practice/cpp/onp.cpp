#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    string exp;
    cin >> exp;
    cout << exp << endl;
    vector<char> v(exp.begin(),exp.end());

    for (auto i : v) cout << i << ", ";
    return 0;
}
