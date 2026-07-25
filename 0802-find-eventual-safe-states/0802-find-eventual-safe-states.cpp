class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reversedAdj(n);
        vector<int> indegree(n, 0);

        // Build reversed graph and set in-degrees
        for (int v = 0; v < n; v++) {
            for (int u : graph[v]) {
                reversedAdj[u].push_back(v); // Reverse edge: u -> v
            }
            indegree[v] = graph[v].size(); // Terminal nodes will have indegree == 0
        }

        queue<int> q;
        vector<bool> isSafe(n, false);

        // Push all terminal nodes (indegree == 0 in reversed graph)
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Process queue (Kahn's algorithm)
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            isSafe[curr] = true;

            for (int neighbor : reversedAdj[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Collect safe nodes in ascending order without sorting
        vector<int> safeNodes;
        for (int i = 0; i < n; i++) {
            if (isSafe[i]) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};