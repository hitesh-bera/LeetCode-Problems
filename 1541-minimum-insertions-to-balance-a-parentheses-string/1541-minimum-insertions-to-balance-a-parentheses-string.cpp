class Solution {
public:
    int minInsertions(string s) {
        // s could be valid if there is k left and 2*k right
        int n = s.size();
        string newS = "";
        int operation = 0;
        int i = 0;
        while(i < n){
            if(s[i] == '('){
                newS += s[i];
                i++;
            }else{ // s[i] == ')'
                newS += ")";
                if(i+1 < n && s[i+1] == ')'){
                    i+=2;
                }else{
                    operation++;
                    i++;
                }
            }
        }
        
        i = 0;
        int cnt = 0;
        while(i < newS.size()){
            if(newS[i] == '('){
                cnt++;
            }else{
                cnt--;
            }

            if(cnt < 0){
                operation++;
                cnt = 0;
            }
            i++;
        }
        operation += 2*cnt;
        return operation;
    }
};