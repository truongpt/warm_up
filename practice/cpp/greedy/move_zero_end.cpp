#include <iostream>
#include <vector>

using namespace std;

vector<int> moveZerosToEnd1(const vector<int>& a)
{
  vector<int> arr = a;
	
  int zero_pos = -1;
  for (int i = 0; i < arr.size(); i++) {
    if (-1 == zero_pos && 0 == arr[i]) {
      zero_pos = i;
    }
    
    if (-1 != zero_pos && arr[i]) {
      swap(arr[zero_pos], arr[i]);
      zero_pos++;
    }
  }

  return arr;
}


vector<int> moveZerosToEnd(const vector<int>& a)
{
  vector<int> arr = a;

  int w = 0;
  for (int i = 0; i < arr.size(); i++) {
      if (arr[i] != 0) {
          arr[w] = arr[i];
          w++;
      }
  }

  for (int i = w; i < arr.size(); i++) {
      arr[i] = 0;
  }

  return arr;
}

int main() 
{
  vector<int> res = moveZerosToEnd({1, 10, 0, 2, 8, 3, 0, 0, 6, 4, 0, 5, 7, 0});
  
  for (auto it : res) {
    cout << it << ",";
  }
  cout << endl;
	return 0;
}
