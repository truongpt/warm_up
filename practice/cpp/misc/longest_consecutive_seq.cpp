// problem: https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    unordered_map<int,int> dj_set;
    
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> m;
        
        for (auto it : m) {
            dj_set[it] = -1;
        }
        
        for (auto it : m) {
            m.insert(it);
            
            if (m.find(it-1) != m.end()) {
                // join it, it-1
                joinDj(it, it-1);
                
            }
            
            if (m.find(it + 1) != m.end()) {
                // join it, it + 1
                joinDj(it+1, it);
            }
        }
        
        unordered_map<int,int> cnt;
        
        for (auto it : nums) {
            cout << getDjIndex(it) << endl;
            //cnt[getDjIndex(it)]++;
        }
        
        int cnt_value = 0;
        for (auto it : cnt) {
            cnt_value = max(cnt_value, it.second);
        }
        
        return cnt_value;
    }
    
    int getDjIndex(int value) {
        if (dj_set[value] == -1) {
            return value;
        } 
        return getDjIndex(dj_set[value]);
    }
    
    void joinDj(int v1, int v2) {
        int idx1 = getDjIndex(v1);
        int idx2 = getDjIndex(v2);
        dj_set[idx1] = idx2;
    }
    
};
