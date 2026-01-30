class Solution {
public:
    string expand(int left, int right, string s){
        while(left>=0&&right<s.size()&&s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }
    string longestPalindrome(string s) {
        string maxSub="";
        for(int i=0;i<s.size();i++){
            string oddSub=expand(i,i,s);
            string evenSub=expand(i,i+1,s);
            if(oddSub.length()>maxSub.length())maxSub=oddSub;
            if(evenSub.length()>maxSub.length())maxSub=evenSub;
        }
        return maxSub;
        
    }
};