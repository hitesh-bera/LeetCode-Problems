
class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int node, vector<int>& color) {
        for (int neibr : adj[node]) {
            if (color[neibr] == -1) {
                color[neibr] = 1 - color[node];
                if (!dfs(adj, neibr, color))
                    return false;
            } else if (color[neibr] == color[node]) {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                color[i] = 0;
                if (!dfs(adj, i, color))
                    return false;
            }
        }
        return true;
    }
};