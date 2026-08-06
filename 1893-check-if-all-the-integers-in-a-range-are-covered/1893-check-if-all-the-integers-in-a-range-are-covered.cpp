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