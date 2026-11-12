// since storage vector only depends on three previous state, we can replace the
// extra vector by keepin track of the three variable.
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {

        int prev1 = 0, prev2 = 0, prev3 = 0;

        for (int step = 1; step <= n; step++) {

            // from prev step by jump one
            int cur = prev1 + 1 + costs[step - 1];

            // from second prev by jump 2
            if (step > 1)
                cur =
                    min(cur, prev2 + 4 + costs[step - 1]);

            // from third prev by jump 3
            if (step > 2) {
                cur =
                    min(cur, prev3 + 9 + costs[step - 1]);
            }

            prev3 = prev2;
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};

/*
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> minCost(n + 1, INT_MAX);

        minCost[0] = 0;

        for (int step = 1; step <= n; step++) {
            // from prev step by jump one
            minCost[step] =
                min(minCost[step], minCost[step - 1] + 1 + costs[step - 1]);

            // from second prev by jump 2
            if (step > 1)
                minCost[step] =
                    min(minCost[step], minCost[step - 2] + 4 + costs[step - 1]);

            // from third prev by jump 3
            if (step > 2) {
                minCost[step] =
                    min(minCost[step], minCost[step - 3] + 9 + costs[step - 1]);
            }
        }

        return minCost[n];
    }
};
*/