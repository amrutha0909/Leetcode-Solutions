class Solution {
public:
    int helper(int i, int j, vector<vector<int>>&grid,vector<vector<int>>&dp){
        int n=grid.size();
        int m=grid[0].size();
        if(i==n-1&&j==m-1)return grid[i][j];
        if(i>=n||j>=m)return 1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        int way1=grid[i][j]+helper(i+1,j,grid,dp);
        int way2=grid[i][j]+helper(i,j+1,grid,dp);
        return dp[i][j]=min(way1,way2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,grid,dp);
    }
};