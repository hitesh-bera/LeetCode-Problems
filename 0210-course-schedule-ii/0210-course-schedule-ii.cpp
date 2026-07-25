class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>in(numCourses,0);

        for(const auto &course : prerequisites){
            int u = course[1];
            int v = course[0];
            adj[u].push_back(v);
            in[v]++;
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        vector<int> order;

        while(!q.empty()){
            int top = q.front();
            q.pop();

            order.push_back(top);

            for(int neibr : adj[top]){
                in[neibr]--;

                if(in[neibr] == 0){
                    q.push(neibr);
                }
            }
        }
        if(order.size() != numCourses){
            return {};
        }
        return order;
    }
};