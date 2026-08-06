/*
// 1.basic approach.
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> diff(102, 0);
        // 1950 -> 0, 1951 -> 1,........, 2050 -> 100
        for (const auto& range : nums) {
            int l = range[0];
            int r = range[1];
            diff[l] += 1;
            diff[r + 1] -= 1;
        }

        for (int i = 1; i <= 100; i++) {
            diff[i] += diff[i - 1];
        }

        int cnt = 0;

        for (int i = 0; i <= 100; i++) {
            if (diff[i] > 0) {
                cnt++;
            }
        }
        return cnt;
    }
};
*/

// 2. do in one pass(like don't compute finel diff first, bcoz we don't need it)
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> diff(102, 0);
        for (const auto& range : nums) {
            int l = range[0];
            int r = range[1];

            diff[l] += 1;
            diff[r + 1] -= 1;
        }

        int runningIntervals = 0;
        int cnt = 0;
        for (int i = 0; i <= 100; i++) {
            runningIntervals += diff[i];
            if (runningIntervals > 0)
                cnt++;
        }
        return cnt;
    }
};
