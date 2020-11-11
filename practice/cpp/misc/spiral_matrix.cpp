// problem: https://leetcode.com/problems/spiral-matrix/solution/


#include <iostream>
#include <vector>
using namespace std;


/*
  - My solution.
  - Đơn giản scan theo đúng thứ tự xoắn ốc: right -> down -> left -> up -> right ...
  - Đến mỗi điểm tới hạn thì update lại trạng thái của matrix.
  - Hạn chế
  - Code trông khá stupid
  - Có vẻ cân nhắc hơi lâu khi code
*/

vector<int> spiralOrder(vector<vector<int>>& matrix)
{        
    if (matrix.empty() || matrix[0].empty()) {
        return {};
    }
    int start_x = 0, start_y = 0, end_x = matrix.size()-1, end_y =  matrix[0].size() - 1;

    vector<int> res;
    int j, i;
    while (true) {

        i = start_x;
        for (j = start_y; j <= end_y; j++) {
            res.push_back(matrix[i][j]);
        }
        // update size
        start_x++;
        if (start_x > end_x || start_y > end_y) {
            break;
        }

        j = end_y;
        for (i = start_x; i <= end_x; i++) {
            res.push_back(matrix[i][j]);
        }
        end_y--;
        if (start_x > end_x || start_y > end_y) {
            break;
        }
        i = end_x;
        for (j = end_y; j >= start_y; j--) {
            res.push_back(matrix[i][j]);
        }
        end_x--;
 
        if (start_x > end_x || start_y > end_y) {
            break;
        }
 
        j = start_y;
        for (i = end_x; i >= start_x; i--) {
            res.push_back(matrix[i][j]);
        }
        start_y++;
    } 
    return res;
}



int main(void)
{
    vector<vector<int>> matrix = {{1, 2, 3, 4},{5, 6, 7, 8},{9,10,11,12}};

    vector<int> res = spiralOrder(matrix);
    for (auto it : res) {
        cout << it << ",";

    }
    cout << endl;
}
