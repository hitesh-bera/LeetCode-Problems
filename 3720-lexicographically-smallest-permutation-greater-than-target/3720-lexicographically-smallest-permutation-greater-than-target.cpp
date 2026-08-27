class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        if (s.size() < target.size()) return "";

        // 1. Frequency count of all available characters in s
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        // 2. Find the maximum prefix length of target we can form
        int max_match = 0;
        vector<int> temp_count = count;
        while (max_match < (int)target.size() && temp_count[target[max_match] - 'a'] > 0) {
            temp_count[target[max_match] - 'a']--;
            max_match++;
        }

        // 3. Try prefix lengths from max_match down to 0
        for (int i = max_match; i >= 0; i--) {
            // Count characters used by prefix target[0 ... i-1]
            vector<int> rem_count = count;
            for (int j = 0; j < i; j++) {
                rem_count[target[j] - 'a']--;
            }

            // Find the smallest character strictly greater than target[i]
            char min_char = 'a' - 1;
            if (i < (int)target.size()) {
                min_char = target[i];
            }

            int chosen_char = -1;
            for (int c = (min_char - 'a') + 1; c < 26; c++) {
                if (rem_count[c] > 0) {
                    chosen_char = c;
                    break;
                }
            }

            // If a strictly greater character is found
            if (chosen_char != -1) {
                string ans = target.substr(0, i);
                ans += (char)('a' + chosen_char);
                rem_count[chosen_char]--;

                // Append remaining characters in ascending order
                for (int c = 0; c < 26; c++) {
                    while (rem_count[c] > 0) {
                        ans += (char)('a' + c);
                        rem_count[c]--;
                    }
                }
                return ans;
            }
        }

        return ""; // Impossible to make a strictly greater string
    }
};