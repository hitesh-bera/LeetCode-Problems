class Solution {
public:
    vector<string>ans;
    int n;
    void f(string s,int o,int c){
        if(o== n && c == n){
            ans.push_back(s);
            return;
        }
        if(o>n || c>n)return;
        if(o<n) f(s + "(",o+1,c);
        if (c<n && o>c)f(s + ")",o,c+1);
        return;
    }
    vector<string> generateParenthesis(int m) {
        n=m;
        f("",0,0);
        return ans;
    }
};