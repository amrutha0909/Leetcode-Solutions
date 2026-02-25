class Solution {
public:
    string reverseWords(string s) {
        string res="";
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                res+=s[i];
            }
            else if(s[i]==' '){
                reverse(res.begin(),res.end());
                ans+=res;
                ans+=' ';
                res="";
            }
            if(i==s.size()-1){
                reverse(res.begin(),res.end());
                ans+=res;
                res="";
            }
        }
        return ans;
    }
};