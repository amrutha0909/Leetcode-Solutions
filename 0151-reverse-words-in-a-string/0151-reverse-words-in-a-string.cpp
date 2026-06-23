class Solution {
public:
    string reverseWords(string s) {
        int left=0;
        int right=s.size()-1;
        while(left<=right && s[right]==' '){
            right--;
        }
        while(left<=right && s[left]==' '){
            left++;
        }
        string word="";
        string ans="";
        for(int i=right;i>=left;i--){
            if(s[i]!=' ')word+=s[i];
            else if(s[i]==' '&&i!=0&& !word.empty()){
                reverse(word.begin(),word.end());
                ans+=word;
                ans+=' ';
                word="";
            }
            // else if(i==0&&!word.empty()){
            //     reverse(word.begin(),word.end());
            //     ans+=word;
            //     word="";
            // }
        }
        if(!word.empty()){
            reverse(word.begin(),word.end());
            ans+=word;
        }
        return ans;
    }
};