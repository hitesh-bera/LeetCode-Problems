class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int curSum = 0;
        vector<int>minLenTillIdx(n, INT_MAX);
        int left = 0;
        int right = 0;
        int bestTillNow = INT_MAX;
        int ans = INT_MAX;
        while(right < n){
            curSum += arr[right];
 
            while(left < right && curSum > target){
                curSum -= arr[left++]; 
            }
            if(curSum == target){
                int len = right-left+1;
                if(left > 0 && minLenTillIdx[left-1] != INT_MAX){
                    ans = min(ans, len + minLenTillIdx[left-1]);
                }
                bestTillNow = min(bestTillNow, len);
            }
            minLenTillIdx[right] = bestTillNow;
            right++;
        }
        if(ans == INT_MAX)return -1;
        return ans;
    }
};