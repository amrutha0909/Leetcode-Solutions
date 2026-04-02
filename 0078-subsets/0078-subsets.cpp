class Solution {
public:
    void backtrack(int start,vector<vector<int>>&res,vector<int>&nums,vector<int>&temp){
        res.push_back(temp);
        if(temp.size()==nums.size()){
            return;
        }
        for(int i=start;i<nums.size();i++){
            if(temp.empty()||temp.back()!=nums[i])temp.push_back(nums[i]);
            backtrack(i+1,res,nums,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
        backtrack(0,res,nums,temp);
        return res;
    }
};