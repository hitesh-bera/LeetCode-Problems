class Solution {
private:
    void dfs(vector<vector<int>>& isConnected, int node, vector<int>& visited) {
        int n = isConnected.size();
        visited[node] = 1;

        for (int j = 0; j < n; j++) {
            if (isConnected[node][j] == 1 && !visited[j]) {
                dfs(isConnected, j, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(isConnected, i, visited);
            }
        }
        return count;
    }
};
