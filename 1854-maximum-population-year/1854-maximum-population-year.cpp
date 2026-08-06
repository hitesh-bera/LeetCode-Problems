/*
//1. basic idea.
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>diff(102, 0);
        // 1950 -> 0, 1951 -> 1,........, 2050 -> 100
        for(const auto &range : logs){
            int l = range[0] - 1950;
            int r = range[1] - 1950;
            diff[l] += 1;
            diff[r] -= 1;
        }

        for(int i = 1;i<=100;i++){
            diff[i] += diff[i-1];
        }

        int maxPopulationYear = 0;

        for(int i =1;i<= 100;i++){
            if(diff[i] > diff[maxPopulationYear]){
                maxPopulationYear = i;
            }
        }
        return maxPopulationYear + 1950;
    }
};
*/

// 2. single pass approach.
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> diff(102, 0);
        // 1950 -> 0, 1951 -> 1,........, 2050 -> 100
        for (const auto& range : logs) {
            int l = range[0] - 1950;
            int r = range[1] - 1950;
            diff[l] += 1;
            diff[r] -= 1;
        }

        int maxPopulationYear = 0;
        int maxPopulation = 0;
        int curPopulation = 0;

        for (int i = 0; i <= 100; i++) {
            curPopulation += diff[i];
            if (curPopulation > maxPopulation) {
                maxPopulation = curPopulation;
                maxPopulationYear = i;
            }
        }
        return maxPopulationYear + 1950;
    }
};