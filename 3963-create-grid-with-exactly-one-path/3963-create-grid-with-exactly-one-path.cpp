class Solution {
public:
    vector<string> createGrid(int m, int n) {
            vector<string> path;


        string s(n - 1, '#');
        string l(n, '.');
        for(int i = 0;i < m;i++){
            if(i == m-1){
                path.push_back(l);
            }else{
                path.push_back('.' + s);
            }
        }
        return path;
    }
};