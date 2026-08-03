class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        
        vector<pair<int,int>>sum;
        for(int i=0;i<n;i++){
            sum.push_back({aliceValues[i]+bobValues[i], i});
        }

        sort(sum.begin(), sum.end(), greater<pair<int,int>>());
        int aliceScore = 0;
        int bobScore = 0;
        for(int i=0;i<n;i++){  
            aliceScore += (i%2 == 0)*aliceValues[sum[i].second];
            bobScore += (i%2 == 1)*bobValues[sum[i].second];
        }
        if(aliceScore > bobScore)return 1;
        else if(aliceScore < bobScore)return -1;
        return 0;
    }
};