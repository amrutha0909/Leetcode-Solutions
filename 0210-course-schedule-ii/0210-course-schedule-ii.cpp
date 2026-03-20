class Solution {
public:
    vector<int>res;
    stack<int>stk;
    bool dfs(int node,vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&pathVis){
        visited[node]=true;
        pathVis[node]=true;
        
        for(auto&it:adj[node]){
            if(!visited[it]){
                if(!dfs(it,adj,visited,pathVis))return false;
            }
            else if(pathVis[it])return false;
        }
        pathVis[node]=false;
        stk.push(node);
        return true;
    }
    bool topoSort(int numCourses,vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&pathVis){
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
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>>adj(numCourses);
        for(auto&edge:pre){
            int u=edge[0];
            int v=edge[1];
            adj[v].push_back(u);
        }
        vector<bool>visited(numCourses,false);
        vector<bool>pathVis(numCourses,false);
        if(!topoSort(numCourses,adj,visited,pathVis))return {};
        return res;
    }
};