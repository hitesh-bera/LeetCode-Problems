class Solution {
public:
    vector<int> arr;
    int n;
    vector<vector<vector<int>>>dp;
    int mod = 1e9 + 7;
    int f(int i, int g1, int g2) {
        if (i == n) {
            return g1 != 0 && g2 != 0 && g1 == g2;
        }
        if(dp[i][g1][g2] != -1)return dp[i][g1][g2];
        long long ans = 0;
        ans += f(i + 1, g1, g2); //skip
        ans %= mod;
        ans += f(i + 1, gcd(g1, arr[i]), g2); //take arr[i] in seq1
        ans %= mod;
        ans += f(i + 1, g1, gcd(g2, arr[i])); //take arr[i] in seq2
        ans %= mod;
    
        return dp[i][g1][g2]= int(ans);
    }
    int subsequencePairCount(vector<int>& nums) {
        arr = nums;
        n = arr.size();
        dp.assign(n, vector<vector<int>>(201,vector<int>(201,-1)));
        return f(0, 0, 0);
    }
};