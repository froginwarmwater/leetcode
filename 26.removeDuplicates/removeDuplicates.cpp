#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int currentNumber = nums[0];
        int point = 1;
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] == currentNumber) {
                continue;
            }
            currentNumber = nums[i];
            nums[point] = nums[i];
            point ++;
        }
    }
};