class Solution {
public:
    int n,m;
    void dfs(int r,int c,vector<vector<int>>&heights, vector<vector<bool>>&vis){
        vector<int>dX={-1,0,1,0};
        vector<int>dY={0,1,0,-1};
        for(int k=0;k<4;k++){
            int nx=r+dX[k];
            int ny=c+dY[k];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&heights[nx][ny]>=heights[r][c] && !vis[nx][ny]){
                vis[nx][ny]=true;
                dfs(nx,ny,heights,vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();
        vector<vector<int>>result;
        vector<vector<bool>>paciVis(n,vector<bool>(m,false));
        vector<vector<bool>>atlanVis(n,vector<bool>(m,false));
        // queue<pair<int,int>>pq;
        // queue<pair<int,int>>aq;
        for(int i=0;i<n;i++){
            //pq.push({i,0});
            paciVis[i][0]=true;
            dfs(i,0,heights,paciVis);
        }
        for(int j=0;j<m;j++){
            //pq.push({0,j});
            paciVis[0][j]=true;
            dfs(0,j,heights,paciVis);
        }
        for(int i=0;i<n;i++){
            // aq.push({i,m-1});
            atlanVis[i][m-1]=true;
            dfs(i,m-1,heights,atlanVis);
            
        }
        for(int j=0;j<m;j++){
            // aq.push({n-1,j});
            atlanVis[n-1][j]=true;
            dfs(n-1,j,heights,atlanVis);
        }
        // bfs(pq,heights,paciVis);
        // bfs(aq,heights,atlanVis);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(paciVis[i][j]&&atlanVis[i][j])result.push_back({i,j});
            }
        }
        return result;
    }
};