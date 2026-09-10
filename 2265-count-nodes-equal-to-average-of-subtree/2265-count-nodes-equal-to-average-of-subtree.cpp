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
pair<int,int> f(TreeNode* root, int &ans){
    if(root == nullptr)return {0,0};
    if(root->left == nullptr && root->right == nullptr){
        ans++;
        return {root->val, 1};
    }

    pair<int,int>left = f(root->left, ans);
    pair<int,int>right = f(root->right, ans);

    int treeSum = (root->val + left.first + right.first);
    int nodes = (1 + left.second + right.second);
    if(treeSum/nodes == root->val)ans++;
    return {treeSum, nodes};

}
    int averageOfSubtree(TreeNode* root) {
        if(root == nullptr)return 0;

        int ans = 0;
        pair<int,int>temp = f(root, ans);
        return ans;
    }
};