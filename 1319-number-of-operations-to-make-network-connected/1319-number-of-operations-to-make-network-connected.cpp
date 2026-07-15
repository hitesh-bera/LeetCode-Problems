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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if (m < (n - 1))
            return -1;
        size.assign(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        int component = n;
        for (int i = 0; i < m; i++) {
            auto edge = connections[i];
            int u = edge[0];
            int v = edge[1];

            if (Union(u, v)) {
                component--;
            }
        }
        return component - 1;
    }
};