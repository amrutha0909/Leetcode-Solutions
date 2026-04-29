class Solution {
    public int helper(int index,int[]coins,int[][]dp,int amount){
        if(amount==0)return 1;
        if(index==coins.length-1){
            if(amount%coins[index]==0)return 1;
            else return 0;
        }
        if(dp[index][amount]!=-1)return dp[index][amount];
        int not_take=helper(index+1,coins,dp,amount);
        int take=0;
        if(coins[index]<=amount)take=helper(index,coins,dp,amount-coins[index]);
        return dp[index][amount]=take+not_take;
    }
    public int change(int amount, int[] coins) {
        int[][]dp=new int[coins.length][amount+1];
        for (int i = 0; i < coins.length; i++) {
            Arrays.fill(dp[i], -1);
        }
        return helper(0,coins,dp,amount);
    }
}