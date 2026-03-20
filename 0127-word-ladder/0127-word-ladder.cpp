class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>dictionary(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        dictionary.erase(beginWord);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            string word=it.first;
            int steps=it.second;
            if(word==endWord)return steps;
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(dictionary.count(word)>0){
                        dictionary.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};