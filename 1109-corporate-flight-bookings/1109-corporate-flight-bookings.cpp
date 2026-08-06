class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 2, 0);
        for (const auto& range : bookings) {
            int l = range[0];
            int r = range[1];
            int seats = range[2];

            diff[l] += seats;
            diff[r + 1] -= seats;
        }
        vector<int>ans(n);
        for (int i = 1; i <= n; i++) {
            diff[i] += diff[i - 1];
            ans[i-1] = diff[i];
        }
        return ans;
    }
};