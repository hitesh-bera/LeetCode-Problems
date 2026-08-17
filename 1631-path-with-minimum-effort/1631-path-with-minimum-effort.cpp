/*
//priority queue approach
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        vector<vector<int>>dis(row, vector<int>(col, INT_MAX)); //min effort
req. to reach (r,c) from (0,0) priority_queue<tuple<int,int,int>,
vector<tuple<int,int,int>>, greater<tuple<int,int,int>>>pq;

        pq.push({0,0,0});
        dis[0][0] = 0;

        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};

        while(!pq.empty()){
            auto [effort, r, c] = pq.top();
            pq.pop();

            for(int k=0;k<4;k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >= 0 && nr < row && nc >= 0 && nc < col){
                    int wt = abs(heights[r][c] - heights[nr][nc]);
                    int nextEffort = max(effort, wt);

                    if(nextEffort < dis[nr][nc]){
                        dis[nr][nc] = nextEffort;
                        pq.push({nextEffort, nr, nc});
                    }
                }
            }
        }
        return dis[row-1][col-1];
    }
};
*/

/*
//2. we can solve this using DSU approach with sorted edge list;
class DSU{
    public:
    vector<int>parent;
    vector<int>size;

    DSU(int n){
        size.assign(n, 1);
        parent.resize(n);
        for(int i=0;i<n;i++)parent[i] = i;
    }

    int findParent(int u){
        if(parent[u] == u)return u;
        return parent[u] = findParent(parent[u]);
    }

    void unite(int u, int v){ //true if they are in same component
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv)return ;

        if(size[pu] > size[pv]){
            size[pu] += size[pv];
            parent[pv] = pu;
        }else{
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        return;
    }

    bool isSameComponent(int u, int v){
        return findParent(u) == findParent(v);
    }
};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        vector<array<int, 3>>edges;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int u = i*col + j;
                int v, wt;
                if(i + 1 < row){
                    v = (i+1) * col + j;
                    wt = abs(heights[i][j] - heights[i+1][j]);
                    edges.push_back({wt, u, v});
                }
                if(j+1 < col){
                    v = i * col + j + 1;
                    wt = abs(heights[i][j] - heights[i][j+1]);
                    edges.push_back({wt, u, v});
                }
            }
        }
        sort(edges.begin(), edges.end());

        DSU dsu(row*col);
        for(const auto [wt, u, v] : edges){
            dsu.unite(u, v);
            if(dsu.isSameComponent(0, row*col - 1)){
                return wt;
            }
        }
        return 0;
    }
};
*/

// 3. binary search + BDF or DFS on height difference.
class Solution {
public:
    int row;
    int col;
    static constexpr int dr[4] = {1, 0, -1, 0};
    static constexpr int dc[4] = {0, 1, 0, -1};

    bool isvalid(int d, vector<vector<int>>& heights) {
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(row, vector<bool>(col, false));
        q.push({0, 0});
        vis[0][0] = true;

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            int r = p.first;
            int c = p.second;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
                    !vis[nr][nc]) {
                    int wt = abs(heights[r][c] - heights[nr][nc]);
                    if (wt <= d) {
                        if (nr == row - 1 && nc == col - 1)
                            return true;
                        q.push({nr, nc});
                        vis[nr][nc] = true;
                    }
                }
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        row = heights.size();
        col = heights[0].size();
        if(row == 1 && col == 1)return 0;

        int low = 0;
        int high = 1e6;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isvalid(mid, heights)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};