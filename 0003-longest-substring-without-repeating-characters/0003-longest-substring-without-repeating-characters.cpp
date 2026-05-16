class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mpp;
        int left=0;
        int maxLen=0;
        for(int right=0;right<s.size();right++){
            mpp[s[right]]++;
            while(mpp[s[right]]>1){
                mpp[s[left]]--;
                if(mpp[s[left]]==0)mpp.erase(s[left]);
                left++;
            }
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};