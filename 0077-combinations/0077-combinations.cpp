class Solution {
public:
    vector<vector<int>>ans;
    vector<int>cur;
    void f(int st,int n,int k){
        if(cur.size()==k){
            ans.push_back(cur);
            return;
        }
        for(int i = st;i<=n-(k-cur.size())+1;i++){
            cur.push_back(i);

            f(i+1,n,k);

            cur.pop_back();
        }
        return ;
    }
    vector<vector<int>> combine(int n, int k) {
        f(1,n,k);
        return ans;
    }
};