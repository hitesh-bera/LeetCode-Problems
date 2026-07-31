
// class Solution {
// public:
//     bool dfs(vector<vector<int>>& adj, int node, vector<int>& color) {
//         for (int neibr : adj[node]) {
//             if (color[neibr] == -1) {
//                 color[neibr] = 1 - color[node];
//                 if (!dfs(adj, neibr, color))
//                     return false;
//             } else if (color[neibr] == color[node]) {
//                 return false;
//             }
//         }
//         return true;
//     }
//     bool isBipartite(vector<vector<int>>& adj) {
//         int n = adj.size();
//         vector<int> color(n, -1);
//         for (int i = 0; i < n; i++) {
//             if (color[i] == -1) {
//                 color[i] = 0;
//                 if (!dfs(adj, i, color))
//                     return false;
//             }
//         }
//         return true;
//     }
// };

class DSU {
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1); // Every node starts as a tree of size 1
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // Path Compression
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // Attach smaller tree to larger tree (Union by Size)
            if (size[rootX] < size[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            } else {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        }
    }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        DSU dsu(n);

        for (int node = 0; node < n; node++) {
            for (int neibr : adj[node]) {
                // If node and neighbor are in the same set -> odd cycle found!
                if (dsu.find(node) == dsu.find(neibr)) {
                    return false;
                }
                // Group all neighbors of 'node' into the same component
                dsu.unite(adj[node][0], neibr);
            }
        }
        return true;
    }
};