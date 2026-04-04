class Solution {
public:
    // int helper(int index,vector<int>&nums,vector<int>&dp){
    //     if(index>=nums.size())return 0;
    //     if(dp[index]!=-1)return dp[index];
    //     int not_take=helper(index+1,nums,dp);
    //     int take=nums[index]+helper(index+2,nums,dp);
    //     return dp[index]=max(take,not_take);
    // }
    int rob(vector<int>& nums) {
        int n=nums.size()-1;
        vector<int>dp(n+1,-1);
        //return helper(0,nums,dp);
        if(nums.size()==1)return nums[0];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<=n;i++){
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[n];
    }
};