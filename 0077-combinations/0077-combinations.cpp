class Solution {
public:
    void backtrack(int start,vector<int>&temp,vector<vector<int>>&result,int n,int k){
        if(temp.size()==k){
            result.push_back(temp);
            return;
        }
        for(int i=start;i<=n;i++){
            temp.push_back(i);
            backtrack(i+1,temp,result,n,k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>result;
        vector<int>temp;
        backtrack(1,temp,result,n,k);
        return result;
    }
};