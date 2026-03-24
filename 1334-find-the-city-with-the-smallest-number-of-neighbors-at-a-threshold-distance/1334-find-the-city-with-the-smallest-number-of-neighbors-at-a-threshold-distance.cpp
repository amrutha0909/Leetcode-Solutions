class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            dist[u][v]=w;
            dist[v][u]=w;
        }
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX){
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        int cityCount=n;
        int cityNo=-1;
        for(int city=0;city<n;city++){
            int cnt=0;
            for(int adj=0;adj<n;adj++){
                if(dist[city][adj]<=distanceThreshold)cnt++;
            }
            if(cnt<=cityCount){
                cityCount=cnt;
                cityNo=city;
            }
        }
        return cityNo;
    }
};