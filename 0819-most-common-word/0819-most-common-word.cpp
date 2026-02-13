class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string word="";
        unordered_map<string,int>mpp;
        unordered_set<string>s(banned.begin(),banned.end());
        for(int i=0;i<paragraph.size();i++){
            if(isalnum(paragraph[i])){
                word+=tolower(paragraph[i]);
            }
            else{
                if(!word.empty()&&s.count(word)==0){
                    mpp[word]++;
                }
                word="";
            }
        }
         if(!word.empty() && s.count(word) == 0) {
            mpp[word]++;
        }
        int maxi=0;
        string ans;
        for(auto&it:mpp){
            string word=it.first;
            int freq=it.second;
            if(freq>maxi){
                maxi=freq;
                ans=word;
            }
        }
        return ans;
    }
};