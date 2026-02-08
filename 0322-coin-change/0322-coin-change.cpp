class Solution {
public:
    int helper(int index, vector<int>& coins, int amount, vector<vector<int>>&dp){
        if(index==0){
            if(amount%coins[index]==0){
                return amount/coins[index];
            }
            else return 1e9;
        }
        if(dp[index][amount]!=-1)return dp[index][amount];
        int not_take=helper(index-1,coins,amount,dp);
        int take=INT_MAX;
        if(coins[index]<=amount){
            take=1+helper(index,coins,amount-coins[index],dp);
        }
        return dp[index][amount]=min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        if(helper(coins.size()-1,coins,amount,dp)==1e9)return -1;
        return helper(coins.size()-1,coins,amount,dp);
    }
};