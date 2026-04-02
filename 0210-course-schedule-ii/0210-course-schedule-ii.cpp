class Solution {
public:
    stack<int>stk;
    bool dfs(int node,vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&pathVis){
        visited[node]=true;
        pathVis[node]=true;
        for(auto it:adj[node]){
            if(!visited[it]){
                if(!dfs(it,adj,visited,pathVis))return false;
            }
            else {
                if(pathVis[it])return false;
            }
        }
        stk.push(node);
        pathVis[node]=false;
        return true;
    }
    bool topologicalSort(int numCourses,vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&pathVis,vector<int>&res){
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(!dfs(i,adj,visited,pathVis))return false;
            }
            
        }
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto edge:prerequisites){
            int u=edge[0];
            int v=edge[1];
            adj[v].push_back(u);
        }
        vector<bool>visited(numCourses,false);
        vector<bool>pathVis(numCourses,false);
        vector<int>res;
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(!topologicalSort(numCourses,adj,visited,pathVis,res))return {};
            }
        }
        return res;
    }
};