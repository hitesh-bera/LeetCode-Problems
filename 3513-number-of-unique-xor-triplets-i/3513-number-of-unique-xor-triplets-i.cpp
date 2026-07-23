class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2)
            return n;

        int msb = 31 - __builtin_clz(n);   // floor(log2(n))

        return 1 << (msb + 1);
    }
};