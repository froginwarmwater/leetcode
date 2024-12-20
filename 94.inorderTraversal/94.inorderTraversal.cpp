#include<vector>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

class Solution {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        subInorderTraversal(root);
        return ans;
    }
    void subInorderTraversal(TreeNode* root) {
        if(root == nullptr) return;
        subInorderTraversal(root->left);
        ans.push_back(root->val);
        subInorderTraversal(root->right);
    }
};