class Solution {
public:
    int count=0;
    void helper(int i, int j, int remaining, vector<vector<int>>&grid, vector<vector<bool>>&visited){       
        int n=grid.size();
        int m=grid[0].size();
        if(grid[i][j]==2){
            if(remaining==0)count++;
            return;
        }
        visited[i][j]=true;
        vector<int>dX={-1,0,1,0};
        vector<int>dY={0,1,0,-1};
        for(int k=0;k<4;k++){
            int nx=i+dX[k];
            int ny=j+dY[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!=-1 && !visited[nx][ny]){
                helper(nx,ny,remaining-1,grid,visited);
            }
        }
        visited[i][j]=false;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int startX,startY;
        int remaining=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    startX=i;
                    startY=j;
                }
                if(grid[i][j]!=-1){
                    remaining++;
                }
            }
        }
        helper(startX,startY,remaining-1,grid,visited);
        return count;
    }
};