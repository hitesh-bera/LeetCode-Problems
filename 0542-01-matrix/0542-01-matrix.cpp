class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>>d(row, vector<int>(col, INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!mat[i][j]){
                    d[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        int dr[4] = {0,1,0,-1};
        int dc[4] = {1,0,-1,0};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr >=0 && nr < row && nc >= 0 && nc < col && d[nr][nc] == INT_MAX){
                    d[nr][nc] = d[r][c] + 1;
                    q.push({nr,nc});
                }
            }
        }
        return d;
    }
};