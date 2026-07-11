class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis;

    bool bfs(int start) {
        queue<int> q;
        q.push(start);
        vis[start] = 1;

        int nodes = 0;
        int degreeSum = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            nodes++;
            degreeSum += adj[u].size();

            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        return degreeSum == nodes * (nodes - 1);
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.assign(n, {});
        vis.assign(n, 0);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i] && bfs(i))
                ans++;
        }

        return ans;
    }
};

// class Solution {
// public:
//     vector<vector<int>>adj;
//     vector<int>visited;
//     int n;
//     vector<int> bfs(int node){
//         visited[node]=1;
//         queue<int>q;
//         q.push(node);
//         vector<int>ans;
//         ans.push_back(node);
//         while(!q.empty()){
//             int u = q.front();
//             q.pop();
//             for(auto v:adj[u]){
//                 if(!visited[v]){
//                     q.push(v);
//                     ans.push_back(v);
//                     visited[v]=1;
//                 }
//             }
//         }
//         return ans;
//     }
//     int countCompleteComponents(int nodes, vector<vector<int>>& edges) {
//         n = nodes;
//         adj.resize(n);
//         visited.assign(n,0);
//         for(auto it:edges){
//             int u = it[0],v=it[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         int cnt=0;
//         for(int i=0;i<n;i++){
//             if(!visited[i]){
//                 vector<int>elements_in_component = bfs(i);
//                 bool flag = true;
//                 for(auto ele : elements_in_component){
//                     if(elements_in_component.size() - 1 != adj[ele].size()){
//                         flag = false;
//                         break;
//                     }
//                 }
//                 if(flag)cnt++;
//             }
//         }
//         return cnt;
//     }
// };