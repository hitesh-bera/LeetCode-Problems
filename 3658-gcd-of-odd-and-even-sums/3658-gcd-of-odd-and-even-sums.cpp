class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int g1= n*n;
        int g2 = n*(n+1);
        return gcd(g1,g2);
    }
};