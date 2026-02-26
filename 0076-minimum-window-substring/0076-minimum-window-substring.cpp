class Solution {
public:
    string minWindow(string s, string t) {
        int left=0;
        int target=t.size();
        unordered_map<char,int>mpp;
        for(char c:t){
            mpp[c]++;
        }
        int minWindow[2]={0,INT_MAX};
        for(int right=0;right<s.size();right++){
            if(mpp.find(s[right])!=mpp.end() && mpp[s[right]]>0){
                target--;
            }
            mpp[s[right]]--;
            if(target==0){
                while(true){
                    char c=s[left];
                    if(mpp.find(c)!=mpp.end() && mpp[c]==0){
                        break;
                    }
                    mpp[c]++;
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