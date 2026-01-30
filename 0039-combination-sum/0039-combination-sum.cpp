class Solution {
public:
    void backtrack(vector<int>&candidates, int target, int total, int start, vector<int>&temp, vector<vector<int>>&result){
        if(total==target){
            result.push_back(temp);
            return;
        }
        if(start>=candidates.size()||total>target)return;
        temp.push_back(candidates[start]);
        backtrack(candidates,target,total+candidates[start],start,temp,result);
        temp.pop_back();
        backtrack(candidates,target,total,start+1,temp,result);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>temp;
        backtrack(candidates,target,0,0,temp,result);
        return result;
    }
};