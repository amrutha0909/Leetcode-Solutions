class Solution {
public:
    void dfs(int i, int j,vector<vector<char>>&grid, vector<vector<bool>>&visited){
        visited[i][j]=true;
        int n=grid.size();
        int m=grid[0].size();
        vector<int>dX={-1,0,1,0};
        vector<int>dY={0,1,0,-1};
        for(int k=0;k<4;k++){
            int nx=i+dX[k];
            int ny=j+dY[k];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]=='1' &&!visited[nx][ny]){
                dfs(nx,ny,grid,visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]&&grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid,visited);
                }
            }
        }
        return count;
    }
};