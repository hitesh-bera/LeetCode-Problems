class Solution {
public:
    int n;
    vector<vector<int>>arr;
    int f(int target,unordered_map<int,int>&indexof){
        int left = 0,right = n-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(arr[mid][0] >= target)right = mid-1;
            else left = mid+1;
        }
        if(left == n)return -1;
        return indexof[arr[left][0]];
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        arr = intervals;
        n = arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<int,int>indexof;
        for(int i=0;i<n;i++){
            indexof[intervals[i][0]] = i;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            int target = intervals[i][1];
            int id = f(target,indexof);
            ans.push_back(id);
        }
        return ans;
    }
};