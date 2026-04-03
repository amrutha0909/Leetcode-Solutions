class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mpp;
        for(string word:words)mpp[word]++;
        vector<vector<string>> bucket(words.size() + 1);
        for(auto&it:mpp){
            bucket[it.second].push_back(it.first);
        }
        vector<string>ans;
        int i=bucket.size()-1;
        for(int i = bucket.size() - 1; i >= 0 && k > 0; i--){
            sort(bucket[i].begin(),bucket[i].end());
            for(string &word : bucket[i]){
                ans.push_back(word);
                k--;
                if(k == 0) break;
            }
        }
        return ans;
    }
};