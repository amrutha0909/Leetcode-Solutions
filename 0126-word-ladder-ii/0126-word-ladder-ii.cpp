class Solution {
public:
    void dfs(string word, string beginWord, unordered_map<string,vector<string>>&parent, vector<string>&path, vector<vector<string>>&res){
        if(word==beginWord){
            reverse(path.begin(),path.end());
            res.push_back(path);
            reverse(path.begin(),path.end());
        }
        for(string p:parent[word]){
            path.push_back(p);
            dfs(p,beginWord,parent,path,res);
            path.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>dict(wordList.begin(),wordList.end());
        vector<vector<string>>res;
        if(!dict.count(endWord))return res;
        unordered_map<string,vector<string>>parent;
        queue<string>q;
        q.push(beginWord);
        unordered_set<string>visited;
        visited.insert(beginWord);
        bool found=false;
        while(!q.empty() && !found){
            int size=q.size();
            unordered_set<string>levelVisited;
            while(size--){
                string word=q.front();
                q.pop();
                string temp=word;
                for(int i=0;i<temp.size();i++){
                    char original=temp[i];
                    for(char c='a';c<='z';c++){
                        temp[i]=c;
                        if(dict.count(temp) && !visited.count(temp)){
                            if(!levelVisited.count(temp)){
                                q.push(temp);
                                levelVisited.insert(temp);
                            }
                            parent[temp].push_back(word);
                            if(temp==endWord){
                                found=true;
                            }
                        }
                    }
                    temp[i]=original;
                }
            }
            for(string w:levelVisited){
                visited.insert(w);
            }
        }
        if(found){
            vector<string>path;
            path.push_back(endWord);
            dfs(endWord,beginWord,parent,path,res);
        }
        return res;
    }
};