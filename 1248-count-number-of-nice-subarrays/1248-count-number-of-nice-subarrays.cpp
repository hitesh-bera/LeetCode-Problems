class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // even -> 0, odd -> 1
        int n = nums.size();

        vector<int> prevOdd(n);

        int prevOddId = -1;
        for (int i = 0; i < n; i++) {
            prevOdd[i] = prevOddId;

            if (nums[i] % 2)
                prevOddId = i;
        }

        vector<int> nextOdd(n);

        int nextOddId = n;
        for (int i = n - 1; i >= 0; i--) {
            nextOdd[i] = nextOddId;

            if (nums[i] % 2)
                nextOddId = i;
        }

        int firstOddId = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2) {
                firstOddId = i;
                break;
            }
        }

        if(firstOddId == -1)return 0;

        int i = firstOddId, j = firstOddId;
        for(int step = 1;step < k;step++){
            j = nextOdd[j];
            if(j >= n)return 0;
        }

        long long cnt = 0;

        while (j < n) {

            //i to j contains k odd elements
            int prevEvenBlockSize = i - prevOdd[i] - 1;
            int nextEvenBlockSize = nextOdd[j] - j - 1;

            cnt += 1LL * (prevEvenBlockSize + 1) * (nextEvenBlockSize + 1);

            i = nextOdd[i];
            j = nextOdd[j];
        }
        return cnt;
    }
};