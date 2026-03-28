class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it[1];
            int dis=it[0];
            for(auto x:adj[node]){
                int neigh=x.first;
                int w=x.second;
                if(dist[neigh]>dis+w){
                    dist[neigh]=dis+w;
                    pq.push({dist[neigh],neigh});
                }
            }
        }
        int max_time=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX)return -1;
            max_time=max(max_time,dist[i]);
        }
        return max_time;
    }
};