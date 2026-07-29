class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(const auto &time : times){
            int u = time[0];
            int v = time[1];
            int wt = time[2];
            adj[u].push_back({v,wt});
        }

        vector<int>dist(n+1,INT_MAX);
        vector<bool>visited(n+1, false);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;

        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()){
            const auto p = pq.top();
            pq.pop();
            int top = p.second;
            int d = p.first;

            if(visited[top])continue;

            visited[top] = true;

            for(const auto &[neibr, wt] : adj[top]){
                if(dist[neibr] > wt + d){
                    dist[neibr] = d + wt;
                    pq.push({dist[neibr], neibr});
                }
            }
        }
        int time = -1;
        for(int i=1;i<=n;i++){
            if(!visited[i])return -1;
            time = max(time, dist[i]);
        }
        return time;
    }
};