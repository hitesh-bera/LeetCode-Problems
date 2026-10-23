class Solution {
public:
    int firstIdGreaterThanEle(int left, int target, vector<int>& nums) {
        int right = nums.size() - 1;

        int id = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] >= target) {
                id = mid; // Potential answer found; look left for an earlier
                          // occurrence
                right = mid - 1;
            } else {
                left = mid + 1; // Not strictly greater; look right
            }
        }

        return id;
    }

    int lastIdLessThanEle(int left, int target, vector<int>& nums) {
        int right = nums.size() - 1;

        int id = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] <= target) {
                id = mid; // Potential answer found; look right for a later
                          // occurrence
                left = mid + 1;
            } else {
                right = mid - 1; // Equal to or greater than target; look left
            }
        }

        return id;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        long long cnt = 0;

        for (int i = 0; i < n; i++) {
            int y1 = lower - nums[i];
            int y2 = upper - nums[i];

            int i1 = firstIdGreaterThanEle(i + 1, y1, nums);
            int i2 = lastIdLessThanEle(i + 1, y2, nums);

            if(i1 != -1 && i2 != -1 && i2 >= i1)
                cnt += i2 - i1 + 1;
        }

        return cnt;
    }
};