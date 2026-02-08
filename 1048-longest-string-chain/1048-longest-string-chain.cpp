class Solution {
public:
    static bool compare(const string&s1, const string&s2){
        return s1.length()<s2.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        unordered_map<string,int>dp;
        int res=0;
        for(string word:words){
            for(int i=0;i<word.size();i++){
                string pre=word.substr(0,i)+word.substr(i+1);
                dp[word]=max(dp[word],dp.find(pre)==dp.end()?1:dp[pre]+1);
            }
            res=max(res,dp[word]);
        }
        return res;
    }
};