class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>adj(n);
        vector<int>in(n,0);
        for(int v=0;v<n;v++){
            for(int u : graph[v]){
                adj[u].push_back(v);
                in[v]++;
            }
        }

        queue<int>q;
        vector<int>safeNodes;

        for(int i=0;i<n;i++){
            if(in[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int top = q.front();
            q.pop();

            safeNodes.push_back(top);

            for(int neibr : adj[top]){
                in[neibr]--;

                if(in[neibr] == 0){
                    q.push(neibr);
                }
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};