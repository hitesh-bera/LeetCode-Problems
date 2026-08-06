/*
//1. precomputation
class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> diff(n + k + 2, 0);
        for (int i = 0; i <= n - k; i++) {
            if (i > 0)
                diff[i] += diff[i - 1];
            int need = nums[i] - diff[i];
            if (need < 0)
                return false;
            diff[i] += need;
            diff[i + k] -= need;
        }

        for (int i = 0; i < n; i++) {
            if (i > n - k)
                diff[i] += diff[i - 1];
            if (nums[i] != diff[i])
                return false;
        }
        return true;
    }
};
*/

/*
// 2. one pass
class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> diff(n + 2, 0);
        for (int i = 0; i < n; i++) {
            if (i > 0)
                diff[i] += diff[i - 1];

            int need = nums[i] - diff[i];
            if (need < 0)
                return false;
            if (need > 0) {
                if (i + k > n)
                    return false;
                diff[i] += need;
                diff[i + k] -= need;
            }

            if (nums[i] != diff[i])
                return false;
        }
        return true;
    }
};
*/

// 3. space opt
class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        int need = 0;
        for (int i = 0; i < n; i++) {

            if (i >= k) {
                need -= nums[i - k];
            }

            nums[i] -= need;

            if (nums[i] < 0)
                return false;

            if (nums[i] > 0) { 
                if (i + k > n)
                    return false;

                need += nums[i];
            }
            // if we dont put nums[i]>0 then it returns false at the end of the array even when nums[i] is already 0 due to i+k > n which is wrong because it's already zero, we don;t need to do anything.
        }
        return true;
    }
};