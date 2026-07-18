class Solution {
public:
    int n;
    string s;
    unordered_set<string> st;
    vector<int>dp;
    bool f(int i){
        if(i == n)return true;

        if(dp[i] != -1)return (dp[i])? true:false;

        for(int j = i;j<n;j++){
            string cur = s.substr(i,j-i+1);
            if(st.count(cur) && f(j+1)){
                return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string str, vector<string>& wordDict) {
        s = str;
        n = s.size();
        dp.assign(305,-1);
        for (string word : wordDict) {
            st.insert(word);
        }
        return f(0);
    }
};

/*
class Solution {
public:
    int n;
    string s;
    unordered_set<string>st;
    vector<vector<int>>dp;
    bool f(int i,int j){
        if(i == n && j == n)return true;
        if(j == n)return false;

        if(dp[i][j] != -1)return (dp[i][j])? true:false;

        string cur = s.substr(i,j-i+1);
        if(st.count(cur)){
            bool take = f(j+1,j+1);
            bool notTake = f(i,j+1);
            return dp[i][j] = take || notTake;
        }
        return dp[i][j] = f(i,j+1);
    }
    bool wordBreak(string str, vector<string>& wordDict) {
        s = str;
        n = s.size();
        dp.assign(305,vector<int>(305,-1));
        for(string word : wordDict){
            st.insert(word);
        }
        return f(0,0);
    }
};
*/