class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int maxLen=0;
        unordered_map<int,int>mpp;
        for(int right=0;right<s.size();right++){
            char c=s[right];
            mpp[c]++;
            while(mpp[c]>1){
                mpp[s[left]]--;
                if(mpp[s[left]]==0)mpp.erase(s[left]);
                left++;
            }
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};