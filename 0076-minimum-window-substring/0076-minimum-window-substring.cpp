class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size())return "";
        unordered_map<char,int>mpp;
        for(char c:t){
            mpp[c]++;
        }
        int targetRem=t.size();
        int minWindow[2]={0,INT_MAX};
        int left=0;
        for(int right=0;right<s.size();right++){
            char c=s[right];
            if(mpp.find(c)!=mpp.end()&&mpp[c]>0){
                targetRem--;
            }
            mpp[c]--;
            if(targetRem==0){
                while(true){
                    char charStart=s[left];
                    if(mpp.find(charStart)!=mpp.end()&&mpp[charStart]==0){
                        break;
                    }
                    mpp[charStart]++;
                    left++;
                }
                if(right-left<minWindow[1]-minWindow[0]){
                    minWindow[0]=left;
                    minWindow[1]=right;
                }
                mpp[s[left]]++;
                targetRem++;
                left++;
            }

        }
        return minWindow[1]>=s.size()?"":s.substr(minWindow[0],minWindow[1]-minWindow[0]+1);
    }
};