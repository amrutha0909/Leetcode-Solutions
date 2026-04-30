class Solution {
public:
    string palindromic(int left,int right,string s){
        int n=s.size();
        while(left>=0 && right<n && s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }
    string longestPalindrome(string s) {
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            string odd=palindromic(i,i,s);
            string even=palindromic(i,i+1,s);
            if(odd.length()>ans.length())ans=odd;
            if(even.length()>ans.length())ans=even;
        }
        return ans;
    }
};