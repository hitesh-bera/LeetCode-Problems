class Solution {
public:
    int dSum(string s){
        int sum = 0;
        for(char ch : s){
            sum += (ch - '0');
        }
        return sum;
    }
    string digitSum(string s, int k) {
        if(s.size() <= k)
            return s;

        string prev = s;

        while(prev.size() > k){
            string cur = "";
            for(int i = 0;i < prev.size();i += k){
                int mnLen = min(k, (int)prev.size() - i);
                string num = prev.substr(i, mnLen);
                int sum = dSum(num);

                cur += to_string(sum);
            }
            prev = cur;
        }
        return prev;
    }
};