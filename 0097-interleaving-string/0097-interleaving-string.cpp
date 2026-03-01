class Solution {
public:
    bool helper(int i, int j, string s1, string s2, string s3, vector<vector<int>>&dp){
        if(i==s1.size() && j==s2.size())return true;
        if(dp[i][j]!=-1)return dp[i][j];
        bool ans=false;
        if(i<s1.size() && s1[i]==s3[i+j]){
            ans=helper(i+1,j,s1,s2,s3,dp);
        }
        if(!ans && j<s2.size() && s2[j]==s3[i+j]){
            ans=helper(i,j+1,s1,s2,s3,dp);
        }
        return dp[i][j]=ans;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length();
        int m=s2.length();
        if(n+m!=s3.length())return false;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(0,0,s1,s2,s3,dp);
    }
};