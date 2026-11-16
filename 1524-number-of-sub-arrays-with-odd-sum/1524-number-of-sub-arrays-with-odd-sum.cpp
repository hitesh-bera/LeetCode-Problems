//since current state only depends on the previous state we can manage extra space by keeping track of variables.
class Solution {
public:
    long long mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        int prevOdd = (arr[0] % 2);
        int prevEven = !(arr[0] % 2);

        long long cnt = prevOdd;

        for (int i = 1; i < n; i++) {
            long long curOdd, curEven;
            if (arr[i] % 2) { // odd
                curOdd = 1 + (prevEven) % mod;
                curEven = prevOdd;
            } else { // even
                curOdd = prevOdd;
                curEven = 1 + (prevEven) % mod;
            }

            cnt += curOdd;

            prevOdd = curOdd;
            prevEven = curEven;
        }
        return cnt % mod;
    }
};

/*
class Solution {
public:
    long long mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        vector<long long> oddEndsAt(n, 0), evenEndsAt(n, 0);

        oddEndsAt[0] = (arr[0] % 2);
        evenEndsAt[0] = !(arr[0] % 2);

        for(int i = 1;i < n;i++){
            if(arr[i] % 2){ // odd
                oddEndsAt[i] = 1 + (evenEndsAt[i-1]) % mod;
                evenEndsAt[i] = oddEndsAt[i-1];
            }else{ //even
                oddEndsAt[i] = oddEndsAt[i-1];
                evenEndsAt[i] = 1 + (evenEndsAt[i-1]) % mod;
            }
        }

        long long cnt = 0;
        for(int i = 0;i < n;i++){
            cnt += (oddEndsAt[i] % mod);
        }
        return cnt % mod;
    }
};
*/