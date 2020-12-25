/*
- Problem:
- Solution:
  - Straight forward diagonal scan
```
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]

 [1,2,4,7,5,3,6,8,9]
```

*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> diagonalTraverse(vector<vector<int>> matrix)
{
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return {};
    }

    bool up = true;
    int i = 0, j = 0;
    vector<int> res = {};
        
    int row = matrix.size()-1;
    int col = matrix[0].size()-1;

    while (true) {
        res.push_back(matrix[i][j]);
        if (i == row && j == col) {
            break;
        }

        if (up) {
            i--, j++;
            if (i < 0 || j < 0 || i > row || j > col) {
                up = !up;
                if (i < 0) {
                    if (j <= col) {
                        i = 0;
                    } else {
                        i += 2;
                        j = col;
                    }
                } else {
                    i += 2;
                    j = col;
                }
            }
        } else {
            i++, j--;
            if (i < 0 || j < 0 || i > row || j > col) {
                up = !up;
                if (j < 0) {
                    if (i <= row) {
                        j = 0;
                    } else {
                        j += 2;
                        i = row;
                    }
                } else {
                    j += 2;
                    i = row;
                }
                
            }
        }
    }
        
    return res;
}

int main(void)
{
    vector<vector<int>> arr = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    vector<int> res = diagonalTraverse(arr);
    for (auto it : res) {
        cout << it << ",";
    }
    cout << endl;
}
