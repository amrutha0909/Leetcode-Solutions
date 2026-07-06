class Solution {
public:
    int helper(int i,int n,vector<int>&dp){
        if(i==n)return 0;
        if(i==n-1)return 1;
        if(i==n-2)return 2;
        if(dp[i]!=-1)return dp[i];
        int way1=helper(i+1,n,dp);
        int way2=helper(i+2,n,dp);
        return dp[i]=way1+way2;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return helper(0,n,dp);
    }
};