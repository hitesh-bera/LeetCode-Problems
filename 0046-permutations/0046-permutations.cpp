class Solution {
public:
    vector<vector<int>> ans; 
    int n;
    void f(int i, vector<int>&nums) {
        if (i == n) {
            ans.push_back(nums);  
            return; 
        }
        for(int j=i;j<n;j++){
            swap(nums[i],nums[j]);

            f(i+1,nums);
            swap(nums[i],nums[j]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        f(0,nums);
        return ans;
    }
};

// class Solution {
// public:
//     vector<vector<int>> f(vector<int> arr) {
//         if (arr.size() == 1)
//             return {{arr[0]}};
//         vector<vector<int>> result;
//         for (int i = 0; i < arr.size(); i++) {
//             int num = arr[0];
//             arr.erase(arr.begin() + 0);
//             vector<vector<int>> child_permutations = f(arr);
//             for (auto permutation : child_permutations) {
//                 permutation.push_back(num);
//                 result.push_back(permutation);
//             }
//             arr.push_back(num);
//         }
//         return result;
//     }
//     vector<vector<int>> permute(vector<int>& nums) { return f(nums); }
// };