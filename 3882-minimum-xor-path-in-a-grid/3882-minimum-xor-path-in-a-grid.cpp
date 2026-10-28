class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> prev(col, vector<bool>(1024, false));

        int rowXor = 0;

        for(int j = 0;j < col;j++){
            rowXor = rowXor ^ grid[0][j];
            prev[j][rowXor] = true;
        }

        for (int i = 1; i < row; i++) {
            vector<vector<bool>> cur(col, vector<bool>(1024, false));
            for (int j = 0; j < col; j++) {
                for (int k = 0; k < 1024; k++) {
                    if (i > 0 && prev[j][k]) {
                        cur[j][(k ^ grid[i][j])] = 1;
                    }
                    if (j > 0 && cur[j - 1][k]) {
                        cur[j][(k ^ grid[i][j])] = 1;
                    }
                }
            }
            prev = cur;
        }

        int minXOR = 1024;

        for (int k = 0; k < 1024; k++) {
            if (prev[col - 1][k])
                minXOR = min(minXOR, k);
        }

        return minXOR;
    }
    
};

/*
Time Complexity: O(m*n*1024)
Space Complexity: O(m*n*1024)
//if we only memorize two row, our job is done bcoz for the counting the result for the i-th row, we just meed it's prev row which is i-1
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<vector<int>>> dp(
            row, vector<vector<int>>(col, vector<int>(1024, 0)));

        dp[0][0][grid[0][0]] = 1;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                for (int k = 0; k < 1024; k++) {
                    if (i > 0 && dp[i - 1][j][k]) {
                        dp[i][j][(k ^ grid[i][j])] = 1;
                    }
                    if (j > 0 && dp[i][j - 1][k]) {
                        dp[i][j][(k ^ grid[i][j])] = 1;
                    }
                }
            }
        }

        int minXOR = 1024;

        for (int k = 0; k < 1024; k++) {
            if (dp[row - 1][col - 1][k])
                minXOR = min(minXOR, k);
        }

        return minXOR;
    }
};
*/