#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> tempBoard;
        int row = board.size();
        if (row == 0) {
            return;
        }
        int col = board[0].size();
        vector<vector<int>> offset = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
        for (int i = 0; i < row; i ++) {
            vector<int> rowTempBoard;
            for (int j = 0; j < col; j ++) {
                vector<int> otherCell;
                for (auto item: offset) {
                    int x = i + item[0];
                    int y = j + item[1];
                    if (x >= 0 && x < row && y >= 0 && y < col) {
                        otherCell.push_back(board[x][y]);
                    }
                }
                int thisAlive = jugder(otherCell, board[i][j]);
                rowTempBoard.push_back(thisAlive);
            }
                tempBoard.push_back(rowTempBoard);
        }
        board = tempBoard;
    }
    int jugder(vector<int> otherCell, int isAlive) {
        int alive = 0;
        int dead = 0;
        for (int i =0; i < otherCell.size(); i ++) {
            if (otherCell[i] == 1) {
                alive ++;
                continue;
            }
            dead ++;
        }
        if ((alive < 2 || alive > 3) && isAlive == 1) {
            return false;
        }
        if ((alive == 2 || alive == 3) && isAlive == 1) {
            return true;
        }
        if ((alive == 3) && isAlive == 0) {
            return true;
        }
        return isAlive;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> tempBoard = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    solution.gameOfLife(tempBoard);
    int row = tempBoard.size();
    int col = tempBoard[0].size();
    for(int i = 0; i < row; i ++) {
        for (int j = 0; j < col; j ++) {
            cout << tempBoard[i][j] << " ";
        }
        cout << endl;
    }
}