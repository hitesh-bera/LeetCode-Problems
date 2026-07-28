class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> freq(26, 0);

        for (char ch : s)
            freq[ch - 'a']++;

        char middle;
        string first = "";

        for (int i = 0; i < 26; i++) {
            char ch = 'a' + i;

            if (freq[i] == 0)
                continue;

            if (freq[i] % 2) {
                middle = ch;
                freq[i]--;
            }

            for (int j = 0; j < (freq[i] / 2); j++) {
                first += ch;
            }
        }
        string second = first;
        reverse(second.begin(), second.end());
        if (n % 2)
            return first + middle + second;

        return first + second;
    }
};