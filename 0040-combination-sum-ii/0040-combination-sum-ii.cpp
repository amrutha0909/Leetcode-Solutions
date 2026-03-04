class Solution {
public:
    void backtrack(int start, vector<int>&candidates, vector<int>&temp, vector<vector<int>>&result, int target){    
        if(target==0){
            result.push_back(temp);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(i>start && candidates[i]==candidates[i-1])continue;
            temp.push_back(candidates[i]);
            backtrack(i+1,candidates,temp,result,target-candidates[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        vector<vector<int>>result;
        backtrack(0,candidates,temp,result,target);
        return result;
    }
};