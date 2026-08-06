//1
class Solution {
private:
    // Helper function to calculate product of digits
    int getDigitProduct(int num) {
        int prod = 1;
        while (num > 0) {
            prod *= (num % 10);
            num /= 10;
        }
        return prod;
    }

public:
    int smallestNumber(int n, int t) {
        // Linearly increment until we find a number whose digit product is divisible by t
        while (getDigitProduct(n) % t != 0) {
            n++;
        }
        return n;
    }
};

/*
//2.
class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int i = 1; i <= 100; i++) {
            int m = 1;
            int num = i;
            while (num > 0) {
                m *= num % 10;
                num /= 10;
            }
            if (i >= n && m % t == 0)
                return i;
        }
        return 100;
    }
};
*/