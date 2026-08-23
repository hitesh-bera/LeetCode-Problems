class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int sumDiff = 0;   // sum(left) - sum(right)
        int questDiff = 0; // count('?' on left) - count('?' on right)

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') questDiff++;
            else sumDiff += (num[i] - '0');
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') questDiff--;
            else sumDiff -= (num[i] - '0');
        }

        // Alice wins if total '?' is odd
        if ((questDiff & 1) != 0) return true;

        // Bob wins only if the excess '?' pairs perfectly cancel the sum difference
        // sumDiff + (questDiff / 2) * 9 == 0  --> Bob wins (false)
        return sumDiff * 2 + questDiff * 9 != 0;
    }
};