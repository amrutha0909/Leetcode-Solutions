class Solution {
public:
    bool cycle(int node,vector<vector<int>>&adj,vector<bool>&vis,vector<bool>&pathVis){
        vis[node]=true;
        pathVis[node]=true;
        for(auto&it:adj[node]){
            if(!vis[it]){
                if(cycle(it,adj,vis,pathVis))return true;
            }
            else if(pathVis[it]){
                return true;
            }
        }
        pathVis[node]=false;
        return false;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }
        vector<bool>vis(numCourses,false);
        vector<bool>pathVis(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(cycle(i,adj,vis,pathVis))return false;
        }
        return true;
    }
};