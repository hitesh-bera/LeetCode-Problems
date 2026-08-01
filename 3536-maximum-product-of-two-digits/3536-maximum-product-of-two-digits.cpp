class Solution {
public:
    int maxProduct(int n) {
        int maxi = INT_MIN;
        int sMaxi = INT_MIN;

        int num = n;
        while (num > 0) {
            int r = num % 10;
            num /= 10;

            if(r > maxi){
                sMaxi = maxi;
                maxi = r;
            }else if(r > sMaxi){
                sMaxi = r;
            }
        }
        return maxi*sMaxi;
    }
};