class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        // Path length must be even
        if ((row + col - 1) % 2 == 1)
            return false;

        // First character must be '('
        if (grid[0][0] == ')')
            return false;

        // Last character must be ')'
        if (grid[row - 1][col - 1] == '(')
            return false;

        // bit k = balance k is possible
        vector<vector<bitset<101>>> dp(
            row, vector<bitset<101>>(col)
        );

        // At (0,0), balance = 1
        // So bit 1 is set:
        // 00010
        dp[0][0][1] = 1;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                // Starting cell already handled
                if (i == 0 && j == 0)
                    continue;

                bitset<101> rootToParent;

                // From upper cell
                if (i > 0) {
                    rootToParent |= dp[i - 1][j];
                }

                // From left cell
                if (j > 0) {
                    rootToParent |= dp[i][j - 1];
                }

                // No possible balance
                if (rootToParent.none())
                    continue;

                if (grid[i][j] == '(') {

                    // '(' increases balance by 1
                    dp[i][j] = rootToParent << 1;

                } else {

                    // ')' decreases balance by 1
                    dp[i][j] = rootToParent >> 1;
                }
            }
        }

        // bit 0 means balance = 0 is possible
        return dp[row - 1][col - 1][0];
    }
};

/*


this is my idea but it can not handle more than 64 bit but we have given m,n <= 100 so we have ti deal with more that 64 bit
now how many max bit? => max path len -> 199 so we have to manage count till last 99 bit because if difference is more that 99 we can not balance it so we don't need to worry about difference of ( - ) > 99 it always impossible
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        if((row + col - 1) % 2 == 1 || grid[0][0] == ')')return false;

        vector<vector<unsigned long long>> dp(
            row, vector<unsigned long long>(col, 0)
        );

        dp[0][0] = (1ULL << 1); //10 -> diff = 1 therefor one at first pos (10).
        int cnt = 1;

        for(int j=1;j<col;j++){
            if(grid[0][j] == '('){
                cnt ++;
            }else cnt --;

            if((cnt < 0) || (cnt > (row+col-1)/2) || (dp[0][j-1] == 0)){
                dp[0][j] = 0;
            }else{
                dp[0][j] = (1ULL << cnt);
            }
        }

        cnt = 1;
        for(int i=1;i<row;i++){
            if(grid[i][0] == '('){
                cnt ++;
            }else cnt --;

            if((cnt < 0) || (cnt > (row+col-1)/2) || (dp[i-1][0] == 0)){
                dp[i][0] = 0;
            }else{
                dp[i][0] = (1ULL << cnt);
            }
        }

        for(int i=1;i<row;i++){
            for(int j = 1;j<col;j++){
                unsigned long long parent =
                    dp[i - 1][j] | dp[i][j - 1];

                if(grid[i][j] == '('){
                    //left shift
                    dp[i][j] = (parent << 1);
                }else{
                    //right shift
                    dp[i][j] = (parent >> 1);
                }
            }
        }
        return dp[row - 1][col - 1] & 1ULL;
    }
};
*/