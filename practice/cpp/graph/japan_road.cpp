#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>

using namespace std;

bool dfs(vector<vector<int>>& g, int b, int t, vector<bool>& todo, vector<int>& p);

int minimumCostInTree(int n, std::vector<std::vector<int>> paths)
{
    unordered_map<long, vector<int>> mg;
    mg.clear();
    vector<vector<int>> g (n+1, vector<int>{});
    for (auto p : paths) {
        g[p[0]].push_back(p[1]);
        g[p[1]].push_back(p[0]);
        int m = max(p[0], p[1]);
        int n = min(p[0], p[1]);
        long key = (long)n*100000+(long)m;
        mg[key].push_back(0);
        mg[key].push_back(p[2]);
        mg[key].push_back(p[3]);
    }
    
    for (int i = 1; i < n; i++) {
        vector<bool> todo (n+1, false);
        vector<int> p = {};
        dfs(g, i, i+1, todo, p);

        for (int j = 0; j < p.size()-1; j++) {
            int m = max(p[j], p[j+1]);
            int n = min(p[j], p[j+1]);
            long key = (long)n*100000+(long)m;
            mg[key][0]++;
        }
    }

    int sum = 0;
    for (auto p : mg) {
        int elem_cost = min(p.second[0]*p.second[1],p.second[2]);
        // cout << "road = " << p.first << ", num = "<< p.second[0] << ", c1 = " << p.second[1] << ", c2 = " << p.second[2] << endl;
        // cout << p.first << "=" << elem_cost << endl;
        sum += elem_cost;
    }
    return sum;
}

bool dfs(vector<vector<int>>& g, int b, int t, vector<bool>& todo, vector<int>& p) 
{
    if (todo[b]) {
        return false;
    }
    if (b == t) {
        p.push_back(t);
        return true;
    }
    todo[b] = true;
    p.push_back(b);
    for (auto v : g[b] ) {
        if(dfs(g, v, t, todo, p)) {
            return true;
        };
    }
    p.pop_back();
    todo[b] = false;
    return false;
}

int main(void)
{
    {
        int n = 4;
        vector<std::vector<int>> paths = {{1,2,3,5}, {1,3,2,4}, {2,4,1,3}};
        cout << minimumCostInTree(n, paths) << endl;
    }

    {
        auto start = std::chrono::system_clock::now();
        int n = 100;
        vector<std::vector<int>> paths = {{13,2,719,755},{2,10,3,45},{10,99,31,750},{13,97,18,309},{13,28,5,318},{97,59,45,93},{10,83,9,893},{28,87,364,925},{83,91,559,700},{28,19,310,795},{13,63,832,919},{99,33,88,859},{2,41,765,774},{63,72,59,206},{28,52,18,689},{41,92,24,237},{33,42,191,618},{63,95,38,264},{97,18,299,386},{97,9,24,911},{9,48,158,654},{33,65,192,265},{65,67,80,538},{28,66,116,801},{66,8,41,99},{63,7,33,87},{97,77,18,76},{52,6,396,824},{83,100,533,816},{48,78,4,829},{52,82,151,834},{48,55,31,86},{55,36,20,847},{8,57,849,909},{52,40,424,754},{28,26,71,190},{19,4,15,168},{4,88,1,814},{19,17,32,320},{4,62,78,817},{8,69,286,362},{57,15,25,145},{57,14,306,930},{66,25,363,912},{4,56,18,47},{18,98,234,331},{10,20,704,742},{41,21,191,505},{97,60,499,1000},{95,76,302,611},{41,34,450,947},{92,22,217,336},{78,29,46,61},{77,79,157,715},{18,16,160,975},{82,51,142,676},{56,35,80,142},{9,37,21,985},{9,45,184,233},{16,84,238,772},{29,39,115,937},{92,47,298,472},{10,61,464,935},{92,85,493,991},{88,96,99,184},{39,58,575,957},{37,23,597,797},{36,38,355,458},{91,24,437,627},{58,71,258,406},{79,90,401,607},{78,32,238,658},{23,80,13,34},{29,74,46,67},{92,93,147,790},{93,12,355,410},{51,3,22,880},{16,89,146,976},{99,43,37,377},{20,31,477,975},{100,53,307,635},{66,73,545,609},{21,54,95,294},{35,68,211,280},{36,30,12,22},{20,86,394,758},{26,44,183,331},{4,75,225,803},{41,70,186,293},{91,46,12,502},{67,27,73,768},{83,94,69,920},{27,11,51,138},{80,49,19,56},{52,81,392,800},{81,1,148,640},{19,64,124,439},{39,50,493,987},{95,5,42,141}};
        cout << minimumCostInTree(n, paths) << endl;

        std::chrono::duration<double> dur= std::chrono::system_clock::now() - start;
        std::cout << "time native: " << dur.count() << " seconds" << std::endl;

    }

}
