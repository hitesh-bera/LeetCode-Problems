/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> maping;
    Node* bfs(Node* st){
        queue<Node*>q;
 
        q.push(st);
        maping[st] = new Node(st->val);

        while(!q.empty()){
            Node* top = q.front();
            q.pop();

            for(auto adj : top->neighbors){
                if(!maping.count(adj)){
                    q.push(adj);
                    Node* newnode = new Node(adj->val);
                    maping[adj] = newnode;
                }
                maping[top]->neighbors.push_back(maping[adj]);
            }
        }
        return maping[st];
    }
    Node* cloneGraph(Node* node) {
        if(node == nullptr)return node;
        return bfs(node);
    }
};