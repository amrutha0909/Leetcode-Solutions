class Solution {
public:
    bool dfs(int node,vector<vector<int>>&graph,int color, vector<int>&colors){
        colors[node]=color;
        for(auto it:graph[node]){
            if(colors[it]==-1){
                if(!dfs(it,graph,1-color,colors))return false;
            }
            else if(colors[it]==color)return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>colors(V,-1);
        for(int i=0;i<V;i++){
            if(colors[i]==-1){
                if(!dfs(i,graph,0,colors))return false;
            }
        }
        return true;
    }
};