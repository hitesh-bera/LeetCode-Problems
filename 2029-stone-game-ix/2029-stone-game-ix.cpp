class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int r0 = 0;
        int r1 = 0;
        int r2 = 0;
        for (int x : stones) {
            if (x % 3 == 0)
                r0++;
            else if (x % 3 == 1)
                r1++;
            else
                r2++;
        }
        if (r0 % 2 == 0)
            return r1 >= 1 && r2 >= 1;
        return abs(r1 - r2) > 2;
    }
};