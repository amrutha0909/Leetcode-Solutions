class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        vector<int>hash(256,-1);
        int maxLen=0;
        for(int right=0;right<s.size();right++){
            if(hash[s[right]]!=-1){
                left=max(left,hash[s[right]]+1);
            }
            hash[s[right]]=right;
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};