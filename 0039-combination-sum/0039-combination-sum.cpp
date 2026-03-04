class Solution {
public:
    set<vector<int>>seen;
    void backtrack(int start, vector<int>&candidates, vector<int>&temp, vector<vector<int>>&result, int target){
        if(start==candidates.size() || target<0)return;
        if(target==0){
            if(seen.find(temp)==seen.end()){
                result.push_back(temp);
                seen.insert(temp);
            }     
            return;
        }
        temp.push_back(candidates[start]);
        //include the current element once
        backtrack(start,candidates,temp,result,target-candidates[start]);
        //include the current element multiple times
        backtrack(start,candidates,temp,result,target-candidates[start]);
        //exlude the current element
        temp.pop_back();
        backtrack(start+1,candidates,temp,result,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>result;
        backtrack(0,candidates,temp,result,target);
        return result;
    }
};