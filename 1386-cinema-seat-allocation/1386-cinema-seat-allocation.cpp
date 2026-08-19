class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int>b;
        for(auto v : reservedSeats){
            int row = v[0];
            int s = v[1];
            if(!b.count(row)){
                b[row] = 0;
            }
            if(s == 2 || s == 3){
                b[row] = b[row] | (1 << 0);
            }else if(s == 4 || s == 5){
                b[row] = b[row] | (1 << 1);
            }else if(s == 6 || s == 7){
                b[row] = b[row] | (1 << 2);
            }else if(s == 8 || s == 9){
                b[row] = b[row] | (1 << 3);
            }
        }
        long long cnt = 0;
        for(auto &[row, mask]:b){
            if(mask == 0){
                cnt+=2;
            }else{
                int fi = mask & (1 << 0);
                int se = mask & (1 << 1);
                int th = mask & (1 << 2);
                int fo = mask & (1 << 3);
                if((fi ==0 && se == 0) || (se ==0 && th == 0) || (th ==0 && fo == 0)){
                    cnt++;
                }
            }
        }
        int two = 0;
        int usedRow = b.size();
        two = (n-usedRow)*2;
        return cnt + two;
    }
};

/*
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>>b;
        for(auto v : reservedSeats){
            int row = v[0];
            int s = v[1];
            if(!b.count(row)){
                b[row] = {0,0,0,0};
            }
            if(s == 2 || s == 3){
                b[row][0]++;
            }else if(s == 4 || s == 5){
                b[row][1]++;
            }else if(s == 6 || s == 7){
                b[row][2]++;
            }else if(s == 8 || s == 9){
                b[row][3]++;
            }
        }
        long long cnt = 0;
        for(auto it:b){
            int row = it.first;
            vector<int>v = it.second;
            bool allZero = true;
            for(int s=0;s<4;s++){
                if(v[s] != 0){
                    allZero = false;
                    break;
                }
            }
            if(allZero){
                cnt+=2;
            }else{
                if((v[0] ==0 && v[1] == 0) || (v[1] ==0 && v[2] == 0) || (v[2] ==0 && v[3] == 0)){
                    cnt++;
                }
            }
        }
        int two = 0;
        int usedRow = b.size();
        two = (n-usedRow)*2;
        return cnt + two;
    }
};
*/