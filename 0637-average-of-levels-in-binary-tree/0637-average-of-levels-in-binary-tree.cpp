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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == nullptr)return {};

        queue<TreeNode*>q;
        q.push(root);

        vector<double>avg;
        long long sum = 0;
        int size;
        TreeNode* top;

        while(!q.empty()){
            size = q.size();
            sum = 0;
            for(int i=0;i<size;i++){
                top = q.front();
                q.pop();

                sum += top->val;

                if(top->left != nullptr)q.push(top->left);
                if(top->right != nullptr)q.push(top->right);
            }
            avg.push_back((1.00000*sum) / size);
        }
        return avg;
    }
};