class Solution {
public:
    vector<int> parent, rnk;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    void unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return;
        // union by rank
        if (rnk[ra] < rnk[rb]) swap(ra, rb);
        parent[rb] = ra;
        if (rnk[ra] == rnk[rb]) rnk[ra]++;
    }

    int removeStones(vector<vector<int>>& stones) {
        // Rows: 0..9999, Cols offset by 10000 -> 10000..19999
        const int OFFSET = 10001;
        parent.resize(20002);
        rnk.assign(20002, 0);
        for (int i = 0; i < 20002; i++) parent[i] = i;

        unordered_set<int> activeNodes; // track which row/col nodes are actually used

        for (auto& st : stones) {
            int row = st[0];
            int col = st[1] + OFFSET;
            unite(row, col);
            activeNodes.insert(row);
            activeNodes.insert(col);
        }

        unordered_set<int> roots;
        for (int node : activeNodes)
            roots.insert(find(node));

        int components = roots.size();
        return (int)stones.size() - components;
    }
};

/*
class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v)
            return;

        if (size[u] < size[v])
            swap(u, v);

        parent[v] = u;
        size[u] += size[v];
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();

        DSU dsu(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1])
                {
                    dsu.unite(i, j);
                }
            }
        }

        int components = 0;

        for (int i = 0; i < n; i++)
        {
            if (dsu.find(i) == i)
                components++;
        }

        return n - components;
    }
};
*/