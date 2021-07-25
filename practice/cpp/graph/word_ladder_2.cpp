/* 
- Problem: https://leetcode.com/problems/word-ladder-ii/
*/
#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

void dfs(std::unordered_map<std::string, std::vector<std::string>>& word_map,
         int cur_level, int max_level,
         std::vector<std::vector<std::string>>& result,
         std::vector<std::string> cur, std::string begin_word, std::string end_word) {
    if (++cur_level > max_level) {
        return;
    }

    cur.push_back(begin_word);

    if (begin_word == end_word) {
        result.push_back(cur);
        return;
    }

    for (auto word : word_map[begin_word]) {
        dfs(word_map, cur_level, max_level, result, cur, word, end_word);
    }

}

std::vector<std::vector<std::string>> findLadders(
    std::string begin_word,
    std::string end_word,
    std::vector<std::string>& word_list) {

    std::unordered_set<std::string> word_set;
    std::unordered_map<std::string, int> word_level;
    for (auto word : word_list) {
        word_set.insert(word);
    }

    if (word_set.find(end_word) == word_set.end()) {
        return {};
    }

    std::queue<std::string> q{};
    q.push(begin_word);
    int level = 0;

    std::unordered_map<std::string, std::vector<std::string>> word_map{};
    word_level[begin_word] = 0;
    while (!q.empty()) {
        int n = q.size();
        level++;
            
        int exit =  false;
        for (int k = 0; k < n; k++) {
            std::string cur_word = q.front();
                
            q.pop();
            if (cur_word == end_word) {
                exit = true;
                break;
            }
        
            for (int i = 0; i < cur_word.length(); i++) {
                auto next_word = cur_word;
                for (int j = 0; j < 26; j++) {
                    next_word[i] = 'a' + j;
                    if (word_set.find(next_word) != word_set.end() && 
                        (word_level.find(next_word) == word_level.end() ||
                         word_level[next_word] == word_level[cur_word]+1 )) {
                        if (word_level.find(next_word) == word_level.end()) {
                            q.push(next_word);
                        }
                        word_level[next_word] = word_level[cur_word]+1;
                        word_map[cur_word].push_back(next_word);
                    }
                }
            }
        }
        if (exit) {
            break;
        }
    }

    std::vector<std::vector<std::string>> result{};
    std::vector<std::string> cur{};
    dfs(word_map, 0, level, result, cur, begin_word, end_word);

    return result;        
} 


int main(void) {

    std::vector<std::string> word_list = {"hot","dot","dog","lot","log","cog"};
    auto result = findLadders("hit", "cog", word_list);
    for (auto words : result) {
        for (auto word : words) {
            std::cout << word << ",";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
