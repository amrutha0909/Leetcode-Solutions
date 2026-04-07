class Solution {
public:
    bool dfs(int node,vector<vector<int>>&graph,vector<int>&check,vector<bool>&vis,vector<bool>&pathVis){
        vis[node]=true;
        pathVis[node]=true;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(it,graph,check,vis,pathVis)){
                    check[it]=false;
                    return true;
                }
            }
            else if(pathVis[it]){
                check[it]=false;
                return true;
            }
        }
        pathVis[node]=false;
        check[node]=true;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>check(V,false);
        vector<bool>vis(V,false);
        vector<bool>pathVis(V,false);
        vector<int>ans;
        for(int i=0;i<V;i++){
            dfs(i,graph,check,vis,pathVis);
            if(check[i])ans.push_back(i);
        }
        return ans;
    }
};