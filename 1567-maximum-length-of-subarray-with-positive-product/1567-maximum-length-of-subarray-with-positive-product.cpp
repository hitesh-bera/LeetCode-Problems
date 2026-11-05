class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();

        vector<int> zeros;
        vector<int> negativeTill(n, 0);

        zeros.push_back(-1);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                zeros.push_back(i);

            if (i > 0)
                negativeTill[i] += negativeTill[i - 1];
            if (nums[i] < 0)
                negativeTill[i]++;
        }
        zeros.push_back(n);

        if (zeros.size() == 2 && negativeTill[n - 1] % 2 == 0)
            return n;

        int maxLen = 0;

        for (int i = 0; i + 1 < zeros.size(); i++) {
            int st = zeros[i] + 1;
            int end = zeros[i+1] - 1;

            if(st == n)break;

            if (st > end)
                continue;

            int neg = negativeTill[end];
            if(st > 0)neg -= negativeTill[st - 1];

            if (neg % 2 == 0) {
                maxLen = max(maxLen, end - st + 1);
            } else {
                int first = -1, last = -1;
                for (int j = st; j <= end; j++) {
                    if (nums[j] > 0)
                        continue;
                    if (first == -1)
                        first = j;
                    last = j;
                }
                
                maxLen = max({maxLen, last - st, end - first});
            }
        }

        return maxLen;
    }
};