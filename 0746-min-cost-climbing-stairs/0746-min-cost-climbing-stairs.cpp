class Solution {
public:
    int helper(int index,vector<int>&cost,vector<int>&dp){
        if(index>=cost.size()){
            return 0;
        }
        if(dp[index]!=-1)return dp[index];
        int way1=cost[index]+helper(index+2,cost,dp);
        int way2=cost[index]+helper(index+1,cost,dp);
        return dp[index]=min(way1,way2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(),-1);
        return min(helper(0,cost,dp),helper(1,cost,dp));
    }
};