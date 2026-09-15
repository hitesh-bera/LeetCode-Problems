/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int f(TreeNode* root, int& maxSum){
        if(root == nullptr)return 0;
        int left = f(root->left, maxSum);
        int right = f(root->right, maxSum);
        maxSum = max({maxSum, root->val+left, root->val+right, root->val+left+right,root->val});
        return max({0, root->val, root->val+left, root->val+right});
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int temp = f(root, maxSum);
        return maxSum;
    }
};