class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>dict(wordList.begin(),wordList.end());
        unordered_set<string>beginSet{beginWord};
        unordered_set<string>endSet{endWord};
        unordered_set<string>vis;
        if(dict.count(endWord)==0)return 0;
        int steps=1;
        while(!beginSet.empty() && !endSet.empty()){
            if(endSet.size()<beginSet.size()){
                swap(endSet,beginSet);
            }
            unordered_set<string>nextSet;
            for(string word:beginSet){
                string current=word;
                for(int i=0;i<current.size();i++){
                    char temp=current[i];
                    for(char c='a';c<='z';c++){
                        if(c==temp)continue;
                        current[i]=c;
                        if(endSet.count(current))return steps+1;
                        if(dict.count(current) && !vis.count(current)){
                            nextSet.insert(current);
                            vis.insert(current);
                        }
                    }
                    current[i]=temp;
                }
            }
            beginSet=nextSet;
            steps++;
        }
        return 0;
    }
};