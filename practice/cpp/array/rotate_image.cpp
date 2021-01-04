/*
- Problem: https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/770/
- Solution:
input
[[1,2,3],
 [4,5,6],
 [7,8,9]]

flip by diagonal
j >= i
swap(a[i][j], a[j][i])

[[1,4,7],
 [2,5,8],
 [3,6,9]]


flip by center vertical
j <= N/2
swap(a[i][j], a[i][N-j])

output
[[7,4,1],
 [8,5,2],
 [9,6,3]]

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<vector<int>>& matrix)
{
    int N = matrix.size();
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N/2; j++) {
            swap(matrix[i][j], matrix[i][N-1-j]);
        }
    }
}

int main(void)
{

}
