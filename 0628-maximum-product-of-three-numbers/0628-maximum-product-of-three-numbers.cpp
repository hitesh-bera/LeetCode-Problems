class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int mini = INT_MAX;
        int sMini = INT_MAX;
        int maxi = INT_MIN;
        int sMaxi = INT_MIN;
        int tMaxi = INT_MIN;
        for(int x: nums){
            if(x > maxi){
                tMaxi = sMaxi;
                sMaxi = maxi;
                maxi = x;
            }else if(x > sMaxi){
                tMaxi = sMaxi;
                sMaxi = x;
            }else if(x > tMaxi){
                tMaxi = x;
            }

            if(x < mini){
                sMini = mini;
                mini = x;
            }else if(x < sMini){
                sMini = x;
            }
        }
        return max(mini*sMini*maxi, tMaxi*sMaxi*maxi);
    }
};