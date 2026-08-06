class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 2, 0);

        for (const auto& shift : shifts) {
            int l = shift[0];
            int r = shift[1];
            int val = shift[2];
            if (val == 0)
                val = -1;

            diff[l] += val;
            diff[r + 1] -= val;
        }

        for (int i = 0; i < s.size(); i++) {
            if (i > 0)
                diff[i] += diff[i - 1];
            int d = diff[i];

            int shift = ((d % 26) + 26) % 26;
            int id = (s[i] - 'a' + shift)%26;

            s[i] = char(id + 'a');
        }
        return s;
    }
};