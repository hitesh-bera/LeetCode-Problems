/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool f(TreeNode* root, int target, int curSum) {
        if (root->left == nullptr && root->right == nullptr) {
            return target == curSum;
        }
        bool ans = false;
        if(root -> left != nullptr){
            ans = ans || f(root->left, target, curSum + root->left->val);
        }
        if(root -> right != nullptr){
            ans = ans || f(root->right, target, curSum + root->right->val);
        }
        return ans;
    }
    bool hasPathSum(TreeNode* root, int target) {
        if (root == nullptr)
            return false;
        return f(root, target, root->val);
    }
};