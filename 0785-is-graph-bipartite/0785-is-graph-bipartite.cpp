class Solution {
public:
    bool dfs(int node,int color,vector<vector<int>>&graph,vector<int>&colors){
        colors[node]=color;
        for(auto it:graph[node]){
            if(colors[it]==-1){
                if(!dfs(it,1-color,graph,colors))return false;
            }
            else{
                if(colors[it]==colors[node])return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>colors(V,-1);
        if(dfs(0,0,graph,colors))return true;
        return false;
    }
};