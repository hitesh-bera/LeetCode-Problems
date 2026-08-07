class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        int n = segments.size();

        map<int, long long>diff;

        for (const auto& segment : segments) {
            int l = segment[0];
            int r = segment[1];
            long long val = segment[2];

            diff[l] += val;
            diff[r] -= val;
        }

        vector<vector<long long>> ans;

        int prev = -1;
        long long total = 0;

        for(const auto &[point, netColor] : diff){
            if(prev != -1 && total > 0){
                ans.push_back({prev, point, total});
            }

            total += netColor;
            prev = point;
        }
        return ans;
    }
};