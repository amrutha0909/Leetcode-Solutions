class Solution {
public:
    void backtrack(int index,vector<int>&nums,vector<vector<int>>&result,vector<int>&temp){
        result.push_back(temp);
        for(int i=index;i<nums.size();i++){
            if(i>index&&nums[i]==nums[i-1])continue;
            temp.push_back(nums[i]);
            backtrack(i+1,nums,result,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;
        vector<int>temp;
        backtrack(0,nums,result,temp);
        return result;
    }
};