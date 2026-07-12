class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>temp = arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int>rank;
        int r = 1;
        for(auto x : temp){
            if(!rank.count(x)){
                rank[x] = r++;
            }
        }
        for(auto &x:arr){
            x= rank[x];
        }
        return arr;
    }
};