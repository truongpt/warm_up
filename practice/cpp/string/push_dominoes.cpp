/*
- Problem:


. L . R . . . L R . . L . .
0 1 2 3 4 5 6 7 8 9 

*/

#include <iostream>
#include <string>
#include<stack>

std::string pushDominoes(std::string dominoes) {
  int last_right = -1;
  std::string result{};

  for (int i = 0; i < dominoes.length(); i++) {
    if ('L' == dominoes[i]) {
      if (-1 == last_right) {
        int cur = result.length()-1;
        int add = i - cur;
        result.insert(result.end(), add, 'L');
      } else {
        int bettwen = i - last_right - 1;
        int add = bettwen/2 + 1;

        std::string b = bettwen % 2 ? "." : "";
        result.insert(result.end(), add, 'R');
        result += b;
        result.insert(result.end(), add, 'L');
        last_right = -1;
      }
    } else if ('R' == dominoes[i]) {
      if (last_right == -1) {
        int cur = result.length()-1;
        int add = i - cur - 1;

        result.insert(result.end(), add, '.');        
        last_right = i;
      } else {
        result.insert(result.end(), i - last_right, 'R');
        last_right = i;
      }
    }
  }

  int add = dominoes.length() - result.length();
  if (last_right == -1) {
    result.insert(result.end(),add, '.');
  } else {
    result.insert(result.end(), add, 'R');
  }

  return result;

}

int main(void) {
  std::string dominoes = ".L.R...LR..L..";
  auto result = pushDominoes(dominoes);
  if (result.length() != dominoes.length()) {
    std::cout << "Fail: " << result << std::endl;
    return -1;
  }
  std::cout << result << std::endl;
  return 0;
}
