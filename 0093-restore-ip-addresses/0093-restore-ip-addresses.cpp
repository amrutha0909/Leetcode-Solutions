class Solution {
public:
    bool isValid(string&s,int start, int len){
        if(len>3)return false;
        if(start+len>s.size())return false;
        if(len>1 && s[start]=='0')return false;
        int num=stoi(s.substr(start,len));
        return num<=255;
    }
    void backtrack(string&s,int index,int parts,string current,vector<string>&result){
        if(parts==4 && index==s.size()){
            current.pop_back();
            result.push_back(current);
            return;
        }
        if(parts>=4)return;
        for(int len=1;len<=3;len++){
            if(isValid(s,index,len)){
                string segment=s.substr(index,len);
                backtrack(s,index+len,parts+1,current+segment+".",result);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>result;
        string current="";
        backtrack(s,0,0,current,result);
        return result;

    }
};