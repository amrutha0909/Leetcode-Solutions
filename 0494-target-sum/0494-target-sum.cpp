class Solution {
public:
    int helper(int index,vector<int>&nums,int target, vector<vector<int>>&dp){
        if(index==0){
            if(nums[index]==0&&target==0)return 2;
            if(nums[index]==target||target==0)return 1;
            return 0;
        }
        if(dp[index][target]!=-1)return dp[index][target];
        int not_take=helper(index-1,nums,target,dp);
        int take=0;
        if(nums[index]<=target)take=helper(index-1,nums,target-nums[index],dp);
        return dp[index][target]=take+not_take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int total=0;
        for(int num:nums){
            total+=num;
        }
       
        if((total-target<0)||(total-target)%2)return 0;
        vector<vector<int>>dp(nums.size(),vector<int>(((total-target)/2)+1,-1));
        return helper(nums.size()-1,nums,(total-target)/2,dp);
    }
};