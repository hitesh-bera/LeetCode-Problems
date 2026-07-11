class Solution {
public:
    vector<vector<int>>adj;
    vector<int>visited;
    int n;
    vector<int> bfs(int node){
        visited[node]=1;
        queue<int>q;
        q.push(node);
        vector<int>ans;
        ans.push_back(node);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v:adj[u]){
                if(!visited[v]){
                    q.push(v);
                    ans.push_back(v);
                    visited[v]=1;
                }
            }
        }
        return ans;
    }
    int countCompleteComponents(int nodes, vector<vector<int>>& edges) {
        n = nodes;
        adj.resize(n);
        visited.assign(n,0);
        for(auto it:edges){
            int u = it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                vector<int>elements_in_component = bfs(i);
                bool flag = true;
                for(auto ele : elements_in_component){
                    if(elements_in_component.size() - 1 != adj[ele].size()){
                        flag = false;
                        break;
                    }
                }
                if(flag)cnt++;
            }
        }
        return cnt;
    }
};