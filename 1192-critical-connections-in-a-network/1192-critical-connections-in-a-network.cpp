class Solution {
public:
    vector<vector<int>>bridges;
    int timer=0;
    void dfs(int node, int parent, vector<int>&disc, vector<int>&low, vector<bool>&visited,vector<vector<int>>&adj){
        visited[node]=true;
        disc[node]=low[node]=timer++;
        for(int neighbour:adj[node]){
            if(neighbour==parent)continue;
            if(!visited[neighbour]){
                dfs(neighbour,node,disc,low,visited,adj);
                low[node]=min(low[node],low[neighbour]);
                if(low[neighbour]>disc[node]){
                    bridges.push_back({node,neighbour});
                }
            }else{
                //back-edge
                low[node]=min(low[node],low[neighbour]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto&edge:connections){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>disc(n,-1);
        vector<int>low(n,-1);
        vector<bool>visited(n,false);
        dfs(0,-1,disc,low,visited,adj);
        return bridges;
    }
};