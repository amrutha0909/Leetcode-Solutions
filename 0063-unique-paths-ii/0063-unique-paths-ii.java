class Solution {
    public int helper(int i,int j,int[][]dp,int[][]obstacleGrid){
        int n=obstacleGrid.length;
        int m=obstacleGrid[0].length;
        if(i==n-1 && j==m-1)return 1;
        if(i>=n ||j >=m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int way1=0;
        int way2=0;
        if(i+1<n && obstacleGrid[i+1][j]!=1){
            way1=helper(i+1,j,dp,obstacleGrid);
        }
        if(j+1<m && obstacleGrid[i][j+1]!=1){
            way2=helper(i,j+1,dp,obstacleGrid);
        }
        return dp[i][j]=way1+way2;
    }
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int n=obstacleGrid.length;
        int m=obstacleGrid[0].length;
        if(obstacleGrid[0][0]==1 ||obstacleGrid[n-1][m-1]==1)return 0;
        int[][]dp=new int[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=-1;
            }
        }
        return helper(0,0,dp,obstacleGrid);
    }
}