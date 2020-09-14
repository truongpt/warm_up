// problem: https://leetcode.com/problems/bulls-and-cows/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> m;
        for (auto c : secret) {
            m[c]++;
        }
        int b = 0, c = 0;

        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                m[secret[i]]--;
                b++;
            }
        }
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] != guess[i]) {
                if (m[guess[i]] != 0)
                {
                    c++;
                    m[guess[i]]--;
                }

            }
        }
        return to_string(b) + "A" + to_string(c) + "B";
    }
};

int main()
{
    Solution sol;
    cout << sol.getHint("7108","8170") << endl;
}
