/*
//1. recursive approach.
class Solution {
public:
    int n;
    vector<int> dp;
    int f(int i, vector<int>& nums) {
        if (i >= n)
            return 0;
        if (dp[i] != INT_MAX)
            return dp[i];
        int first = nums[i];
        int second = 0;
        if (i + 1 < n)
            second = nums[i + 1];
        int third = 0;
        if (i + 2 < n)
            third = nums[i + 2];
        int takeOne = first - f(i + 1, nums);
        int takeTwo = first + second - f(i + 2, nums);
        int takeThree = first + second + third - f(i + 3, nums);

        return dp[i] = max({takeOne, takeTwo, takeThree});
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.assign(n, INT_MAX);
        int netMargin = f(0, stoneValue);
        if (netMargin == 0)
            return "Tie";
        else if (netMargin > 0)
            return "Alice";
        else
            return "Bob";
    }
};
*/

/*
//2. tabulation
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int netMargin;
        if (n == 1)
            netMargin = stoneValue[n - 1];
        else if (n == 2)
            if (stoneValue[n - 1] > 0)
                netMargin = stoneValue[n - 2] + stoneValue[n - 1];
            else
                netMargin = stoneValue[n - 2] - stoneValue[n - 1];
        else {
            vector<int> dp(n + 3, 0);
            
            for (int i = n - 1; i >= 0; i--) {
                int first = stoneValue[i];
                int second = 0;
                if (i + 1 < n)
                    second = stoneValue[i + 1];
                int third = 0;
                if (i + 2 < n)
                    third = stoneValue[i + 2];
                int takeOne = first - dp[i + 1];
                int takeTwo = first + second - dp[i + 2];
                int takeThree = first + second + third - dp[i + 3];

                dp[i] = max({takeOne, takeTwo, takeThree});
            }
            netMargin = dp[0];
        }
        if (netMargin == 0)
            return "Tie";
        else if (netMargin > 0)
            return "Alice";
        else
            return "Bob";
    }
};
*/

//3. space optimization O(1)
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int netMargin;
        if (n == 1)
            netMargin = stoneValue[n - 1];
        else if (n == 2)
            if (stoneValue[n - 1] > 0)
                netMargin = stoneValue[n - 2] + stoneValue[n - 1];
            else
                netMargin = stoneValue[n - 2] - stoneValue[n - 1];
        else {
            int n0;
            int n1 = 0;
            int n2 = 0;
            int n3 = 0;
            for (int i = n - 1; i >= 0; i--) {
                int first = stoneValue[i];
                int second = 0;
                if (i + 1 < n)
                    second = stoneValue[i + 1];
                int third = 0;
                if (i + 2 < n)
                    third = stoneValue[i + 2];
                int takeOne = first - n1;
                int takeTwo = first + second - n2;
                int takeThree = first + second + third - n3;

                n0 = max({takeOne, takeTwo, takeThree});
                n3 = n2;
                n2 = n1;
                n1 = n0;
            }
            netMargin = n0;
        }
        if (netMargin == 0)
            return "Tie";
        else if (netMargin > 0)
            return "Alice";
        else
            return "Bob";
    }
};