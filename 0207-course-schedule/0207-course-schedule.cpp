class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.empty()) return true;        
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for (const auto &edge : prerequisites) {
            int u = edge[1];
            int v = edge[0];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int topoSize = 0;
        while(!q.empty()){
            int top = q.front();
            q.pop();

            topoSize++;
            for(int neibr : adj[top]){
                indegree[neibr]--;
                if(indegree[neibr] == 0){
                    q.push(neibr);
                }
            }
        }
        return numCourses == topoSize;
    }
};