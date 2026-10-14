class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (num * 9 < sum)
            return "";

        string number = "";
        while (sum > 9) {
            number += "9";
            sum -= 9;
        }
        if (sum != 0) {
            number += to_string(sum);
        }
        int temp = number.size(); 
        for (int i = 0; i < num - temp; i++) {
            number += "0";
        }
        return number;
    }
};