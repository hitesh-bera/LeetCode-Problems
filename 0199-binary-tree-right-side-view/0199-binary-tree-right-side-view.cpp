/*
//1.
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        vector<int> rightSide;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* top = q.front();
                q.pop();

                if (top->left != nullptr) {
                    q.push(top->left);
                }
                if (top->right != nullptr) {
                    q.push(top->right);
                }

                if (i == size - 1) {
                    rightSide.push_back(top->val);
                }
            }
        }

        return rightSide;
    }
};
*/

// 2.
class Solution {
public:
    void dfs(TreeNode* root, int level, vector<int>&rightSide){
        if(root == nullptr)return;

        if(level == rightSide.size() + 1){
            rightSide.push_back(root->val);
        }

        dfs(root->right, level+1, rightSide);
        dfs(root->left, level+1, rightSide);

    }
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        vector<int> rightSide;

        dfs(root, 1, rightSide);

        return rightSide;
    }
};