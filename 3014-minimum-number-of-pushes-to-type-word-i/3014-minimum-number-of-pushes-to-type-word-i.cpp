class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int num = 8;
        int add = 1;
        int cnt = 0;
        while(true){
            if(num <= n){
                cnt += 8*add;
                add++;
                num += 8;
            }else{
                cnt += (n-num+8)*add;
                break;
            }
        }
        return cnt;
    }
};