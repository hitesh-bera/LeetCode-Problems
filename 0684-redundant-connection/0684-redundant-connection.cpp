class Solution {
public:
    vector<int> size;
    vector<int> parent;
    int findparent(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = findparent(parent[u]);
    }
    bool Union(int u, int v) {
        int pu = findparent(u);
        int pv = findparent(v);

        if (pu == pv)
            return false;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        size.assign(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            auto edge = edges[i];
            int u = edge[0];
            int v = edge[1];

            if(!Union(u, v)){
                ans = edge;
                break;
            }
        }
        return ans;
    }
};

/*
class Solution {
public:
    bool dfs(int u, int parent, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) {
                if (dfs(v, u, adj, vis))
                    return true;
            } else if (v != parent)
                return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        vector<int> ans;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            vector<bool> vis(n + 1, false);
            if (dfs(u, -1, adj, vis)) {
                ans = edge;
                break;
            }
        }
        return ans;
    }
};
*/