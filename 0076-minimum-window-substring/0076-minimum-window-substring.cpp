class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size())return "";
        unordered_map<char,int>mpp;
        for(char c:t){
            mpp[c]++;
        }
        int target=t.size();
        int left=0;
        int minWindow[2]={0,INT_MAX};
        for(int right=0;right<s.size();right++){
            char c=s[right];
            if(mpp.find(c)!=mpp.end()&&mpp[c]>0){
                target--;
            }
            mpp[c]--;
            if(target==0){
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
                target++;
                left++;
            }
        }
        return minWindow[1]>s.size()?"":s.substr(minWindow[0],minWindow[1]-minWindow[0]+1);
    }
};