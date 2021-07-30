/*
- Problem: https://leetcode.com/problems/map-sum-pairs
*/

#include <iostream>
#include <unordered_map>
#include <string>

class MapSum {
public:
  MapSum() {
    prefix_m_.clear();
    original_m_.clear();
  }
  void insert(std::string key, int val) {
    int add = val;
    if (original_m_.find(key) != original_m_.end()) {
      add -= original_m_[key];
    }
    original_m_[key] = val;

    for (int i = 0; i <= key.length(); i++) {
      std::string prefix = key.substr(0,i);
      prefix_m_[prefix] += add;
    }
  }

  int sum(std::string prefix) {
    return prefix_m_[prefix];
  }

private:
  std::unordered_map<std::string, int> prefix_m_;
  std::unordered_map<std::string, int> original_m_;
};


int main(void) {
  auto* map_sum = new MapSum();
  map_sum->insert("apple",5);
  std::cout << map_sum->sum("app") << std::endl;
  map_sum->insert("app",3);
  std::cout << map_sum->sum("app") << std::endl;
}
