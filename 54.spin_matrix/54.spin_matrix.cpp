#include "common.h"
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        // right, down, left, up
        vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int currentRow = 0;
        int currentCol = 0;
        int length = row * col;
        int directionIndex = 0;
        vector<int> ans;
        for(int i = 0; i < length; i ++) {
            ans.push_back(matrix[currentRow][currentCol]);
            visited[currentRow][currentCol] = true;
            int nextRow = currentRow + direction[directionIndex][0];
            int nextCol = currentCol + direction[directionIndex][1];
            if(nextRow < 0 || nextRow == row || nextCol < 0 || nextCol == col || visited[nextRow][nextCol])
                directionIndex = (directionIndex + 1) % 4;
            currentRow += direction[directionIndex][0];
            currentCol += direction[directionIndex][1];
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    solution.spiralOrder(matrix);
}