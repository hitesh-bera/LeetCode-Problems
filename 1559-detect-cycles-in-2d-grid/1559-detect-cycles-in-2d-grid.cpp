class Solution {
public:
    int row,col;
    bool isvalid(int i,int j){
        return i>=0 && j>=0 && i<row && j<col;
    }
    bool dfs(int ui,int uj,int pi,int pj,vector<vector<char>>& grid,vector<vector<bool>>& vis){
        vis[ui][uj] = true;
        int dr[4] = {1,0,-1,0};
        int dc[4] = {0,1,0,-1};
        for(int k=0;k<4;k++){
            int vi = ui + dr[k];
            int vj = uj + dc[k];
            if(!isvalid(vi,vj))continue;
            if(grid[vi][vj] != grid[ui][uj])continue;
            if(!vis[vi][vj]){
                if(dfs(vi,vj,ui,uj,grid,vis))return true;
            }else if(vi!=pi || vj!=pj)return true;
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();
        vector<vector<bool>>vis(row,vector<bool>(col,false));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!vis[i][j]){
                    if(dfs(i,j,-1,-1,grid,vis))return true;
                }
            }
        }
        return false;
    }
};