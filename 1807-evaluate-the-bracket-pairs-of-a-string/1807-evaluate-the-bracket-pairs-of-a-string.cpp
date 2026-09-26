class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mpp;
        for(vector<string> &p : knowledge){
            string key = p[0];
            string val = p[1];

            mpp[key] = val;
        }


        int n = s.size();

        string key = "";

        string ans = "";

        int i = 0;
        while (i < n) {
            if (s[i] == '(') {
                i++;
                key = "";
                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }
                i++;
                (!mpp.count(key)) ? ans += "?" : ans += mpp[key];
            } else {
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
};