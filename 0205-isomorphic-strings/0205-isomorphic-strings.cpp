class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m)return false;
        unordered_map<char,int>mpp1;
        unordered_map<char,int>mpp2;
        for(int i=0;i<n;i++){
            char c1=s[i];
            char c2=t[i];
            if(mpp1.count(c1) && mpp1[c1]!=c2)return false;
            if(mpp2.count(c2) && mpp2[c2]!=c1)return false;
            mpp1[c1]=c2;
            mpp2[c2]=c1;
        }
        return true;
    }
};