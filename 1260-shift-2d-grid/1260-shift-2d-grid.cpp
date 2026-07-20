class Solution {
public:
    int n;
    int row,col;
    void Reverse(vector<vector<int>>&grid,int st,int end){
        while(st < end){
            int sti = st/col;
            int stj = st%col;
            int endi = end/col;
            int endj = end%col;

            swap(grid[sti][stj],grid[endi][endj]);
            st++;
            end--;
        }
        return;
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(k==0)return grid;
        row = grid.size();
        col = grid[0].size();
        n = row*col;
        k%=n;
        Reverse(grid,0,n-1);
        Reverse(grid,0,k-1);
        Reverse(grid,k,n-1);

        return grid;
    }
};