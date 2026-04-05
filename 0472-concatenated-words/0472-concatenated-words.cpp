class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string>st(words.begin(),words.end());
        vector<string>res;
        for(const string&word:words){
            int length=word.size();
            vector<bool>dp(length+1,false);
            dp[0]=true;
            for(int i=1;i<=length;i++){
                for(int j=(i==length)?1:0;!dp[i]&&j<i;j++){
                    dp[i]=dp[j]&&st.count(word.substr(j,i-j));
                }
            }
            if(dp[length])res.push_back(word);
        }
        return res;
    }
};