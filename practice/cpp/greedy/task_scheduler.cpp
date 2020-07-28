// problem : https://leetcode.com/problems/task-scheduler/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int LeastInterval(string task, int n)
{
    vector<int> f(26,0);
    for (auto t : task) {
        f[t-'A']++;
    }
    sort(f.begin(), f.end(), [](auto a, auto b){return a > b;});
    int idle = (f[0]-1)*n;
    for (int i = 1; i < f.size() && f[i] > 0 && idle > 0; i++) {
        idle -= min(f[0]-1, f[i]);
    }

    return task.size() + max(0,idle);
}

int main(void)
{
    string task;
    int n;
    cin >> task;
    cin >> n;
    cout << LeastInterval(task, n) << endl;    
    return 0;
}
