class Solution {
public:

    void dfs(int r, int c, vector<vector<int>> grid, vector<vector<bool>>& vis){
        if(vis[r][c])return;

        vis[r][c] = true;

        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};

        for(int k = 0;k < 4;k++){
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == 0 && !vis[nr][nc]){
                dfs(nr, nc, grid, vis);
            }
        }
        return;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> vis(row, vector<bool>(col, false));

        //first row
        for(int j = 0;j < col;j++){
            if(grid[0][j] == 0 && !vis[0][j]){
                dfs(0, j, grid, vis);
            }
        }

        //last row
        for(int j = 0;j < col;j++){
            if(grid[row - 1][j] == 0 && !vis[row-1][j]){
                dfs(row - 1, j, grid, vis);
            }
        }

        //first col
        for(int i = 0;i < row;i++){
            if(grid[i][0] == 0 && !vis[i][0]){
                dfs(i, 0, grid, vis);
            }
        }

        //last col
        for(int i = 0;i < row;i++){
            if(grid[i][col - 1] == 0 && !vis[i][col - 1]){
                dfs(i, col - 1, grid, vis);
            }
        }

        int island = 0;

        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(grid[i][j] == 0 && !vis[i][j]){
                    island++;
                    dfs(i, j, grid, vis);
                }
            }
        }

        return island;
    }
};