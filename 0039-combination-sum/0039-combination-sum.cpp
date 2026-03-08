class Solution {
public:
    void backtrack(int start, vector<int>&candidates, vector<int>&temp, vector<vector<int>>&result, int target, int total){
        if(total==target){
            result.push_back(temp);
            return;
        }
        if(start>=candidates.size()||total>target)return;
        temp.push_back(candidates[start]);
        backtrack(start,candidates,temp,result,target,total+candidates[start]);
        temp.pop_back();
        backtrack(start+1,candidates,temp,result,target,total);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>result;
        backtrack(0,candidates,temp,result,target,0);
        return result;
    }
};