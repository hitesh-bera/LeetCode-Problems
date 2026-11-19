class Solution {
public:
    bool isOverlap(int a, int b, int c, int d) { return a <= d && b >= c; }
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int n = intervals.size();

        if (n == 0) {
            return {newInterval};
        }

        int st, end;
        int nst = newInterval[0], nend = newInterval[1];

        int newSt = nst, newEnd = nend;
        int sid = -1, eid = -1;

        for (int i = 0; i < n; i++) {
            st = intervals[i][0];
            end = intervals[i][1];

            if (isOverlap(st, end, nst, nend)) {
                if (sid == -1)
                    sid = i;
                eid = i;
                newSt = min(newSt, st);
                newEnd = max(newEnd, end);
            }
        }

        vector<vector<int>> ans;
        int prevEnd;

        if (sid == -1) { // overlap does not happens, we have to put new
                         // interval at its correct place.
            bool inserted = false;
            for (int i = 0; i < n; i++) {
                if (!inserted && newEnd < intervals[i][0]) {
                    ans.push_back({newSt, newEnd});
                    inserted = true;
                }
                ans.push_back(intervals[i]);
            }
            if (!inserted) { // Belongs at the very end
                ans.push_back({newSt, newEnd});
            }
        } else { // overlap happebs
            for (int i = 0; i < n; i++) {
                if (i == sid) {
                    ans.push_back({newSt, newEnd});
                } else if (i > sid && i <= eid) {
                    continue;
                } else {
                    ans.push_back(intervals[i]);
                }
            }
        }

        return ans;
    }
};