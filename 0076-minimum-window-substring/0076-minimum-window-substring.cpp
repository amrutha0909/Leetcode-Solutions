class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int,int>mpp;
        for(char c:t){
            mpp[c]++;
        }
        int target=t.size();
        int left=0;
        vector<int>minWindow={0,INT_MAX};
        for(int right=0;right<s.size();right++){
            if(mpp.find(s[right])!=mpp.end() && mpp[s[right]]>0){
                target--;
            }
            mpp[s[right]]--;
            if(target==0){
                while(true){
                    if(mpp.find(s[left])!=mpp.end()&&mpp[s[left]]==0){
                        break;
                    }
                    mpp[s[left]]++;
                    left++;
                }
                if(right-left<minWindow[1]-minWindow[0]){
                    minWindow[0]=left;
                    minWindow[1]=right;
                }
                mpp[s[left]]++;
                left++;
                target++;
            } 
        }
        if(minWindow[1]>s.size())return "";
        return s.substr(minWindow[0],minWindow[1]-minWindow[0]+1);
    }
};