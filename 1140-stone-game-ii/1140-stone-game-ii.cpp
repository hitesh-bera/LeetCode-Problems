/*
//1. recursive approach.
class Solution {
public:
    int n;
    vector<int> prefix;
    vector<vector<int>> dp;
    int f(int i, int m) {
        if (i >= n) {
            return 0;
        }
        if (i + 2 * m >= n) { return prefix[n] - prefix[i];
        }
        if (dp[i][m] != -1) {
            return dp[i][m];
        }

        int maxSum = INT_MIN;
        for (int x = 1; x <= (2 * m); x++) {
            int curSum = prefix[i + x] - prefix[i];
            maxSum = max(maxSum, curSum - f(i + x, max(m, x)));
        }
        return dp[i][m] = maxSum;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        prefix.assign(n + 1, 0);
        dp.assign(n, vector<int>(n, -1));
        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] + piles[i - 1]; // exclusive

        int total = prefix[n];
        int netMargin = f(0, 1);
        int ans = (total + netMargin) / 2;
        return ans;
    }
};
*/

// 2. Memoization.
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] + piles[i - 1]; // exclusive

        for (int i = n - 1; i >= 0; i--) {
            for (int m = 1; m <= n; m++) {

                if (i + 2 * m >= n) {
                    dp[i][m] = prefix[n] - prefix[i];
                    continue;
                }

                int maxSum = INT_MIN;
                for (int x = 1; x <= (2 * m); x++) {
                    //if(i + m > n)break;
                    int curSum = prefix[i + x] - prefix[i];
                    maxSum = max(maxSum, curSum - dp[i + x][max(m, x)]);
                }
                dp[i][m] = maxSum;
            }
        }

        int total = prefix[n];
        int netMargin = dp[0][1];
        int ans = (total + netMargin) / 2;
        return ans;
    }
};