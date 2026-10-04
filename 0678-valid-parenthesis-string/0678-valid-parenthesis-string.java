class Solution {
    public boolean checkValidString(String s) {
        int min = 0;
        int max = 0;

        for(char ch : s.toCharArray()){
            if(ch == '('){
                min += 1;
                max += 1;
            }else if(ch == ')'){
                min -= 1;
                max -= 1;
            }else{
                min -= 1;
                max += 1;
            }
            if(max < 0)return false;
            min = Math.max(0, min);
        }
        return min == 0;
    }
}
/*
//my own solution.
class Solution {
    public boolean checkValidString(String s) {
        int n = s.length();

        int cnt = 0;
        int star = 0;

        for(int i = 0;i < n;i++){ 
            char ch = s.charAt(i);
            if(ch == '('){
                cnt += 1;
            }else if(ch == '*'){
                star += 1;
            }else{
                if(cnt > 0){
                    cnt -= 1;
                }else{
                    if(star == 0){
                        return false;
                    }
                    star -= 1;
                }
            }
        }

        if(cnt == 0)return true;
        
        cnt = 0; // close - open
        star = 0;
        for(int i = s.length() - 1; i >= 0; i--) {
            char ch = s.charAt(i);
            if(ch == ')'){
                cnt += 1;
            }else if(ch == '*'){
                star += 1;
            }else{
                if(cnt > 0){
                    cnt -= 1;
                }else{
                    if(star == 0){
                        return false;
                    }
                    star -= 1;
                }
            }
        }
        return true;
    }
}
*/