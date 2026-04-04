class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        queue<int>q;
        q.push(0);
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        vector<bool>visited(s.size(),false);
        while(!q.empty()){
            int index=q.front();
            q.pop();
            if(visited[index])continue;
            visited[index]=true;
            for(int end=index+1;end<=s.size();end++){
                string sub=s.substr(index,end-index);
                if(st.find(sub)!=st.end()){
                    if(end==s.size())return true;
                    q.push(end);
                }
            }
        }
        return false;
    }
};