class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int count=0;
        vector<vector<int>>dist(n,vector<int>(k+2,INT_MAX));
        dist[src][0]=0;
        vector<vector<pair<int,int>>>adj(n);
        for(auto&flight:flights){
            int u=flight[0];
            int v=flight[1];
            int w=flight[2];
            adj[u].push_back({v,w});
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,src,0});
        while(!pq.empty()){
            count++;
            auto it=pq.top();
            pq.pop();
            int u=it[1];
            int dis=it[0];
            int stops=it[2];
            if(u==dst)return dis;
            if(stops<=k){
                for(auto&it:adj[u]){
                    int v=it.first;
                    int w=it.second;
                    if(dis+w<dist[v][stops+1]){
                        dist[v][stops+1]=dis+w;
                        pq.push({dist[v][stops+1],v,stops+1});
                    }
                }
            }    
        }
        return -1;
    }
};