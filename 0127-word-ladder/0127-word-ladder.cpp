class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<string>q;
        q.push(beginWord);
        st.erase(beginWord);
        int steps=1;
        while(!q.empty()){
            int len=q.size();
            for(int i=0;i<len;i++){
                string word=q.front();
                q.pop();
                if(word==endWord)return steps;
                for(int i=0;i<word.size();i++){
                    char temp=word[i];
                    for(char c='a';c<='z';c++){
                        word[i]=c;
                        if(st.count(word)){
                            st.erase(word);
                            q.push(word);
                        }
                    }
                    word[i]=temp;
                }
            }
            if(!q.empty())steps++;
        }
        return 0;
    }
};