class Solution {
public:
    int row, col;
    bool isvalid(int i, int j) {
        return i >= 0 && j >= 0 && i < row && j < col;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        if(image[sr][sc] == color)return image;
        row = image.size(), col = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int old_color = image[sr][sc];
        image[sr][sc] = color;

        int dr[4] = {1, 0, -1, 0}, dc[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [ui, uj] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int vi = ui + dr[k], vj = uj + dc[k];
                if (isvalid(vi, vj) && image[vi][vj] == old_color) {
                    q.push({vi, vj});
                    image[vi][vj] = color;
                }
            }
        }
        return image;
    }
};