class Solution {
public:
    int row, col;
    vector<vector<vector<int>>>dp;
    int mod = 1e9 + 7;

    /*
    camefrom left -> 0
    camefrom up -> 1
    */
    int f(int i, int j, int camefrom, vector<vector<int>>& grid){
        if(i >= row || j >= col)return 0;

        if(dp[i][j][camefrom] != -1)return dp[i][j][camefrom] % mod;

        if(i == row - 1 && j == col - 1)return 1;

        int total = 0;

        if(grid[i][j] == 0){
            total += (f(i+1, j, 1, grid) % mod);
            total += (f(i, j+1, 0, grid) % mod);
        }else{ //curent cell is mirror
            if(camefrom == 0){ //reflect down side
                total = (f(i+1, j, 1, grid) % mod);
            }else{ //reflect right side
                total = (f(i, j+1, 0, grid) % mod);
            }
        }
        return dp[i][j][camefrom] = total % mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();

        dp.assign(row, vector<vector<int>>(col, vector<int>(2, -1)));

        return f(0, 0, 0, grid);
    }
};