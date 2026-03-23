class Solution {
public:
    int helper(int index,int n,vector<int>&dp){
        if(index==n-1)return 1;
        if(index==n-2)return 2;
        if(index==n)return 0;
        if(dp[index]!=-1)return dp[index];
        return dp[index]=helper(index+1,n,dp)+helper(index+2,n,dp);
        
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return helper(0,n,dp);
    }
};