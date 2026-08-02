/*
//1. recursive approach
class Solution {
public:
int n;
    vector<int> prefix;
    vector<int>dp;
    int f(int i) {
        if (i == n-1)
            return prefix[i];

        if(dp[i] != -1)return dp[i];

        int takeHere = prefix[i] - f(i+1);
        int skip = f(i+1);

        return dp[i] = max(takeHere, skip);
    }
    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        dp.assign(n, -1);

        prefix.assign(n, 0);
        prefix[0] = stones[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        return f(1);
    }
};
*/

/*
// 2. tabulation
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> dp(n, -1);

        vector<int> prefix(n, 0);
        prefix[0] = stones[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        dp[n - 1] = prefix[n - 1];
        for (int i = n - 2; i >= 1; i--) {
            int takeHere = prefix[i] - dp[i + 1];
            int skip = dp[i + 1];

            dp[i] = max(takeHere, skip);
        }

        return dp[1];
    }
};
*/

// 3. space optimization
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<int> prefix(n, 0);
        prefix[0] = stones[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        int next = prefix[n-1];
        int cur = next;
        for (int i = n - 2; i >= 1; i--) {
            int takeHere = prefix[i] - next;
            int skip = next;

            cur = max(takeHere, skip);

            next = cur;
        }

        return next;
    }
};