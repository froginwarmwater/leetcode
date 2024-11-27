#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int temp;
        int row = matrix.size();
        if (row == 1) {
            return;
        }
        int col = matrix[0].size();
        for(int i = 0; i < row; i ++) {
            for(int j = i; j < col; j ++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for(int i = 0; i < row; i ++) {
            for(int j = 0; j < col / 2; j ++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[i][col - j];
                matrix[i][col - j] = temp;
            }
        }
    }
};