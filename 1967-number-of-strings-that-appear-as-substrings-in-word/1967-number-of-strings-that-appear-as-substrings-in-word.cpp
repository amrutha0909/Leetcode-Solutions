class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count=0;
        for(string s:patterns){
            if(word.find(s)<word.size())count++;
        }
        return count;
    }
};