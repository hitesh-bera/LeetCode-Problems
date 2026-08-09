/*
//1.
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
*/

//2. optimized version
class Solution {
public:
    int trailingZeroes(int n) {
        int five = 0;
        int two = 0;

        int num = n;
        int d = 5;
        while(num/d != 0){
            five += num/d;
            d *= 5;
        }

        num = n;
        d = 2;
        while(num/d != 0){
            two += num/d;
            d *= 2;
        }
        return min(two, five);
    }
};