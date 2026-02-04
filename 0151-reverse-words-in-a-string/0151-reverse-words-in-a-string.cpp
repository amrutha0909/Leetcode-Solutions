class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int l=0;
        int r=n-1;
        while(l<r&&s[l]==' '){
            l++;
        }
        while(l<r&&s[r]==' '){
            r--;
        }
        string ans="";
        string rev="";
        for(int i=r;i>=l;i--){
            if(s[i]!=' '){
                rev+=s[i];
            }
            else{
                if(rev=="")continue;
                reverse(rev.begin(),rev.end());
                ans+=rev;
                ans+=' ';
                rev="";
            }
            if(i==l){
                reverse(rev.begin(),rev.end());
                ans+=rev;
                rev="";
            }
        }
        return ans;
    }
};