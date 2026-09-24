class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        long long sum = 0;
        for (int num : nums) {
            sum += num;
        }

        int k = sum - x;

        if(k == 0){
            return n;
        }

        int left = 0;
        int right = 0;

        long long windowSum = 0;

        int maxWindowSize = -1;

        while(right < n){
            windowSum += nums[right];

            while(left < right && windowSum > k){
                windowSum -= nums[left++];
            }

            if(windowSum == k){
                maxWindowSize = max(maxWindowSize, right- left + 1);
            }

            right++;
        }

        if(maxWindowSize == -1)return maxWindowSize;

        return n - maxWindowSize;

    }
};

/*
//TLE
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        vector<int>prefix(n,0);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++)prefix[i] = nums[i] + prefix[i-1];

        vector<int>suffix(n,0);
        suffix[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--)suffix[i] = nums[i] + suffix[i+1];

        for(int l = 1;l<=n;l++){
            for(int takeFromTheStart = 0;takeFromTheStart <=
l;takeFromTheStart++){ int takeFromTheEnd = l - takeFromTheStart;

                int x1 = 0;
                if(takeFromTheStart != 0){
                    x1 = prefix[takeFromTheStart-1];
                }

                int x2 = 0;
                if(takeFromTheEnd != 0){
                    x2 = suffix[n-takeFromTheEnd];
                }

                if(x1+x2 == x){
                    return l;
                }
            }
        }
        return -1;
    }
};
*/