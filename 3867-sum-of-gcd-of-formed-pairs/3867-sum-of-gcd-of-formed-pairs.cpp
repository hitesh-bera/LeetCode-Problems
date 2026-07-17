class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        long long mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i] > mx)
                mx = nums[i];
            nums[i] = gcd(nums[i], mx);
        }
        sort(nums.begin(), nums.end());
        int left = 0, right = n - 1;
        long long gcdSum = 0;
        while (left < right) {
            gcdSum += gcd(nums[left++], nums[right--]);
        }
        return gcdSum;
    }
};