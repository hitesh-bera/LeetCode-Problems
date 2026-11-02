class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        long long cnt1 = 0, cnt2 = 0;

        for(int i = 0;i < n;i++){
            cnt1 += abs(nums[i]-nums[n/2]);

            if(n % 2 == 0)
                cnt2 += abs(nums[i]-nums[(n/2)-1]);
        }

        if(n % 2)return cnt1;

        return min(cnt1, cnt2);
    }
};