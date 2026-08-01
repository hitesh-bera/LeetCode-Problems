/*
//1. Recursive approach
// in this case, we will maximize the sum of player-1 and the end of the day we
will check weather the player-1 sum >= player-2 sum class Solution { public:
    vector<vector<int>>dp;
    vector<int>nums;
    int n;
    int f(int i, int j){
        if(i > j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int t1 = f(i+2, j);
        int t2 = f(i+1, j-1);
        int t3 = f(i, j-2);

        int takeFirst = nums[i] + min(t1, t2);
        int takeLast = nums[j] + min(t2, t3);

        return dp[i][j] = max(takeFirst, takeLast);
    }
    bool predictTheWinner(vector<int>& arr) {
        nums = arr;
        n = arr.size();
        dp.assign(n, vector<int>(n, -1));

        int s2 = 0;
        for(int x: nums) s2+=x;

        int s1 = f(0, n-1);
        s2 -= s1;
        return s1 >= s2;
    }
};

//state of the dp: dp[i][j] = The maximum total score Player 1 can guarantee to
collect from the sub-array [i..j], assuming both players play optimally from
this point onward.
*/

/*
//2. Recursive approach
//since both of them are trying to play optimal, we will check that how much he
can get in his turn, nut the twist is that we will add the profit of first
whenever it's first turn and substract other's profit. and the end of the
process,if this substraction goes to >=0 it means that player-1 sum >= player-2
sum.

class Solution {
public:
    vector<vector<int>>dp;
    vector<int>nums;
    int n;

    int f(int i, int j){
        if(i > j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int takeFirst = nums[i] - f(i+1,j);
        int takeLast = nums[j] - f(i, j-1);

        return dp[i][j] = max(takeFirst, takeLast);
    }

    bool predictTheWinner(vector<int>& arr) {
        nums = arr;
        n = arr.size();
        dp.assign(n, vector<int>(n, -1));

        return f(0,n-1) >= 0;
    }
};
// state of the dp: dp[i][j] = The maximum net margin (Current Player Score -
Opponent Score) that the player whose turn it is can achieve using the remaining
elements in range [i..j].

*/

/*
// 3. tabulation approach.
// based on the recursion indexing, we can say that we need previous column and
// next row to compute current index.in short (i,j) is depend on the (i,j-1) and
// (i+1,j)

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }
        for (int d = 1; d < n; d++) {
            for (int i = 0; i < n - d; i++) {
                int takeFirst = nums[i] - dp[i + 1][i + d];
                int takeLast = nums[i + d] - dp[i][i + d - 1];

                dp[i][i+d] = max(takeFirst, takeLast);
            }
        }
        return dp[0][n-1] >= 0;
    }
};

*/

// 4. space optimization
// since it is only depends on previous column and next row, we can maintain two
// sepatare 1D vectors for that

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        vector<int> diagonal = nums;
        vector<int> nextDiagonal;

        for (int d = 1; d < n; d++) {
            nextDiagonal.clear();
            for (int i = 0; i < n - d; i++) {
                int takeFirst = nums[i] - diagonal[i+1];
                int takeLast = nums[i + d] - diagonal[i];

                nextDiagonal.push_back(max(takeFirst, takeLast));
            }
            diagonal = nextDiagonal;
        }
        return diagonal[0] >= 0;
    }
};