/*
//1. recursive approach
class Solution {
public:
    vector<vector<int>> dp;
    bool f(int n, bool turn) {
        if (n == 0)
            return !turn;
        if (dp[n][int(turn)] != -1)
            return dp[n][int(turn)];
        for (int i = 1; i * i <= n; i++) {
            if (f(n - i * i, !turn) == turn)
                return dp[n][int(turn)] = turn;
        }
        return dp[n][int(turn)] = !turn;
    }
    bool winnerSquareGame(int n) {
        dp.assign(n+1, vector<int>(2, -1));
        return f(n, true);
    }
};
*/

/*
//2. optimization in recursive approach
class Solution {
public:
    vector<int> dp;
    bool f(int n) {
        if (n == 0)
            return false;
        if (dp[n] != -1)
            return dp[n];
        for (int i = 1; i * i <= n; i++) {
            if (!f(n - i * i))
                return dp[n] = true;
        }
        return dp[n] = false;
    }
    bool winnerSquareGame(int n) {
        dp.assign(n+1, -1);
        return f(n);
    }
};
*/

class Solution {
public:
    bool winnerSquareGame(int num) {
        vector<int> dp(num + 1, false);
        dp[0] = 0;
        for (int n = 1; n <= num; n++) {
            for (int i = 1; i * i <= n; i++) {
                if (!dp[n - i * i]) {
                    dp[n] = true;
                    break;
                }
            }
        }
        return dp[num];
    }
};