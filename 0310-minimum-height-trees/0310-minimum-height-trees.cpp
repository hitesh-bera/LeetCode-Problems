class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 0){
            return {};
        }else if(n == 1){
            return {0};
        }
        vector<vector<int>>adj(n);
        vector<int>degree(n,0);
        for(const auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(degree[i] == 1){
                q.push(i);
            }
        }

        vector<int>level;
        while(!q.empty()){
            level.clear();
            int curSize = q.size();
            for(int i=0;i<curSize;i++){
                int top = q.front();
                q.pop();
                level.push_back(top);
                for(int neibr : adj[top]){
                    degree[neibr]--;
                    if(degree[neibr] == 1){
                        q.push(neibr);
                    }
                }
            }
        }
        return level;
    }
};