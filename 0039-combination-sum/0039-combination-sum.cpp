class Solution {
public:
    void backtrack(int start,vector<int>&nums,vector<vector<int>>&result,vector<int>&temp,int sum,int target){
        if(sum==target){
            result.push_back(temp);
            return;
        }
        if(start>=nums.size()||sum>target)return;
        temp.push_back(nums[start]);
        backtrack(start,nums,result,temp,sum+nums[start],target);
        temp.pop_back();
        backtrack(start+1,nums,result,temp,sum,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>result;
        vector<int>temp;
        backtrack(0,nums,result,temp,0,target);
        return result;
    }
};