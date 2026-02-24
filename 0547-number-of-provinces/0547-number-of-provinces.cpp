class Solution {
public:
    void dfs(int node, vector<vector<int>>&isConnected, vector<bool>&visited){
        visited[node]=true;
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[node][i]&&!visited[i]){
                dfs(i,isConnected,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<bool>visited(V,false);
        int count=0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                count++;
                dfs(i,isConnected,visited);
            }
        }
        return count;
    }
};