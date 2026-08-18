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

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)return root;

        Node* curLevelPtr = root;

        while(curLevelPtr != nullptr){ 
            Node dummy(0);
            Node* nextLevelPtr = &dummy;

            while(curLevelPtr != nullptr){
                if(curLevelPtr -> left != nullptr){
                    nextLevelPtr->next = curLevelPtr -> left;
                    nextLevelPtr = nextLevelPtr->next;
                }
                if(curLevelPtr -> right != nullptr){
                    nextLevelPtr->next = curLevelPtr -> right;
                    nextLevelPtr = nextLevelPtr->next;
                }
                curLevelPtr = curLevelPtr -> next;
            }
            curLevelPtr = dummy.next;
        }
        return root;
    }
};