class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        bool alreadySorted = true;
        for (int i = 1; i < n; i++) {
            if (s[i] < s[i - 1]) {
                alreadySorted = false;
            }
        }

        if (alreadySorted)
            return 0;
        if (n == 2)
            return -1;

        char mini = *min_element(s.begin(), s.end());
        char maxi = *max_element(s.begin(), s.end());

        int mini_cnt = count(s.begin(), s.end(), mini);
        int maxi_cnt = count(s.begin(), s.end(), maxi);

        if (s[0] == maxi && maxi_cnt == 1 && s[n - 1] == mini && mini_cnt == 1)
            return 3;
        if (s[0] == mini || s[n - 1] == maxi)
            return 1;
        return 2;
    }
};

/*
class Solution {
public:
    int minOperations(string s) {

        int n = s.size();

        int maxi = 90;
        int mini = 200;

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, int(s[i]));
            mini = min(mini, int(s[i]));
        }

        bool alreadySorted = true;
        for (int i = 1; i < n; i++) {
            if (s[i] < s[i - 1]) {
                alreadySorted = false;
            }
        }

        bool lastPartSorted = true;
        for(int i = 2;i < n;i++){
            if(s[i] < s[i-1]){
                lastPartSorted = false;
                break;
            }
        }

        bool firstPartSorted = true;
        for(int i = 1;i < n-1;i++){
            if(s[i] < s[i-1]){
                firstPartSorted = false;
                break;
            }
        }

        if (alreadySorted)
            return 0;
        if (n == 2)
            return -1;
        if (s[0] == mini || s[n - 1] == maxi)
            return 1;
        if(s[0] == maxi && s[n-1] == mini)
            return 1 + !firstPartSorted + !lastPartSorted;
        return 2;

    }
};

*/