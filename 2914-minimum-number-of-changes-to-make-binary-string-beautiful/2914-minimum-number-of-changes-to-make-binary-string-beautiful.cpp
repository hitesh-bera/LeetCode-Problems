class Solution {
public:
    int minChanges(string s) {
        int n = s.size();

        int prev = 1;
        int i = 1;

        int ope = 0;

        while (i < n) {
            if (s[i] == s[i - 1])
                prev++;
            else {
                if (prev % 2) {
                    ope++;
                    i++;
                }
                prev = 1;
            }
            i++;
        }
        return ope;
    }
};