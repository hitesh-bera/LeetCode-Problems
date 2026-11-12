class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int inc = 1;
        int dec = 1;

        int cnt1 = 1;
        int cnt2 = 1;

        for(int i = 1;i < n;i++){
            if(nums[i] < nums[i-1]){
                cnt2++;
            }else{
                dec = max(dec, cnt2);
                cnt2 = 1;
            }

            if(nums[i] > nums[i-1]){
                cnt1++;
            }else{
                inc = max(inc, cnt1);
                cnt1 = 1;
            }
        }
        dec = max(dec, cnt2);
        inc = max(inc, cnt1);
        return max({dec, inc});
    }
};

/*
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1;
        int cnt = 1;
        for(int i = 1;i < nums.size();i++){
            if(nums[i] > nums[i-1])cnt++;
            else {
                inc = max(inc, cnt);
                cnt = 1;
            }
        }
        inc = max(inc, cnt);


        int dec = 1;
        cnt = 1;

        for(int i =1;i<nums.size();i++){
            if(nums[i] < nums[i-1]){
                cnt++;
            }else{
                dec = max(dec, cnt);
                cnt = 1;
            }
        }
        dec = max(dec, cnt);
        return max(inc, dec);
    }
};
*/