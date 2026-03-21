class Solution {
public:
    void dfs(int x, int y,vector<vector<int>>&grid, vector<vector<bool>>&vis){
        vis[x][y]=true;
        int n=grid.size();
        int m=grid[0].size();
        vector<int>dX={-1,0,1,0};
        vector<int>dY={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nx=x+dX[i];
            int ny=y+dY[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&!vis[nx][ny]&&grid[nx][ny]==1)dfs(nx,ny,grid,vis);
            
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            if(!vis[i][0]&&grid[i][0]==1)dfs(i,0,grid,vis);
            if(!vis[i][m-1]&&grid[i][m-1]==1)dfs(i,m-1,grid,vis);
        }
        for(int j=0;j<m;j++){
            if(!vis[0][j]&&grid[0][j]==1)dfs(0,j,grid,vis);
            if(!vis[n-1][j]&&grid[n-1][j]==1)dfs(n-1,j,grid,vis);
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]==1)count++;
            }
        }
        return count;
    }
};