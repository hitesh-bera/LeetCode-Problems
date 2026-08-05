/*
class DSU {
    public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        size.assign(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int u) {
        if (parent[u] == u)
            return parent[u];
        return parent[u] = findParent(parent[u]);
    }

    void unite(int u, int v) {
        int parentU = findParent(u);
        int parentV = findParent(v);

        if (parentU == parentV) {
            return;
        }

        if (size[parentU] < size[parentV]) {
            size[parentV] += size[parentU];
            parent[parentU] = parentV;
        } else {
            size[parentU] += size[parentV];
            parent[parentV] = parentU;
        }
        return;
    }

    int setSize(int u) {
        int prnt = findParent(u);
        return size[prnt];
    }
};
class Solution {
public:
    int numberOfSuspicious(int node, vector<bool>& vis,
                           vector<vector<int>> adj) {
        queue<int> q;

        q.push(node);
        vis[node] = true;

        int cnt = 0;

        while (!q.empty()) {
            int top = q.front();
            q.pop();

            cnt++;

            for (int neibr : adj[top]) {
                if (!vis[neibr]) {
                    q.push(neibr);
                    vis[neibr] = true;
                }
            }
        }
        return cnt;
    }
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        DSU dsu(n);
        for (const auto& invocation : invocations) {
            int u = invocation[0];
            int v = invocation[1];

            adj[u].push_back(v);
            dsu.unite(u, v);
        }

        vector<bool> vis(n, false);
        int totalSuspicious = numberOfSuspicious(k, vis, adj);

        int componentSize = dsu.setSize(k);

        vector<int> ans;

        if (totalSuspicious == componentSize) {
            for (int i = 0; i < n; i++) {
                if (!vis[i])
                    ans.push_back(i);
            }
        } else {
            for (int i = 0; i < n; i++)
                ans.push_back(i);
        }
        return ans;
    }
};
*/
class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for (const auto& invocation : invocations) {
            int u = invocation[0];
            int v = invocation[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        q.push(k);

        unordered_set<int> susp;

        while (!q.empty()) {
            int top = q.front();
            q.pop();

            susp.insert(top);

            for (int neibr : adj[top]) {
                indegree[neibr]--;

                if (!susp.count(neibr)) {
                    q.push(neibr);
                    susp.insert(neibr);
                }
            }
        }

        vector<int>remainingMethods;
        bool removePossible = true;

        for (int i = 0; i < n; i++) {
            if (susp.count(i) && indegree[i] > 0) {
                removePossible = false;
                break;
            } else if (!susp.count(i)) {
                remainingMethods.push_back(i);
            }
        }

        if (!removePossible) {
            remainingMethods.clear();
            for (int i = 0; i < n; i++) {
                remainingMethods.push_back(i);
            }
        }
        return remainingMethods;
    }
};