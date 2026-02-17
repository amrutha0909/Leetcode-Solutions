class Solution {
public:
    int helper(int index, int k, int buy, vector<int>&prices, vector<vector<vector<int>>>&dp){
        if(index==prices.size()||k==0)return 0;
        if(dp[index][buy][k]!=-1)return dp[index][buy][k];
        int profit;
        if(buy){
            profit=max(-prices[index]+helper(index+1,k,0,prices,dp),helper(index+1,k,1,prices,dp));
        }
        else{
            profit=max(prices[index]+helper(index+1,k-1,1,prices,dp),helper(index+1,k,0,prices,dp));
        }
        return dp[index][buy][k]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return helper(0,k,1,prices,dp);
    }
};