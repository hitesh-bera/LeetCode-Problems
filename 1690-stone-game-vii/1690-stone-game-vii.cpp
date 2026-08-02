/*
//1. recursive approach
class Solution {
public:
    int n;
    vector<int>prefix;
    vector<vector<int>>dp;
    int getSum(int i,int j){
        return prefix[j+1] - prefix[i];
    }
    int f(int i, int j){
        if(i == j)return 0;

        if(dp[i][j] != -1)return dp[i][j];

        int removeLeft = getSum(i+1,j) - f(i+1, j);
        int removeRight = getSum(i,j-1) - f(i, j-1);

        return dp[i][j] = max(removeLeft, removeRight);
    }
    int stoneGameVII(vector<int>& stones) {
        n = stones.size();
        prefix.resize(n+1, 0);
        dp.assign(n, vector<int>(n, -1));
        for(int i=1;i<=n;i++){
            prefix[i] = prefix[i-1] + stones[i-1];
        }
        return f(0, n-1);
    }
};
*/

/*
// 2. tabulation.
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + stones[i - 1];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                int removeLeft = prefix[j + 1] - prefix[i + 1] - dp[i + 1][j];
                int removeRight = prefix[j] - prefix[i] - dp[i][j - 1];

                dp[i][j] = max(removeLeft, removeRight);
            }
        }
        return dp[0][n - 1];
    }
};

*/
// 3. since current state only depend on previous column and next row, we can
// manage diagonal vector to optimize space from O(N^2) to O(N)

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + stones[i - 1];
        }
 
        vector<int> prev(n, 0);
        for (int d = 1; d < n; d++) {
            vector<int>cur;
            for (int i = 0; i < n-d; i++) {
                int j = i + d;
                int removeLeft = prefix[j + 1] - prefix[i + 1] - prev[i+1];
                int removeRight = prefix[j] - prefix[i] - prev[i];

                cur.push_back(max(removeLeft, removeRight));
            }
            prev = cur;
        }
        return prev[0];
    }
};