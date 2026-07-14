class Solution {
public:
    int row,col;
    bool isvalid(int i,int j){
        return i>=0 && j>=0 && i<row && j<col;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        queue<tuple<int, int, int>>q; // {i,j,level}
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                    visited[i][j] = true;
                }
            }
        }
        vector<int> dr = {1,0,-1,0}, dc = {0,1,0,-1};
        int max_level=0;
        while(!q.empty()){
            auto [ui, uj, cur_level] = q.front();
            q.pop();
            max_level = max(max_level,cur_level);
            for(int k = 0;k<4;k++){
                int new_i = ui + dr[k],new_j = uj + dc[k];
                if(isvalid(new_i,new_j) && !visited[new_i][new_j] && grid[new_i][new_j] == 1){
                    grid[new_i][new_j] = 2;
                    visited[new_i][new_j] = true;
                    q.push({new_i,new_j,cur_level+1});
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return max_level;
    }
};