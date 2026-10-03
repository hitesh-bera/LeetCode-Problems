class Solution {
    public int longestValidParentheses(String s) {
        int n = s.length();

        int[] dp = new int[n];
        //state of the dp: the length(not max length) of the valid parentheses ends at i

        int maxLen = 0;

        for (int i = 1; i < n; i++) {
            if (s.charAt(i) == ')' && s.charAt(i - 1) == '(') {
                dp[i] = 2 + (i - 2 >= 0 ? dp[i - 2] : 0);
            } else if (s.charAt(i) == ')' && s.charAt(i - 1) == ')') { //try to find the matching of the s[i-1]
                int prevBlockLen = dp[i - 1];
                int stChar = i - prevBlockLen; //starting char of the prev block

                if (stChar - 1 >= 0 && s.charAt(stChar - 1) == '(') {
                    dp[i] = 2 + dp[i - 1] + (((stChar - 2 >= 0)&& (s.charAt(stChar - 2) == ')')) ? dp[stChar - 2] : 0);
                }
            }
            maxLen = Math.max(maxLen, dp[i]);
        }
        return maxLen;
    }
}
/*
//1. traverse from both side one by one
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        
        int maxLen = 0;
        int left = 0;
        int right = 0;

        for(char ch : s){
            if(ch == '('){
                left++;
            }else{
                right++;
            }

            if(right > left){
                left = 0;
                right = 0;
            }else if(left == right){
                maxLen = max(maxLen, 2*left);
            }
        }

        left = 0;
        right = 0;

        for(int i = n-1;i>=0;i--){
            if(s[i] == '('){
                left++;
            }else{
                right++;
            }

            if(right < left){
                left = 0;
                right = 0;
            }else if(left == right){
                maxLen = max(maxLen, 2*left);
            }
        }
        return maxLen;
    }
};
*/