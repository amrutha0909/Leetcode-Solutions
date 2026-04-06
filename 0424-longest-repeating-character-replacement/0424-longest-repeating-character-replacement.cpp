class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mpp;
        int left=0;
        int maxLength=0;
        int maxFreq=0;
        for(int right=0;right<s.size();right++){
            mpp[s[right]]++;
            maxFreq=max(maxFreq,mpp[s[right]]);
            while(right-left+1-maxFreq>k){
                mpp[s[left]]--;
                if(mpp[s[left]]==0)mpp.erase(s[left]);
                left++;
            }
            maxLength=max(maxLength,right-left+1);
        }
        return maxLength;
    }
};