class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int totalXor = 0;
        bool allZero = true;

        for (int x : nums) {
            totalXor ^= x;
            if (x != 0) {
                allZero = false;
            }
        }

        // Case 1: Only zeros exist
        if (allZero) return 0;

        // Case 2: Whole array XOR is non-zero
        if (totalXor != 0) return n;

        // Case 3: Remove any non-zero element to get non-zero XOR
        return n - 1;
    }
};