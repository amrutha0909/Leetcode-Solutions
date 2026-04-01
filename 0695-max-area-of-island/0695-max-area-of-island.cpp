class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&visited,int&count){
        int n=grid.size(),m=grid[0].size();
        visited[i][j]=true;
        count++;
        vector<int>dX={-1,0,1,0};
        vector<int>dY={0,1,0,-1};
        for(int k=0;k<4;k++){
            int nx=i+dX[k];
            int ny=j+dY[k];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&!visited[nx][ny]&&grid[nx][ny]==1){
                dfs(nx,ny,grid,visited,count);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int maxArea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&!visited[i][j]){
                    int area=0;
                    dfs(i,j,grid,visited,area);
                    maxArea=max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
};