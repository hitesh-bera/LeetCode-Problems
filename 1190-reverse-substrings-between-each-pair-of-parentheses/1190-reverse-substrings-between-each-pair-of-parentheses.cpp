class Solution {
public:
    int n;
    string f(int &i, string& s) {
        string ans = "";

        while (i < n && s[i] != ')') {

            if (s[i] != '(' && s[i] != ')') {
                ans += s[i++];
            } else if(s[i] == '('){
                i++;
                ans += f(i, s);
                i++;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string reverseParentheses(string s) {
        n = s.size();

        string ans = "";
        
        int i = 0;
        while(i<n){
            if(s[i] == '('){
                i++;
                ans += f(i, s);
                i++;
            }else ans += s[i++];
        }
        return ans;
    }
};
/*
class Solution {
public:
    int n;
    string f(int &i, string& s) {
        
        string ans = "";

        while (i < n && s[i] != ')') {
            if(s[i] == '('){
                i++; 

                string t = f(i, s);
                reverse(t.begin(), t.end());
                ans += t;

                i++;
            }else{
                ans += s[i++];
            }
        }
        return ans;
    }
    string reverseParentheses(string s) {
        n = s.size();
        int i = 0;
        return f(i, s);
    }
};
*/