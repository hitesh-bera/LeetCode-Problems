class Solution {
public:
    int n;
    bool isvalid(int i,int j){
        return i>=0 && j>=0 && i<n && j<n;
    }
    int countOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2, int row_shift,int col_shift){
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int img1i = i + row_shift;
                int img1j = j + col_shift;
                if(isvalid(img1i, img1j)&&img1[img1i][img1j] == img2[i][j] && img1[img1i][img1j] == 1)cnt++;
            }
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        n = img1.size();
        int maxOverlap = 0;
        for(int row_shift = (n*(-1))+1;row_shift<n;row_shift++){
            for(int col_shift=(n*(-1))+1;col_shift<n;col_shift++){
                maxOverlap = max(maxOverlap, countOverlap(img1, img2, row_shift, col_shift));
            }
        }
        return maxOverlap;
    }
};