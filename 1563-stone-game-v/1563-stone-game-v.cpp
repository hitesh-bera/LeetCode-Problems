/*
//1. recursive approach
class Solution {
public:
    vector<vector<int>>dp;
    vector<int>prefix;
    int n;
    int getSum(int i,int j){
        return prefix[j+1] - prefix[i];
    }
    int f(int i, int j) {
        if (i == j)
            return 0;

        if(dp[i][j] != -1)return dp[i][j];

        int maxSum = INT_MIN;
        for(int k = i;k < j;k++){
            int leftSum = getSum(i,k);
            int rightSum = getSum(k+1,j);

            if(leftSum < rightSum){
                maxSum = max(maxSum, leftSum + f(i,k));
            }else if(rightSum < leftSum){
                maxSum = max(maxSum, rightSum + f(k+1,j));
            }else{
                int takeLeft = getSum(i,k) + f(i,k);
                int takeRight = getSum(k+1,j) + f(k+1,j);
                maxSum = max({maxSum, takeLeft, takeRight});
            }
        }
        return dp[i][j] = maxSum;
    }
    int stoneGameV(vector<int>& stoneValue) {
        n = stoneValue.size();
        prefix.assign(n+1, 0);
        dp.assign(n, vector<int>(n, -1));
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + stoneValue[i-1];
        }
        return f(0, n - 1);
    }
};
*/
class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + stoneValue[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                int maxSum = INT_MIN;
                for (int k = i; k < j; k++) {
                    int leftSum = prefix[k + 1] - prefix[i];
                    int rightSum = prefix[j + 1] - prefix[k+1];

                    if (leftSum < rightSum) {
                        maxSum = max(maxSum, leftSum + dp[i][k]);
                    } else if (rightSum < leftSum) {
                        maxSum = max(maxSum, rightSum + dp[k + 1][j]);
                    } else {
                        int takeLeft = prefix[k + 1] - prefix[i] + dp[i][k];
                        int takeRight = prefix[j + 1] - prefix[k+1] + dp[k + 1][j];
                        maxSum = max({maxSum, takeLeft, takeRight});
                    }
                }
                dp[i][j] = maxSum;
            }
        }

        return dp[0][n - 1];
    }
};