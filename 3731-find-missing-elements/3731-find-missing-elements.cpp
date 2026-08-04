class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = 101;
        int maxi = 0;
        vector<bool> present(101, false);
        for (int x : nums) {
            mini = min(mini, x);
            maxi = max(maxi, x);
            present[x] = true;
        }
        vector<int> missingNumbers;
        for (int i = mini+1; i < maxi; i++) {
            if (!present[i])
                missingNumbers.push_back(i);
        }
        return missingNumbers;
    }
};