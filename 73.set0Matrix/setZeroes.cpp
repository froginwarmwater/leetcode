#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        set<int> setRowPos;
        set<int> setColPos;
        for(int i = 0; i < row; i ++) {
            for(int j = 0; j < col; j ++) {
                if(matrix[i][j] == 0) {
                    setRowPos.insert(i);
                    setColPos.insert(j);
                }
            }
        }
        for(int i = 0; i < row; i ++) {
            for(int j = 0; j < col; j ++) {
                if(setRowPos.count(i) > 0 || setColPos.count(j) > 0 ) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};