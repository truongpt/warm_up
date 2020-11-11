// problem: https://leetcode.com/problems/repeated-dna-sequences/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cmath>

using namespace std;

/*
- Suy nghĩ.
  - Tìm chuỗi lặp lại -> sử dụng KMP?
  - Cố định 10 phần tử -> duyệt toàn bộ sử dụng hashtable rồi check sự lặp lại?
  - Tránh sự lặp lại bằng cách dùng thêm 1 hashtable để ngăn chặn.
- Solution 1: (easy stupid)
  - Dùng hashtable.
  - Việc ngăn chặn lặp lại cũng bằng hashtable, cuối cùng mới duyệt nó và chuyển
  thành vector.
  - Độ phức tạp TC: 0(n), SC: O(n*k) k = 10 -> O(n)
  - Note: việc tính hashID -> O(k)
  - Cách này hơi lực điền, một kiểu brute force, không có tri thức mấy.
  - Chưa tận dụng được lợi thế  trong string có 4 kí tự

- Solution 2
  - Solution 1 thì TC lớn bởi vì việc tính hashID của string ~ O(k)
  - Sử dụng Rabin-Karp -> Rolling hash, mỗi lần tính hashtable -> O(1)
- Solution 3
  - Sử dụng bit manupulation.
  - Tư tưởng nó như thế nào?
  - 1 kiểu chuyển sang bitmap và dùng nó như hash id
  - Nếu thế cứ dụng nó như con số thập phân thì làm sao nhỉ? 000123 -> 123
*/

vector<string> findRepeatedDNASequence(string s)
{
    vector<int> arr;
    unordered_map<char, int> m = {{'A',0},{'C',1},{'G',2},{'T',3}};
    for (auto c : s) {
        arr.push_back(m[c]);
    }

    int a = 4, a10 = pow(4,10);
    unordered_set<int> pattern;
    unordered_set<string> res;
    int hash_id = 0;

    for (int i = 0; i <= arr.size() - 10; i++) {
        if (i != 0) {
            hash_id = hash_id*a - arr[i-1]*a10 + arr[i+9];
        } else {
            for (int j = 0; j < 10; j++) {
                hash_id = hash_id*a + arr[j];
            }
        }

        if (pattern.find(hash_id) != pattern.end()) {
            res.insert(s.substr(i,10));
        }
        pattern.insert(hash_id);
    }

    vector<string> ans;
    for (auto it : res) {
        ans.push_back(it);
    }

    return ans;
}
    
vector<string> findRepeatedDNASequence1(string s)
{
    if (s.length() <= 10) return {};
    unordered_set<string> pattern;
    unordered_set<string> res;

    for (int i = 0; i <= s.length()-10; i++) {
        string temp = s.substr(i,10);
        if (pattern.find(temp) != pattern.end()) {
            res.insert(temp);
        }
        pattern.insert(temp);
    }

    vector<string> ans;
    for (auto it : res) {
        ans.push_back(it);
    }
    return ans;
}


int main(void)
{
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> res = findRepeatedDNASequence(s);
    for (auto it : res) {
        cout << it << ",";
    }
    cout << endl;
}
