class Solution {
public:
    bool isValid(int index,int len,string s){
        if(len>3)return false;
        if(index+len>s.size())return false;
        if(len>1 && s[index]=='0')return false;
        string sub=s.substr(index,len);
        return stoi(sub)<=255;
    }
    void backtrack(int index,int parts,string curr,string s,vector<string>&res){
        if(parts==4&&index==s.size()){
            curr.pop_back();
            res.push_back(curr);
            return;
        }
        if(parts>=4)return;
        for(int len=1;len<=3;len++){
            string segment=s.substr(index,len);
            if(isValid(index,len,s)){
                backtrack(index+len,parts+1,curr+segment+".",s,res);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>res;
        backtrack(0,0,"",s,res);
        return res;
    }
};