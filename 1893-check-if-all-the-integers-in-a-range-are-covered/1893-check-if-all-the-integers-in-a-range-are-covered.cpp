/*
//1. main idea approach
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int>diff(52,0);
        for(const auto &range : ranges){
            int l = range[0];
            int r = range[1];
            diff[l] += 1;
            diff[r+1] -= 1;
        }
        for(int i = 1;i<=50;i++){
            diff[i] +=diff[i-1];
        }
        for(int i = left;i<=right;i++){
            if(diff[i] <= 0)return false;
        }
        return true;
    }
};
*/

//2. slightly optimized version
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int>diff(52,0);
        for(const auto &range : ranges){
            int l = range[0];
            int r = range[1];
            diff[l] += 1;
            diff[r + 1] -= 1;
        }

        int runningIntervals = 0;
        for(int i = 1;i<= right;i++){
            runningIntervals += diff[i];

            if(i >= left && runningIntervals <= 0)return false;
        }
        return true;
    }
};