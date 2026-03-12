class Solution {
public:
    string minWindow(string s, string t) {
        int left=0;
        int minWindow[2]={0,INT_MAX};
        int target=t.size();
        unordered_map<int,int>mpp;
        for(char c:t){
            mpp[c]++;
        }
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
                if(minWindow[1]-minWindow[0]>right-left){
                    minWindow[1]=right;
                    minWindow[0]=left;
                }
                mpp[s[left]]++;
                left++;
                target++;
            }
        }
        return minWindow[1]>s.size()?"":s.substr(minWindow[0],minWindow[1]-minWindow[0]+1);
    }
};