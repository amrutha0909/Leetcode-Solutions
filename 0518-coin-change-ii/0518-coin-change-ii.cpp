class Solution {
public:
    int helper(int index,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(index==0){
            if(amount%coins[0]==0){
                return 1;
            }
            return 0;
        }
        if(dp[index][amount]!=-1)return dp[index][amount];
        int not_take=helper(index-1,amount,coins,dp);
        int take=0;
        if(amount>=coins[index]){
            take=helper(index,amount-coins[index],coins,dp);
        }
        return dp[index][amount]=take+not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(n-1,amount,coins,dp);
    }
};