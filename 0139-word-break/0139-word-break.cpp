class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dictionary(wordDict.begin(),wordDict.end());
        const int length=s.length();
        vector<bool>dp(length+1);
        dp[0]=true;
        for(int i=1;i<=length;i++){
            for(int j=0;!dp[i]&&j<i;j++){
                dp[i]=dp[j]&&dictionary.count(s.substr(j,i-j));
            }
        }
        if(dp[length]){
            return true;
        }
        return false;
    }
};