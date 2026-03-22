class Solution {
public:
    vector<vector<int>>bridges;
    int timer=0;
    void dfs(int node,int parent,vector<int>&disc,vector<int>&low,vector<bool>&vis,vector<vector<int>>&adj){
        vis[node]=true;
        low[node]=disc[node]=timer++;
        for(auto&it:adj[node]){
            if(it==parent)continue;
            if(!vis[it]){
                dfs(it,node,disc,low,vis,adj);
                low[node]=min(low[node],low[it]);
                if(low[it]>disc[node]){
                    bridges.push_back({it,node});
                }
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>disc(n,-1);
        vector<int>low(n,-1);
        vector<bool>vis(n,false);
        vector<vector<int>>adj(n);
        for(auto&edge:connections){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1,disc,low,vis,adj);
        return bridges;
    }
};