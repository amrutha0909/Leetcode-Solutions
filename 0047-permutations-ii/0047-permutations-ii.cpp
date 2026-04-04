class Solution {
public:
    void backtrack(vector<int>&nums, vector<vector<int>>&result, vector<int>&temp,vector<bool>&vis){
        if(temp.size()==nums.size()){
            result.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(vis[i])continue;
            if(i>0 && nums[i]==nums[i-1] && !vis[i-1])continue;
            vis[i]=true;
            temp.push_back(nums[i]);
            backtrack(nums,result,temp,vis);
            temp.pop_back();
            vis[i]=false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>temp;
        vector<bool>vis(nums.size(),false);
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        backtrack(nums,result,temp,vis);
        return result;
    }
};