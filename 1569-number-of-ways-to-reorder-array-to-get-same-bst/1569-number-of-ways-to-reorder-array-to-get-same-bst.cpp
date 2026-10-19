class Solution {
public:

    vector<vector<long long>>C;

    long long mod = 1e9 + 7;

    int solve(vector<int> nums){
        int n = nums.size();

        if(n < 3){
            return 1;
        }

        vector<int> left_tree, right_tree;

        for(int i=1;i<n;i++){
            if(nums[i] < nums[0]){
                left_tree.push_back(nums[i]);
            }else{
                right_tree.push_back(nums[i]);
            }
        }

        long long x = solve(left_tree) % mod;

        long long y = solve(right_tree) % mod;

        long long z = C[n-1][left_tree.size()] % mod;

        return (1LL * ((1LL * x * y) % mod) * z) % mod;

    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        C.assign(n, vector<long long>(n, 1));
        for(int i=1;i<n;i++){
            for(int j = 1;j<i;j++){
                C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
            }
        }

        return solve(nums) - 1;
    }
};