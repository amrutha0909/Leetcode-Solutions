class Solution {
public:
    bool isValid(int index, int len, string s){
        if(len>3)return false;
        if(index+len>s.size())return false;
        if(len>1&&s[index]=='0')return false;
        string segment=s.substr(index,len);
        return stoi(segment)<=255;
    }
    void backtrack(int index,int parts,string current,string s,vector<string>&result){
        if(parts==4&&index==s.size()){
            current.pop_back();
            result.push_back(current);
            return;
        }
        if(parts>=4)return;
        for(int len=1;len<=3;len++){
            if(isValid(index,len,s)){
                string segment=s.substr(index,len);
                backtrack(index+len,parts+1,current+segment+".",s,result);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>result;
        backtrack(0,0,"",s,result);
        return result;
    }
};