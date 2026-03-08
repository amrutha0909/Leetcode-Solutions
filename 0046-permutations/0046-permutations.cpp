class Solution {
public:
    void backtrack(vector<int>&nums, vector<int>&temp, vector<vector<int>>&result){
        if(temp.size()==nums.size()){
            result.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(find(temp.begin(),temp.end(),nums[i])==temp.end()){
                temp.push_back(nums[i]);
                backtrack(nums,temp,result);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>result;
        backtrack(nums,temp,result);
        return result;
    }
};