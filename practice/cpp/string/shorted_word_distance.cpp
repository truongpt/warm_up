/*
- Problem: https://leetcode.com/explore/featured/card/december-leetcoding-challenge/569/week-1-december-1st-december-7th/3550/

- Solution:
  - store position of 2 words -> update value when reach each words.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int shortedDistance(vector<string> words, string word1, string word2)
{
    int distance = words.size();
    int pos1 = -1, pos2 = -1;

    for (int i = 0; i < words.size(); i++) {
        if (words[i] == word1) {
            pos1 = i;
            if (pos2 != -1) {
                distance = min(distance, abs(pos1 - pos2));
            }
        }
        if (words[i] == word2) {
            pos2 = i;
            if (pos1 != -1) {
                distance = min(distance, abs(pos1 - pos2));
            }
        }
    }

    return distance;
}

int main(void)
{

    cout << shortedDistance({"practice", "makes", "perfect", "coding", "makes"}, "makes", "coding") << endl;

}
