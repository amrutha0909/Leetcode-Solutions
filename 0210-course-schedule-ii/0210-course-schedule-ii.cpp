class Solution {
public:
    vector<int>result;
    stack<int>stk;
    bool dfs(int node,vector<vector<int>>&adj,vector<bool>&visited, vector<bool>&pathVis){
        visited[node]=true;
        pathVis[node]=true;
        
        for(auto it:adj[node]){
            if(!visited[it]){
                if(!dfs(it,adj,visited,pathVis))return false;
            }
            else{
                if(pathVis[it])return false;
            }
        }

        pathVis[node]=false;
        stk.push(node);
        return true;
    }
    bool topologicalSort(int numCourses, vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&pathVis){
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(!dfs(i,adj,visited,pathVis))return false;
            }
        }
        while(!stk.empty()){
            result.push_back(stk.top());
            stk.pop();
        }
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>pathVis(numCourses,false);
        vector<bool>visited(numCourses,false);
        vector<vector<int>>adj(numCourses);
        for(auto edge:prerequisites){
            int u=edge[0];
            int v=edge[1];
            adj[v].push_back(u);
        }
        if(!topologicalSort(numCourses,adj,visited,pathVis))return {};
        return result;
    }
};