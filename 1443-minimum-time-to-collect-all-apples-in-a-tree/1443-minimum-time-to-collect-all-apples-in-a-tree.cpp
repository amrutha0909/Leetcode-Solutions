class Solution {
public:
    int dfs(int node,int parent,vector<vector<int>>&adj,vector<bool>&hasApple){
        int time=0;
        for(auto it:adj[node]){
            if(it==parent)continue;
            int childTime=dfs(it,node,adj,hasApple);
            if(childTime>0||hasApple[it]){
                time+=childTime+2;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>adj(n);
        for(auto edge:edges){
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(0,-1,adj,hasApple);
    }
};