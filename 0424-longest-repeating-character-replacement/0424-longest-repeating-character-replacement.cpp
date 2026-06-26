class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mpp;
        int left=0;
        int freq=0;
        int maxFreq=0;
        int ans=0;
        for(int right=0;right<s.size();right++){
            mpp[s[right]]++;
            freq=mpp[s[right]];
            maxFreq=max(maxFreq,freq);
            while(right-left+1-maxFreq>k){
                mpp[s[left]]--;
                if(mpp[s[left]]==0)mpp.erase(s[left]);
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};