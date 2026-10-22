class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        bool inc = true, dec = true;
        for (int i = 0; i + 1 < n; i++) {
            if (nums[i + 1] != (nums[i] + 1) % n)     inc = false;
            if (nums[i + 1] != (nums[i] - 1 + n) % n) dec = false;
        }
        int p = find(nums.begin(), nums.end(), 0) - nums.begin();

        if (inc) return min(p, n - p + 2);            // p == 0 -> 0
        if (dec) return min(n - p, (p + 1) % n + 1);
        return -1;
    }
};