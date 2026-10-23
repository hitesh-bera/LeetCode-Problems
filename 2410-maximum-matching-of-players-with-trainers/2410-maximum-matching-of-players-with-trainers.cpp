class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int p = players.size();
        int t = trainers.size();

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int cnt = 0;

        int i = 0;
        int j = 0;
 
        while(i < p && j < t){
            while(j < t && players[i] > trainers[j]){
                j++;
            }
            if(j >= t)break;
            cnt++;
            i++;
            j++;
        }
        return cnt;
    }
};