class Solution {
public:
    void dfs(int u,vector<vector<int>> adj,vector<int>& visited){
        visited[u] = 1;
        for(int i=0;i<adj.size();i++){
            if(adj[u][i] && !visited[i])dfs(i,adj,visited);
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int>visited(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                dfs(i,adj,visited);
            }
        }
        return cnt;
    }
};