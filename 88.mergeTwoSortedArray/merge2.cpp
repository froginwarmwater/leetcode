#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int lastPoint = nums1.size() - 1;
        m = m - 1;
        n = n - 1;
        while(m >= 0 && n >= 0) {
            if(nums1[m] > nums2[n]) {
                nums1[lastPoint] = nums1[m];
                m --;
                lastPoint --;
            }
            else {
                nums1[lastPoint] = nums2[n];
                n --;
                lastPoint --;
            }
        }
        while (m >= 0) {
            nums1[lastPoint] = nums1[m];
            m --;
            lastPoint --;
        }
        while (n >= 0) {
            nums1[lastPoint] = nums2[n];
            n --;
            lastPoint --;
        }

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