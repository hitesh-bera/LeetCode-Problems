class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>>mpp;
        mpp.reserve(strs.size());

        for(const string& s : strs){
            string orgnl = s;
            sort(orgnl.begin(), orgnl.end());
            mpp[orgnl].push_back(s);
        }

        vector<vector<string>>ans;
        ans.reserve(mpp.size());

        for(auto &[key, grp] : mpp){
            ans.push_back(grp);
        }

        return ans;
    }
};