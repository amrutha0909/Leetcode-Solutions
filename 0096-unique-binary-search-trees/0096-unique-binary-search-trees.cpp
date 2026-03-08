class Solution {
public:
    void helper(vector<int>&dp, int n){
        int total=0;
        for(int i=1;i<=n;i++){
            total+=dp[i-1]*dp[n-i];
        }
        dp[n]=total;
    }
    int numTrees(int n) {
        vector<int>dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            helper(dp,i);
        }
        return dp[n];
    }
};