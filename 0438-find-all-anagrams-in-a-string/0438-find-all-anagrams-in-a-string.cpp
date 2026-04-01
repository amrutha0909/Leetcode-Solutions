class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>p_mpp;
        unordered_map<char,int>s_mpp;
        vector<int>ans;
        for(char c:p)p_mpp[c]++;
        int win=p.size();
        int l=0;
        for(int r=0;r<s.size();r++){
            s_mpp[s[r]]++;
            if(r-l+1>win){
                s_mpp[s[l]]--;
                if(s_mpp[s[l]]==0)s_mpp.erase(s[l]);
                l++;
            }
            if(r-l+1==win && s_mpp==p_mpp)ans.push_back(l);
        }
        return ans;
    }
};