class Solution {
public:
    unordered_map<int, string>mpp;
    vector<string> addCombination(int i, vector<string> ans){
        vector<string>newAns;

        for(int k = 0;k < ans.size();k++){
            string laters = mpp[i];
            for(int j = 0;j < laters.size();j++){
                string newS = ans[k] + laters[j];
                newAns.push_back(newS);
            }
        }

        return newAns;
    }
    vector<string> f(string digits){
        vector<string> ans = {""};

        for(int i = 0;i < digits.size();i++){
            ans = addCombination(digits[i] - '0', ans);
        }

        return ans;
    }
    vector<string> letterCombinations(string digits) {
        mpp[2] = "abc";
        mpp[3] = "def";
        mpp[4] = "ghi";
        mpp[5] = "jkl";
        mpp[6] = "mno";
        mpp[7] = "pqrs";
        mpp[8] = "tuv";
        mpp[9] = "wxyz";
        return f(digits);
    }
};