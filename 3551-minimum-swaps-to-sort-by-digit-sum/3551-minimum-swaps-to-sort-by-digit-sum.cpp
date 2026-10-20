class Solution {
public:
    int minSwaps(vector<int>& nums) {

        int n = nums.size();

        vector<tuple<int,int,int>>tupples;

        for(int i = 0;i < n;i++){
            int digitSum = 0;
            int curNum = nums[i];

            while(curNum != 0){
                digitSum += curNum % 10;
                curNum /= 10;
            }

            tupples.push_back({digitSum, nums[i], i});
        }

        sort(tupples.begin(), tupples.end());

        vector<int>truePos(n);

        for(int i = 0;i < n;i++){
            truePos[i] = get<2>(tupples[i]);
        }

        int swaps = 0;

        for(int st=0;st<n;st++){
            if(truePos[st] == -1 || truePos[st] == st)continue;

            int cycleLen = 0;
            int i = st;
            while(truePos[i] != -1){
                int curPos = truePos[i];
                truePos[i] = -1;
                i = curPos;
                cycleLen++;
            }
            swaps += cycleLen - 1;
        }
        return swaps;
    }
};