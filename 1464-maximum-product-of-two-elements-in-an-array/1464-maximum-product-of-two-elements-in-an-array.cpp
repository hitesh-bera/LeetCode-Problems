class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int sMaxi = INT_MIN;
        for(int x:nums){
            if(x > maxi){
                sMaxi = maxi;
                maxi = x;
            }else if(x > sMaxi){
                sMaxi = x;
            }
        }
        return (maxi-1)*(sMaxi-1);
    }
};