class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>wordMap;
        for(string word:words){
            wordMap[word]++;
        }
        vector<int>result;
        
        int left=0;
        int window=words[0].size();
        int wordCount=words.size();
        for(int offset=0;offset<window;offset++){
            int left=offset;
            int right=offset;
            int count=0;
            unordered_map<string,int>currMap;
            while(right+window<=s.length()){
                string word=s.substr(right,window);
                right+=window;
                if(wordMap.count(word)>0){
                    currMap[word]++;
                    count++;
                    while(currMap[word]>wordMap[word]){
                        string leftWord=s.substr(left,window);
                        currMap[leftWord]--;
                        left+=window;
                        count--;
                    }
                    if(count==wordCount)result.push_back(left);
                }
                else{
                    currMap.clear();
                    count=0;
                    left=right;
                }

            }
        }
        return result;

    }
};