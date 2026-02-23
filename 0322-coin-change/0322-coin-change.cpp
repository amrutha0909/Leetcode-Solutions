class Solution {
public:
    const int INF = 1e9;
    int helper(int index, int amount, vector<int>&coins,vector<vector<int>>&dp){
        if(index==coins.size()-1){
            if(amount%coins[index]==0){
                return amount/coins[index];
            }
            else return INF;
        }
        if(dp[index][amount]!=-1)return dp[index][amount];
        int not_take=helper(index+1,amount,coins,dp);
        int take=INT_MAX;
        if(coins[index]<=amount){
            take=1+helper(index,amount-coins[index],coins,dp);
        }
        return dp[index][amount]=min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans = helper(0, amount, coins, dp);
        return (ans >= INF) ? -1 : ans;
    }
};