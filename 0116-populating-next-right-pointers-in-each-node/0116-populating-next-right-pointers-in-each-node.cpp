/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

/*
//1. level order trversal
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)return root;
        queue<Node*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            Node* prev = nullptr;
            for(int i=0;i<size;i++){
                Node* cur = q.front();
                q.pop();

                if(prev != nullptr){
                    prev->next = cur;
                }
                prev = cur;
                if(cur -> left != nullptr){
                    q.push(cur->left);
                }
                if(cur->right != nullptr){
                    q.push(cur->right);
                }
            }
            prev->next == nullptr;
        }
        return root;
    }
};
*/

// 2. space optimization.
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return root;

        Node* leftMost = root;

        while (leftMost->left != nullptr) {
            Node* cur = leftMost;
            while (cur != nullptr) {
                cur->left->next = cur->right;

                if (cur->next != nullptr) {
                    cur->right->next = cur->next->left;
                }

                cur = cur->next;
            }
            leftMost = leftMost -> left;
        }
        return root;
    }
};