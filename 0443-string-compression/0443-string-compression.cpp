class Solution {
public:
    int compress(vector<char>& chars) {
        string word="";
        word+=chars[0];
        string ans="";
        for(int i=1;i<chars.size();i++){
            if(chars[i]==chars[i-1]){
                word+=chars[i];
            }
            else{
                ans+=word.back();
                if(word.size()>1)ans+=to_string(word.size());
                word="";
                word+=chars[i];
            }
        }
        ans+=word.back();
        ans+=word.size()>1?to_string(word.size()):"";
        for(int i=0;i<ans.size();i++){
            chars[i]=ans[i];
        }
        return ans.size();
    }
};