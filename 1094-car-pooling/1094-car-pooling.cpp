class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1002, 0);
        for (const auto& range : trips) {
            int pasangers = range[0];
            int l = range[1];
            int r = range[2];

            diff[l] += pasangers;
            diff[r ] -= pasangers;
        }

        int pasangersInsideBus = 0;
        for (int i = 0; i <= 1000; i++) {
            pasangersInsideBus += diff[i];

            if(pasangersInsideBus > capacity)return false;
        }
        return true;
    }
};