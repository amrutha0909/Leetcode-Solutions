class Solution {
public:
    void backtrack(int index,vector<int>&temp,vector<int>&nums,vector<vector<int>>&result){
        result.push_back(temp);
        for(int i=index;i<nums.size();i++){
            temp.push_back(nums[i]);
            backtrack(i+1,temp,nums,result);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>temp;
        backtrack(0,temp,nums,result);
        return result;
    }
};