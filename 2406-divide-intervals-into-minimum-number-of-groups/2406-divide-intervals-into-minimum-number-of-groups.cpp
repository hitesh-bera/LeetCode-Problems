/*
//1. works here, because maxR won't exceed 10^6. but what if it would exceed => approach-2
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int maxR = intervals[0][1];
        for(const auto &interval : intervals){
            maxR = max(maxR, interval[1]);
        }

        vector<int>diff(maxR+2, 0);
        for(const auto &interval : intervals){
            int l = interval[0];
            int r = interval[1];

            diff[l] += 1;
            diff[r + 1] -= 1;
        }

        int maxCnt = diff[0];
        for(int i =1;i<=maxR;i++){
            diff[i] += diff[i-1];

            maxCnt = max(maxCnt, diff[i]);
        }
        return maxCnt;
    }
};
*/

//2. same logic but another extra space instead of diff.

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<vector<int>>diff;
        for(const auto &interval : intervals){
            int l = interval[0];
            int r = interval[1];

            diff.push_back({l,1});
            diff.push_back({r+1,-1});
        }

        sort(diff.begin(),diff.end());

        int maxActiveIntervals = 0;
        int curActiveIntervals = 0;

        for(const auto &p : diff){
            curActiveIntervals += p[1];

            maxActiveIntervals = max(maxActiveIntervals, curActiveIntervals);
        }
        return maxActiveIntervals;
    }
};