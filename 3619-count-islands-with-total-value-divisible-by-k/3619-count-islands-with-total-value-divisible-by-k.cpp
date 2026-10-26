class Solution {
public:

    int row, col;

    bool isvalid(int i,int j){
        return i >= 0 && j >= 0 && i < row && j < col;
    }

    long long Sum(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis){

        long long sum = 0;

        queue<pair<int,int>>q;
        q.push({i, j});
        vis[i][j] = true;

        const int dr[4] = {1, 0, -1, 0};
        const int dc[4] = {0, 1, 0, -1};

        while(!q.empty()){

            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            sum += grid[r][c];

            for(int k = 0;k < 4;k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(isvalid(nr, nc) && grid[nr][nc] != 0 && !vis[nr][nc]){
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }

        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        row = grid.size();
        col = grid[0].size();

        vector<vector<bool>> vis(row, vector<bool>(col, false));

        int cnt = 0;

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {

                if (grid[r][c] != 0 && !vis[r][c]) {

                    long long sum = Sum(r, c, grid, vis);
                    if (sum % k == 0)
                        cnt++;

                }

            }
        }
        return cnt;
    }
};