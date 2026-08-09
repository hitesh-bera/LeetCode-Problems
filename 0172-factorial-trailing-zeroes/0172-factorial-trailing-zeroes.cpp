class Solution {
public:
    int trailingZeroes(int n) {
        if (n == 0)
            return 0;

        int two = 0;
        int five = 0;

        for (int i = 1; i <= n; i++) {
            int num = i;
            while(num%2 == 0){
                num/=2;
                two++;
            }
            while(num%5==0){
                num/=5;
                five++;
            }
        }
        return min(five,two);
    }
};