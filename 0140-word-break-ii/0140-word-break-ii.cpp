class Solution {
public:

    void backtrack(int start,string s,string curr,vector<string>&result,unordered_set<string>&st){
        if(start==s.length()){
            result.push_back(curr);
            return;
        }
        for(int end=start+1;end<=s.size();end++){
            string word=s.substr(start,end-start);
            if(st.find(word)!=st.end()){
                string original=curr;
                if(!curr.empty())curr+=" ";
                curr+=word;
                backtrack(end,s,curr,result,st);
                curr=original;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        vector<string>result;
        string curr="";
        backtrack(0,s,curr,result,st);
        return result;
    }
};