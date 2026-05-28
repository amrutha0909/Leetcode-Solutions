class Solution {
    public int helper(int i,int j,int[][]dp,int[][]grid){
        int n=grid.length;
        int m=grid[0].length;
        if(i>=n||j>=m)return (int)1e9;
        if(i==n-1 && j==m-1)return grid[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int way1=grid[i][j]+helper(i+1,j,dp,grid);
        int way2=grid[i][j]+helper(i,j+1,dp,grid);
        return dp[i][j]=Math.min(way1,way2);
    }
    public int minPathSum(int[][] grid) {
        int n=grid.length;
        int m=grid[0].length;
        int[][]dp=new int[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=-1;
            }
        }
        return helper(0,0,dp,grid);
    }
}