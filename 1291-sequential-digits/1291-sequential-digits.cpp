class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> sequential_numbers;
        long long r = 11;
        long long num = 12, prev_first = 12;
        for (int i = 8; i >= 1; i--) {
            for (int j = 1; j <= i; j++) {
                sequential_numbers.push_back(num);
                num += r;
            }
            num = 10LL*prev_first + ((prev_first % 10) + 1);
            prev_first = num;
            r = 10LL*r + 1;
        }
        vector<int>ans;
        for(int i=0;i<36;i++){
            if(sequential_numbers[i] >= low && sequential_numbers[i] <= high)
                ans.push_back(sequential_numbers[i]);
        }
        return ans;
    }
};