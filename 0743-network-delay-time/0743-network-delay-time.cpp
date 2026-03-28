class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>>dist(n+1,vector<int>(n+1,INT_MAX));
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            dist[u][v]=w;
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            dist[i][i]=0;
        }
        for(int a=1;a<=n;a++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(dist[i][a]!=INT_MAX && dist[a][j]!=INT_MAX && dist[i][a]+dist[a][j]<dist[i][j]){
                        dist[i][j]=dist[i][a]+dist[a][j];
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dist[k][i] == INT_MAX) return -1; 
            if(dist[k][i]!=INT_MAX){
                ans=max(ans,dist[k][i]);
            }
        }
        return ans==INT_MIN?-1:ans;
    }
};