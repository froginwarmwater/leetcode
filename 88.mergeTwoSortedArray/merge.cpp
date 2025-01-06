#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> answerArray;
        int largest = m + n;
        int point1 = 0;
        int point2 = 0;
        while(point1 < m &&  point2 < n) {
            if (nums1[point1] <= nums2[point2]) {
                answerArray.push_back(nums1[point1]);
                point1 ++;
            } else {
                answerArray.push_back(nums2[point2]);
                point2 ++;
            }
        }
        while(point2 < n) {
                answerArray.push_back(nums2[point2]);
                point2 ++;
        }
        while(point1 < m) {
                answerArray.push_back(nums1[point1]);
                point1 ++;
        }
        nums1 = answerArray;
    }
};

int main() {
    Solution solution;
    
    // 测试用例 1
    vector<int> nums1 = {1, 2, 3, 0, 0, 0}; // nums1 的实际内容
    int m = 3; // nums1 的有效长度
    vector<int> nums2 = {2, 5, 6}; // nums2 的内容
    int n = 3; // nums2 的长度
    solution.merge(nums1, m, nums2, n);
    cout << "Test Case 1 Result: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;
}