class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        vector<vector<int>>dis(row, vector<int>(col, INT_MAX)); //min effort req. to reach (r,c) from (0,0)
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>>pq;

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