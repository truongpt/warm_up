// problem: https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3480/

// t - (t-3000) ->
// vector<int> temp;

// temp.push_back(t);
// if temp.back() - temp[i] > 30000;
// temp.erase(temp[i]);

#include <iostream>
#include <vector>
using namespace std;

class RecentCounter {
public:
    RecentCounter() {
        time.clear();
    }
    int ping(int t) {
        time.push_back(t);
        while (time.back() - time[0] > 3000) {
            time.erase(time.begin());
        }
        return time.size();
    }

private:
    vector<int> time;

};

    int main(void)
    {
        vector<int> t = {1, 100, 3001, 3002};
        RecentCounter sol;
  
        for (auto it : t) {
            cout << sol.ping(it) << endl;
        }
    }
