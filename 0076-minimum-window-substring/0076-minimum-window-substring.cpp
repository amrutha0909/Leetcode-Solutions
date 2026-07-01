class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>window{0,INT_MAX};
        int left=0;
        unordered_map<int,int>mpp;
        for(char c:t)mpp[c]++;
        int target=t.size();
        for(int right=0;right<s.size();right++){
            if(mpp.find(s[right])!=mpp.end() && mpp[s[right]]>0){
                target--;
            }
            mpp[s[right]]--;
            if(target==0){
                while(true){
                    if(mpp.find(s[left])!=mpp.end() && mpp[s[left]]==0){
                        break;
                    }
                    mpp[s[left]]++;
                    left++;
                }
                if(right-left<window[1]-window[0]){
                    window[1]=right;
                    window[0]=left;
                }
                mpp[s[left]]++;
                left++;
                target++;
            }
        }
        if(window[1]>s.size())return "";
        return s.substr(window[0],window[1]-window[0]+1);
    }
};